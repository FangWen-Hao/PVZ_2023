#include "stdafx.h"
// #include "../Terrain/Lane.h"
#include "../Background/GameBar.h"
// #include "GameMenu.h"
// #include "ProgressBar.h"
// #include "Lanes.h"
#include "../Misc/NormalSun.h"
#include "GameModeUtils.h"
#include "Maps/Tile_Positions.h"
#include "../Plants/Plant.h"
#include "../Zombies/Zombie.h"
#include <algorithm>
#include "Maps/Zombies_Spawn_Instruction.h"

namespace game_framework {

	Map::Map(vector<vector<int>> zombiesSpawningInstructions)
	{
		SetUpGameBoard();

		// temp code
		// NormalZombie *nz = new NormalZombie();
		// nz->onInit();
		// zombies.push_back(nz);

		this->zombiesSpawningInstructions = zombiesSpawningInstructions;
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
		for (unsigned int i = 0; i < displayedSuns.size(); i++)
		{
			delete displayedSuns.at(i);
		}

		for (unsigned i = 0; i < zombies.size(); i++)
		{
			delete zombies.at(i);
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
	}

	void Map::init()
	{
		isDay = true;
		InitUI();

		// Sun is obtained from [...] and falls from the sky approximately every 10 seconds when it is daytime. -> https://plantsvszombies.fandom.com/wiki/Sun
		InitGameBoard();
	}

	void Map::InitGameBoard()
	{
		sunProductionCooldown.initCooldown(10);


		for (int row = 0; row < 5; row++)
		{
			lawnmowers.at(row)->init(row);
		}
	}

	void Map::InitUI()
	{
		background.init(MAP_BG_DAY);
		bar.init(sunsAmount);
		shovelCursor.LoadBitmapByString({ SHOVEL_CURSOR_BITMAP }, RGB(255, 255, 255));
		menu.init();
		progress.init(countTotalZombies(), 0);
	}

	void Map::show()
	{
		background.show();
		ShowEntities();
		ShowUI();
	}

	void Map::ShowEntities()
	{

		for (vector<Plant*> row : plants) {
			for (Plant* plant : row) {
				if (plant != nullptr) plant->onShow();
			}
		}

		for (Sun* sun : displayedSuns) {
			sun->show();
		}

		for (Zombie* zombie : zombies) {
			zombie->onShow();
		}

		for (Bullet* bullet : bullets) {
			bullet->onShow();
		}

		for (Lawnmower* lawnmower : lawnmowers)
		{
			if (lawnmower != nullptr)
			{
				lawnmower->show();
			}
		}
	}

	void Map::ShowUI()
	{
		bar.show();
		menu.show();
		if (bar.hasGameStarted())
		{
			progress.show();

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
			sunFactoryLogic();
			bar.move();

			CreateZombieOnInstruction();
			collisionDetection(&zombies);
			UpdatePlantsState();
			UpdateZombiesState();
			UpdateBulletsState();
			UpdateLawnmowers();
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
			if (zombie == nullptr) continue;

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

			if (zombie->isDead() && zombie->isDeadDone())
			{
				zombies.erase(remove(zombies.begin(), zombies.end(), zombie), zombies.end());
				delete zombie;
				progress.updateCount();
			}
		}
	}

	void Map::UpdateBulletsState()
	{
		for (Bullet* bullet : bullets)
		{
			if (bullet == nullptr) continue;

			bullet->onMove();
			if (bullet->detectCollison(&zombies) || bullet->isOutOfRange())
			{
				bullets.erase(remove(bullets.begin(), bullets.end(), bullet), bullets.end());
				delete bullet;
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

		if (menu.getIsGamePaused())
		{
			int returnCode = menu.onClick(coords, 0);

			if (returnCode != MENU_NO_BTN_ACTION_REJECTED && returnCode != MENU_NO_BTN_ACTION_ACCEPTED)
				return returnCode;
		}
		else
		{
			menu.onClick(coords, 0);
			if (!bar.hasGameStarted())
			{
				bar.onClick(coords);
				return 0;
			}

			if (bar.hasGameStarted())
			{
				AddSunOnClick(coords);
				CreatePlantOnClick(coords);
			}
		}
		

		return 0;
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
				currentSelectPlant = new CherryBomb(coords);
			break;
		case SEED_CARD_TYPE::PEA_SHOOTER:
			if (bar.getSuns() >= PeaShooter::price)
				currentSelectPlant = new PeaShooter(coords);
			break;
		case SEED_CARD_TYPE::REPEATER_PEA:
			if (bar.getSuns() >= RepeaterPea::price)
				currentSelectPlant = new RepeaterPea(coords);
			break;
		case SEED_CARD_TYPE::THREE_PEATER:
			if (bar.getSuns() >= Threepeater::price)
				currentSelectPlant = new Threepeater(coords);
			break;
		case SEED_CARD_TYPE::POTATO_MINE:
			if (bar.getSuns() >= PotatoMine::price)
				currentSelectPlant = new PotatoMine(coords);
			break;
		case SEED_CARD_TYPE::PUFF_SHROOM:
			if (bar.getSuns() >= PuffShroom::price)
				currentSelectPlant = new PuffShroom(coords);
			break;
		case SEED_CARD_TYPE::SCAREDY_SHROOM:
			if (bar.getSuns() >= ScaredyShroom::price)
				currentSelectPlant = new ScaredyShroom(coords);
			break;
		case SEED_CARD_TYPE::SNOW_PEA:
			if (bar.getSuns() >= SnowPea::price)
				currentSelectPlant = new SnowPea(coords);
			break;
		case SEED_CARD_TYPE::SQUASH:
			if (bar.getSuns() >= Squash::price)
				currentSelectPlant = new Squash(coords);
			break;
		case SEED_CARD_TYPE::SUN_FLOWER:
			if (bar.getSuns() >= SunFlower::price)
				currentSelectPlant = new SunFlower(coords);
			break;
		case SEED_CARD_TYPE::WALL_NUT:
			if (bar.getSuns() >= WallNut::price)
				currentSelectPlant = new WallNut(coords);
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
			if (coords.x < (sun->GetLeft() + sun->GetWidth()) && coords.x > sun->GetLeft()
				&& coords.y < (sun->GetTop() + sun->GetHeight()) && coords.y > sun->GetTop())
			{
				bar.addSuns(sun->getValue());
				removeSunFromVector(sun);
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
			if (sun->update() == Sun_status::INVALID)
			{
				removeSunFromVector(sun);
			}
		}

		if (!sunProductionCooldown.isOnCooldown()
			&& displayedSuns.size() <= MAX_SUNS_FALLEN)
		{
			displayedSuns.push_back(new NormalSun());
			displayedSuns.back()->init(MIDDLE_TILES_POSITION_ON_MAP.at(integerPRNG(0, 8)),
				FALLING_SUN_INITIAL_POSITION,
				MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(integerPRNG(0, 4)));

			sunProductionCooldown.startCooldown();
		}
	}

	void Map::removeSunFromVector(Sun* sun)
	{
		displayedSuns.erase(remove(displayedSuns.begin(), displayedSuns.end(), sun), displayedSuns.end());
		delete sun;
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

				// case ZOMBIE_TYPE::FLAG:
				// 	zombie = new FlagZombie();
				// 	break;

				// case ZOMBIE_TYPE::NEWSPAPER:
				// 	zombie = new NewspaperZombie();
				// 	break;

				// case ZOMBIE_TYPE::NEWSPAPERNOPAPER:
				// 	zombie = new NewpaperZombieNoPaper();
				// 	break;

				default:
					return nullptr;
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