#include "stdafx.h"
// #include "../Terrain/Lane.h"
#include "../Background/GameBar.h"
// #include "GameMenu.h"
// #include "ProgressBar.h"
// #include "Lanes.h"
#include "../Utils/GameModeConsts.h"
#include "../Misc/NormalSun.h"
#include "../Utils/GameModeUtils.h"
#include "../Utils/EntitiesUtil.h"
#include "Maps/Tile_Positions.h"
#include "../Plants/Plant.h"
#include "../Zombies/Zombie.h"
#include <algorithm>
#include "../config.h"

namespace game_framework {

	Map::Map(vector<vector<int>> zombiesSpawningInstructions,
		string messageBitmap,
		bool isDay,
		double sunProductionCooldownVal,
		unsigned int maxSunsFallen,
		int startingSunHeight,
		int startingSunsAmmount)

	{
		SetUpGameBoard();

		this->zombiesSpawningInstructions = zombiesSpawningInstructions;
		this->sunProductionCooldownVal = sunProductionCooldownVal;
		this->maxSunsFallen = maxSunsFallen;
		this->startingSunHeight = startingSunHeight;
		this->startingSunsAmmount = startingSunsAmmount;
		this->isDay = isDay;
		endGameMsg.init(messageBitmap);
	}

	void Map::SetUpGameBoard()
	{
		for (int row = 0; row < 5; row++)
		{
			plants.push_back(vector<Plant*>());
			for (int col = 0; col < 9; col++) {
				plants[row].push_back(nullptr);
			}
		}

		for (int row = 0; row < 5; row++)
		{
			lawnmowers.push_back(new Lawnmower());
		}
	}

	Map::~Map()
	{
		DeleteEntities();
	}

	void Map::DeleteEntities()
	{
		for (Sun* sun : displayedSuns)
		{
			deleteObjInVector(&displayedSuns, sun);
		}

		for (Zombie* zomb : zombies)
		{
			deleteObjInVector(&zombies, zomb);
		}

		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 9; col++) {
				if (plants.at(row).at(col) != nullptr)
				{
					delete plants.at(row).at(col);
				}
			}

			if (lawnmowers.at(row) != nullptr)
			{
				delete lawnmowers.at(row);
			}
		}

		// delete vector bullets
		for (Bullet* bullet : bullets)
		{
			deleteObjInVector(&bullets, bullet);
		}
	}

	void Map::init()
	{
		InitUI();

		// Sun is obtained from [...] and falls from the sky approximately every 10 seconds when it is daytime. -> https://plantsvszombies.fandom.com/wiki/Sun
		InitGameBoard();
	}

	void Map::InitGameBoard()
	{
		sunProductionCooldown.initCooldown(sunProductionCooldownVal);


		for (int row = 0; row < 5; row++)
		{
			lawnmowers.at(row)->init(row);
		}

		note.LoadBitmapByString({ NOTE_BITMAP } /*TODO:, color*/);
		note.SetTopLeft(RESOLUTION_X + 10, RESOLUTION_Y + 10);
	}

	void Map::InitUI()
	{
		if (isDay) background.init(MAP_BG_DAY);
		else background.init(MAP_BG_NIGHT);

		bar.init(startingSunsAmmount);
		shovelCursor.LoadBitmapByString({ SHOVEL_CURSOR_BITMAP }, RGB(255, 255, 255));
		progress.init(countTotalZombies());
		menu.init(getPreviousLevel(), getCurrentLevel(), getNextLevel());
		gameOver.init();
	}

	void Map::show()
	{
		background.show();
		ShowEntities();
		ShowUI();
		gameOver.show();

		if (noteWasClicked)
		{
			endGameMsg.ShowBitmap();
		}

	}

	void Map::ShowEntities()
	{

		for (vector<Plant*> row : plants) {
			for (Plant* plant : row) {
				if (plant != nullptr) plant->onShow();
			}
		}

		for (Sun* sun : displayedSuns) {
			if (!findObjInVector(displayedSuns, sun)) continue;
			sun->show();
		}

		for (Zombie* zombie : zombies) {
			if (!findObjInVector(zombies, zombie)) continue;
			zombie->onShow();
		}

		for (Bullet* bullet : bullets) {
			if (!findObjInVector(bullets, bullet)) continue;
			bullet->onShow();
		}

		for (Lawnmower* lawnmower : lawnmowers)
		{
			if (lawnmower != nullptr)
			{
				lawnmower->show();
			}
		}
		note.ShowBitmap();
	}

	void Map::ShowUI()
	{
		bar.show();
		menu.show();
		if (bar.hasGameStarted())
		{
			int currentLevel = getCurrentLevel() - LEVEL_1 + 1;
			progress.show(currentLevel);

			if (currentSelectPlant != nullptr) {
				currentSelectPlant->onShow();
			}

			if (currentSelectedSeedCard == SEED_CARD_TYPE::SHOVEL)
			{
				shovelCursor.ShowBitmap();
			}
			else
			{
				shovelCursor.UnshowBitmap();
			}
		}
	}

	void Map::OnHover(CPoint coords)
	{
		if (bar.hasGameStarted())
		{
			OnHoverCursor(coords);
		}

		menu.onHover(coords);
	}

	void Map::OnHoverCursor(CPoint &coords)
	{
		if (currentSelectPlant != nullptr)
		{
			currentSelectPlant->SetTopLeft(coords);
		}

		if (currentSelectedSeedCard == SEED_CARD_TYPE::SHOVEL)
		{
			shovelCursor.SetTopLeft(coords.x, coords.y);
		}
	}

	void Map::OnMove()
	{
		// On Move is performed aprox 30 times per second.
		Cooldown::updateGameClock(); // update the universal clock the game uses to check all cooldowns.

		if (menu.getIsGamePaused())
		{
			// note that we need to have a counter for the time while the menu was open so the zombies dont just magically appear all at once.
			return;
		}

		if (bar.hasGameStarted())
		{
			if (isDay) sunFactoryLogic();

			bar.move();

			CreateZombieOnInstruction();
			collisionDetection(&zombies);
			UpdatePlantsState();
			UpdateZombiesState();
			UpdateBulletsState();
			UpdateLawnmowers();
		}
	}

	void Map::OnKeyUp(UINT nChar)
	{
		const char KEY_D = 0x44;
		const char KEY_L = 0x4C;
		const char KEY_S = 0x53;
		const char KEY_Z = 0x5A;

		switch (nChar)
		{
		case KEY_D:
			for (Zombie* zombie : zombies)
				zombie->setHp(0);
			break;
		case KEY_L:
			// TODO : jump to next level
			break;
		case KEY_S:
			bar.addSuns(500);
			break;
		case KEY_Z:
			// TODO : add zombies moving speed
			break;
		default:
			break;
		}
	}

	void Map::CreateZombieOnInstruction()
	{
		Zombie* zomb = zombieFactory();
		if (zomb != nullptr)
		{
			zombies.push_back(zomb);
		}
	}

	void Map::collisionDetection(vector<Zombie*>* zombies)
	{
		for (Zombie* zombie : *zombies)
		{
			if (zombie->col() != -1 && plants[zombie->row()][zombie->col()] != nullptr)
			{
				zombie->setIsAttacking(true);
			}
			else
			{
				zombie->setIsAttacking(false);
			}
		}
	}

	void Map::UpdatePlantsState()
	{
		for (vector<Plant*> row : plants) {
			for (Plant* plant : row) {
				if (plant == nullptr) continue;

				plant->onMove(&bullets, &displayedSuns, &zombies);

				if (plant->isDead())
				{
					plants[plant->row()][plant->col()] = nullptr;
					delete plant;
				}
			}
		}
	}

	void Map::UpdateZombiesState()
	{
		for (Zombie* zombie : zombies)
		{
			if ((!findObjInVector(zombies, zombie)) || zombie == nullptr) continue;

			zombie->onMove(&plants);

			if (lawnmowers.at(zombie->row()) != nullptr
				&& zombie->left() <= lawnmowers.at(zombie->row())->getRight()
				&& !zombie->isDead())
			{
				if (!lawnmowers.at(zombie->row())->isActive())
				{
					lawnmowers.at(zombie->row())->activate();
				}
				else
				{
					zombie->setHp(0);
				}
			}
			else if (lawnmowers.at(zombie->row()) == nullptr
				&& zombie->left() <= LEFT_TILES_POSITION_ON_MAP.at(0)
				&& !zombie->isDead())
			{
				gameOver.triggerGameOver();
			}

			if (zombie->isDead())
			{
				if (progress.getRemainingZombies() == 1)
				{
					note.SetTopLeft(zombie->left(), zombie->top());
				}

				if (zombie->isDeadDone())
				{
					deleteObjInVector(&zombies, zombie);
					progress.updateCount();
				}
			}
		}
	}

	void Map::UpdateBulletsState()
	{
		for (Bullet* bullet : bullets)
		{
			if ((!findObjInVector(bullets, bullet)) || bullet == nullptr) continue;

			bullet->onMove();
			if (bullet->detectCollison(&zombies) || bullet->isOutOfRange())
			{
				deleteObjInVector(&bullets, bullet);
			}
		}
	}

	void Map::UpdateLawnmowers()
	{
		for (int row = 0; row < 5; row++)
		{
			if (lawnmowers.at(row) == nullptr)
			{
				continue;
			}

			if (lawnmowers.at(row)->isActive())
			{
				lawnmowers.at(row)->move();
			}

			if (lawnmowers.at(row)->isDone())
			{
				delete lawnmowers.at(row);
				lawnmowers.at(row) = nullptr;
			}
		}
	}

	int Map::OnLClick(CPoint coords)
	{
		// if the game was lost or won, then don't allow the user to access the menu.
		if (noteWasClicked)
		{
			return getNextLevel();
		}

		if (gameOver.getIsGameOver())
		{
			return gameOver.onClick(getCurrentLevel());
		}

		// if the menu is open, then don't allow the user to click anything else.
		if (menu.getIsGamePaused())
		{
			return menu.onClick(coords);
		}


		menu.onClick(coords);

		// allow the user to click the menu if the game is over but the user hasn't picked up the note.
		if (progress.isGameComplete())
		{
			if (coords.x < (note.GetLeft() + note.GetWidth()) && coords.x > note.GetLeft()
				&& coords.y < (note.GetTop() + note.GetHeight()) && coords.y > note.GetTop())
			{
				noteWasClicked = true;
				return MENU_NO_BTN_ACTION_ACCEPTED;
			}
			return MENU_NO_BTN_ACTION_ACCEPTED;
		}

		// otherwise, if the game is in progress then the user can click anything.
		if (!bar.hasGameStarted())
		{
			bar.onClick(coords);
			return MENU_NO_BTN_ACTION_ACCEPTED;
		}

		if (bar.hasGameStarted())
		{
			AddSunOnClick(coords);
			CreatePlantOnClick(coords);
		}

		return MENU_NO_BTN_ACTION_ACCEPTED;
	}

	int Map::OnRClick(CPoint coords)
	{
		if (!bar.hasGameStarted()) return 0;
		if (currentSelectPlant == nullptr) return 0;
		delete currentSelectPlant;
		currentSelectPlant = nullptr;

		return 0;
	}

	void Map::CreatePlantOnClick(const CPoint &coords)
	{
		SEED_CARD_TYPE card = bar.onClick(coords);
		CPoint pos = _mousePos2TilePos(coords);
		switch (card)
		{
		case SEED_CARD_TYPE::CHERRY_BOMB:
			if (bar.getSuns() >= CherryBomb::price)
				currentSelectPlant = new CherryBomb(coords, isDay);
			break;
		case SEED_CARD_TYPE::PEA_SHOOTER:
			if (bar.getSuns() >= PeaShooter::price)
				currentSelectPlant = new PeaShooter(coords, isDay);
			break;
		case SEED_CARD_TYPE::REPEATER_PEA:
			if (bar.getSuns() >= RepeaterPea::price)
				currentSelectPlant = new RepeaterPea(coords, isDay);
			break;
		case SEED_CARD_TYPE::THREE_PEATER:
			if (bar.getSuns() >= Threepeater::price)
				currentSelectPlant = new Threepeater(coords, isDay);
			break;
		case SEED_CARD_TYPE::POTATO_MINE:
			if (bar.getSuns() >= PotatoMine::price)
				currentSelectPlant = new PotatoMine(coords, isDay);
			break;
		case SEED_CARD_TYPE::PUFF_SHROOM:
			if (bar.getSuns() >= PuffShroom::price)
				currentSelectPlant = new PuffShroom(coords, isDay);
			break;
		case SEED_CARD_TYPE::SCAREDY_SHROOM:
			if (bar.getSuns() >= ScaredyShroom::price)
				currentSelectPlant = new ScaredyShroom(coords, isDay);
			break;
		case SEED_CARD_TYPE::SNOW_PEA:
			if (bar.getSuns() >= SnowPea::price)
				currentSelectPlant = new SnowPea(coords, isDay);
			break;
		case SEED_CARD_TYPE::SQUASH:
			if (bar.getSuns() >= Squash::price)
				currentSelectPlant = new Squash(coords, isDay);
			break;
		case SEED_CARD_TYPE::SUN_FLOWER:
			if (bar.getSuns() >= SunFlower::price)
				currentSelectPlant = new SunFlower(coords, isDay);
			break;
		case SEED_CARD_TYPE::WALL_NUT:
			if (bar.getSuns() >= WallNut::price)
				currentSelectPlant = new WallNut(coords, isDay);
			break;
		case SEED_CARD_TYPE::JALAPENO:
			if (bar.getSuns() >= Jalapeno::price)
				currentSelectPlant = new Jalapeno(coords, isDay);
			break;
		case SEED_CARD_TYPE::ICE_SHROOM:
			if (bar.getSuns() >= IceShroom::price)
				currentSelectPlant = new IceShroom(coords, isDay);
			break;
		case SEED_CARD_TYPE::HYPNO_SHROOM:
			if (bar.getSuns() >= HypnoShroom::price)
				currentSelectPlant = new HypnoShroom(coords, isDay);
			break;
		case SEED_CARD_TYPE::SHOVEL:
			shovelCursor.SetTopLeft(coords.x, coords.y);

			if (currentSelectPlant != nullptr)
			{
				delete currentSelectPlant;
				currentSelectPlant = nullptr;
			}

			break;
		case SEED_CARD_TYPE::REFUSED:
			if (currentSelectedSeedCard == SEED_CARD_TYPE::REFUSED)
			{
				break;
			}

			// if the click was registered outside of the board bounderies
			// or the user tried to plant on an occupied tile
			// or the user tried to remove a plant from an empty tile
			// breaks
			if ((currentSelectPlant == nullptr
				&& currentSelectedSeedCard != SEED_CARD_TYPE::SHOVEL)
				|| pos.x == -1
				|| pos.y == -1
				|| (plants[pos.y][pos.x] != nullptr
					&& currentSelectedSeedCard != SEED_CARD_TYPE::SHOVEL)
				|| (plants[pos.y][pos.x] == nullptr
					&& currentSelectedSeedCard == SEED_CARD_TYPE::SHOVEL))
			{
				// cancel planting
				if (currentSelectPlant != nullptr)
				{
					delete currentSelectPlant;
					currentSelectPlant = nullptr;
				}

				break;
			}

			if (plants[pos.y][pos.x] != nullptr
				&& currentSelectedSeedCard == SEED_CARD_TYPE::SHOVEL)
			{
				// unplant plant
				delete plants[pos.y][pos.x];
				plants[pos.y][pos.x] = nullptr;
			}

			if (plants[pos.y][pos.x] == nullptr
				&& currentSelectedSeedCard != SEED_CARD_TYPE::SHOVEL)
			{
				// plant plant
				currentSelectPlant->PlaceDown(pos.y, pos.x);
				plants[pos.y][pos.x] = currentSelectPlant;

				bar.addSuns(-1 * currentSelectPlant->price());
				bar.setSeedCardCooldown(currentSelectedSeedCard);
				currentSelectPlant = nullptr;
			}

		default: break;
		}

		currentSelectedSeedCard = card;
	}

	void Map::AddSunOnClick(CPoint &coords)
	{
		for (Sun* sun : displayedSuns)
		{
			if (findObjInVector(displayedSuns, sun)
				&& coords.x < (sun->GetLeft() + sun->GetWidth()) && coords.x > sun->GetLeft()
				&& coords.y < (sun->GetTop() + sun->GetHeight()) && coords.y > sun->GetTop())
			{
				bar.addSuns(sun->getValue());
				deleteObjInVector(&displayedSuns, sun);
				break;
			}
		}
	}

	void Map::setIsDay(bool val)
	{
		isDay = val;

		if (isDay)
		{
			background.init(MAP_BG_DAY);
			background.show();
		}

		else
		{
			background.init(MAP_BG_NIGHT);
			background.show();
		}
	}

	void Map::sunFactoryLogic()
	{
		if (!isDay)
		{
			return;
		}

		for (Sun* sun : displayedSuns)
		{
			if (findObjInVector(displayedSuns, sun)
				&& sun->update() == Sun_status::INVALID)
			{
				deleteObjInVector(&displayedSuns, sun);
			}
		}

		if (!sunProductionCooldown.isOnCooldown()
			&& displayedSuns.size() <= maxSunsFallen)
		{
			displayedSuns.push_back(new NormalSun());
			displayedSuns.back()->init(MIDDLE_TILES_POSITION_ON_MAP.at(integerPRNG(0, 8)),
				startingSunHeight,
				MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(integerPRNG(0, 4)));

			sunProductionCooldown.startCooldown();
		}
	}

	CPoint Map::_mousePos2TilePos(CPoint coords)
	{
		CPoint res = CPoint(-1, -1);

		// search the Y-axis
		for (int i = 0; i < 5; ++i)
		{
			if (coords.y >= TOP_LANE_POSITION_ON_SCREEN_MAP.at(i) &&
				coords.y <= BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(i))
			{
				res.y = i;
				break;
			}
		}

		// search the X-axis
		for (int i = 0; i < 9; ++i)
		{
			if (coords.x >= LEFT_TILES_POSITION_ON_MAP.at(i) &&
				coords.x <= RIGHT_TILES_POSITION_ON_MAP.at(i))
			{
				res.x = i;
				break;
			}
		}

		return res;
	}

	Zombie* Map::zombieFactory()
	{
		Zombie* zombie;
		for (unsigned int i = 0; i < zombiesSpawningInstructions.size(); i++)
		{
			if (zombiesSpawningInstructions.at(i).at(3) == 1)
			{
				continue;
			}

			if (duration_cast<duration<double>>(Cooldown::getGameClock() - bar.getGameStartedTime()).count() >= zombiesSpawningInstructions.at(i).at(1))
			{
				switch ((ZOMBIE_INSTRUCTION_TYPE)zombiesSpawningInstructions.at(i).at(0))
				{
				case ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT:
				case ZOMBIE_INSTRUCTION_TYPE::WAIT:
					// in the case of EMPTY: the game waits until the screen is clear of zombies to spawn any new one
					if (zombies.size() == 0)
					{
						zombiesSpawningInstructions.at(i).at(3) = 1;
					}
					return nullptr;

				case ZOMBIE_INSTRUCTION_TYPE::NORMAL:
					zombie = new NormalZombie();
					break;

				case ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD:
					zombie = new BucketheadZombie();
					break;

				case ZOMBIE_INSTRUCTION_TYPE::CONEHEAD:
					zombie = new ConeheadZombie();
					break;

				case ZOMBIE_INSTRUCTION_TYPE::FLAG:
				 	zombie = new FlagZombie();
				 	break;

				case ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER:
				 	zombie = new NewspaperZombie();
				 	break;

				case ZOMBIE_INSTRUCTION_TYPE::NEWSPAPERNOPAPER:
				 	zombie = new NewpaperZombieNoPaper();
				 	break;

				default:
					continue;
				}

				zombiesSpawningInstructions.at(i).at(3) = 1;
				zombie->onInit(zombiesSpawningInstructions.at(i).at(2));
				return zombie;
			}
		}
		return nullptr;
	}

	int Map::countTotalZombies()
	{
		int total = 0;
		for (unsigned int i = 0; i < zombiesSpawningInstructions.size(); i++)
		{
			switch ((ZOMBIE_INSTRUCTION_TYPE)zombiesSpawningInstructions.at(i).at(0))
			{
			case ZOMBIE_INSTRUCTION_TYPE::NORMAL:
			case ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD:
			case ZOMBIE_INSTRUCTION_TYPE::CONEHEAD:
			case ZOMBIE_INSTRUCTION_TYPE::FLAG:
			case ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER:
			case ZOMBIE_INSTRUCTION_TYPE::NEWSPAPERNOPAPER:
				total++;
				break;

			case ZOMBIE_INSTRUCTION_TYPE::EMPTY:
			default:
				continue;
			}
		}
		return total;
	}
}
