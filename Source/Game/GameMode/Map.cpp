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
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 9; x++) {
				plantsMap[y][x] = PLANT::EMPTY;
			}
		}
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

			for (Plant* plant : plants) {
				plant->onShow();
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

			// TODO: wirte a function for detect objects collision
			collisionDetection(&zombies, &plants);

			for (Plant* plant : plants) {
				if (plant->getType() == PLANT_TYPE::GENERATE_SUN) plant->onMove(&displayedSuns);
				else if (plant->getType() == PLANT_TYPE::SHOOTING) plant->onMove(&bullets);
				else plant->onMove();

				if (plant->isDead())
				{
					delete plant;
					plants.erase(remove(plants.begin(), plants.end(), plant), plants.end());
				}
			}

			for (Zombie* zombie : zombies)
			{
				zombie->onMove();
				if (zombie->isDead() && zombie->isDeadDone())
				{
					delete zombie;
					zombies.erase(remove(zombies.begin(), zombies.end(), zombie), zombies.end());
				}
			}

			for (Bullet* bullet : bullets)
			{
				bullet->onMove();
				if (bullet->detectCollison(&zombies) || bullet->GetLeft() > 900)
				{
					delete bullet;
					bullets.erase(remove(bullets.begin(), bullets.end(), bullet), bullets.end());
				}
			}
		}
	}

	int Map::OnClick(CPoint coords)
	{
		SEED_CARD card = bar.onClick(coords);

		if (bar.hasGameStarted())
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
			
			CPoint pos = _mousePos2TilePos(coords);
			switch (card)
			{
			case SEED_CARD::CHERRY_BOMB:
				if (bar.getSuns() >= CherryBomb::price)
					currentSelectPlant = new CherryBomb(coords);
				break;
			case SEED_CARD::PEA_SHOOTER:
				if (bar.getSuns() >= PeaShooter::price)
					currentSelectPlant = new PeaShooter(coords);
				break;
			case SEED_CARD::POTATO_MINE:
				if (bar.getSuns() >= PotatoMine::price)
					currentSelectPlant = new PotatoMine(coords);
				break;
			case SEED_CARD::PUFF_SHROOM:
				if (bar.getSuns() >= PuffShroom::price)
					currentSelectPlant = new PuffShroom(coords);
				break;
			case SEED_CARD::SNOW_PEA:
				if (bar.getSuns() >= SnowPea::price)
					currentSelectPlant = new SnowPea(coords);
				break;
			case SEED_CARD::SQUASH:
				if (bar.getSuns() >= Squash::price)
					currentSelectPlant = new Squash(coords);
				break;
			case SEED_CARD::SUN_FLOWER:
				if (bar.getSuns() >= SunFlower::price)
					currentSelectPlant = new SunFlower(coords);
				break;
			case SEED_CARD::WALL_NUT:
				if (bar.getSuns() >= WallNut::price)
					currentSelectPlant = new WallNut(coords);
				break;
			case SEED_CARD::REFUSED:
				if (currentSelectPlant == nullptr
					|| pos.x == -1 || pos.y == -1
					|| plantsMap[pos.y][pos.x] != PLANT::EMPTY)
				{
					break;
				}

				plantsMap[pos.y][pos.x] = currentSelectPlant->getName();
				currentSelectPlant->SetTopLeft(
					MIDDLE_TILES_POSITION_ON_MAP.at(pos.x) - currentSelectPlant->width() / 2,
					MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(pos.y) - currentSelectPlant->height() / 2);
				plants.push_back(currentSelectPlant);
				bar.addSuns(-1 * currentSelectPlant->getPrice());
				currentSelectPlant = nullptr;

			default: break;
			}

			// temp code
			NormalZombie *nz = new NormalZombie();
			nz->onInit();
			zombies.push_back(nz);
		}

		return 0;
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

	void Map::collisionDetection(vector<Zombie*>* zombies, vector<Plant*>* plants)
	{
		for (Zombie* zombie : *zombies)
		{
			for (Plant* plant : *plants)
			{
				if (zombie->left() < plant->right() && zombie->right() > plant->left() &&
					zombie->top() < plant->bottom() && zombie->bottom() > plant->top())
				{
					// collision
					zombie->setIsAttacking(true);
					plant->isAttackedBy(zombie);
				}
				else {
					zombie->setIsAttacking(false);
					plant->isNotAttackedBy(zombie);
				}
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