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

namespace game_framework {
	Map::Map()
	{
		for (int row = 0; row < 5; row++)
		{
			plants.push_back(vector<Plant*>());
			for (int col = 0; col < 9; col++) {
				plants[row].push_back(nullptr);
			}
		}

		// temp code
		NormalZombie *nz = new NormalZombie();
		nz->onInit();
		zombies.push_back(nz);
	}

	Map::~Map()
	{
		for (unsigned int i = 0; i < displayedSuns.size(); i++)
		{
			delete displayedSuns.at(i);
		}
	}

	void Map::init()
	{
		isDay = true;
		background.init(MAP_BG_DAY);
		bar.init(50);

		// Sun is obtained from [...] and falls from the sky approximately every 10 seconds when it is daytime. -> https://plantsvszombies.fandom.com/wiki/Sun
		sunProductionCooldown.setCooldown(10);
	}

	void Map::show()
	{
		background.show();
		bar.show();

		if (bar.hasGameStarted())
		{
			for (Zombie* zombie : zombies) {
				zombie->onShow();
			}

			for (vector<Plant*> row : plants) {
				for (Plant* plant : row) {
					if (plant != nullptr) plant->onShow();
				}
			}

			for (Bullet* bullet : bullets) {
				bullet->onShow();
			}

			for (Sun* sun : displayedSuns) {
				sun->show();
			}

			if (currentSelectPlant != nullptr) {
				currentSelectPlant->onShow();
			}
		}
	}

	void Map::OnHover(CPoint coords)
	{
		if (bar.hasGameStarted())
		{
			if (currentSelectPlant != nullptr)
			{
				currentSelectPlant->SetTopLeft(coords);
			}
		}
	}

	void Map::OnMove()
	{
		// On Move is performed aprox 30 times per second.

		Cooldown::updateGameClock(); // update the universal clock the game uses to check all cooldowns.

		if (bar.hasGameStarted())
		{
			sunFactoryLogic();
			bar.move();
			collisionDetection(&zombies);

			for (vector<Plant*> row : plants) {
				for (Plant* plant : row) {
					if (plant != nullptr) 
					{
						if (plant->getType() == PLANT_TYPE::GENERATE_SUN) plant->onMove(&displayedSuns);
						else if (plant->getType() == PLANT_TYPE::SHOOTING) plant->onMove(&bullets, &zombies);
						else plant->onMove();

						if (plant->isDead())
						{
							plants[plant->row()][plant->col()] = nullptr;
							delete plant;
						}
					}
				}
			}

			for (Zombie* zombie : zombies)
			{
				zombie->onMove(&plants);
				if (zombie->isDead() && zombie->isDeadDone())
				{
					zombies.erase(remove(zombies.begin(), zombies.end(), zombie), zombies.end());
					delete zombie;
				}
			}

			for (Bullet* bullet : bullets)
			{
				bullet->onMove();
				if (bullet->detectCollison(&zombies) || bullet->GetLeft() > 900)
				{
					bullets.erase(remove(bullets.begin(), bullets.end(), bullet), bullets.end());
					delete bullet;
				}
			}
		}
	}

	int Map::OnClick(CPoint coords)
	{
		CreatePlantOnClick(coords);

		if (bar.hasGameStarted())
		{
			AddSunOnClick(coords);
		}

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
		case SEED_CARD_TYPE::POTATO_MINE:
			if (bar.getSuns() >= PotatoMine::price)
				currentSelectPlant = new PotatoMine(coords);
			break;
		case SEED_CARD_TYPE::PUFF_SHROOM:
			if (bar.getSuns() >= PuffShroom::price)
				currentSelectPlant = new PuffShroom(coords);
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
		case SEED_CARD_TYPE::REFUSED:
			if (currentSelectPlant == nullptr
				|| pos.x == -1 || pos.y == -1
				|| plants[pos.y][pos.x] != nullptr)
			{
				break;
			}

			currentSelectPlant->PlaceDown(pos.y, pos.x);
			plants[pos.y][pos.x] = currentSelectPlant;

			bar.addSuns(-1 * currentSelectPlant->getPrice());
			bar.setSeedCardCooldown(currentSelectedSeedCard);
			currentSelectPlant = nullptr;

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

	bool Map::getIsDay()
	{
		return isDay;
	}
	void Map::sunFactoryLogic()
	{
		sunProductionCooldown.updateCooldown();

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
}