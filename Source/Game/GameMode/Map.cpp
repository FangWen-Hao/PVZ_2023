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
		menu.Show();

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
		menu.onHover(coords);

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

		if (menu.getGameIsPaused())
		{
			return;
		}

		Cooldown::updateGameClock(); // update the universal clock the game uses to check all cooldowns.
		
		if (bar.hasGameStarted())
		{
			sunFactoryLogic();

			for (Plant* plant : plants) {
				if (plant->getType() == PLANT::SUN_FLOWER) plant->onMove(&displayedSuns, &zombies);
				else plant->onMove(&bullets, &zombies);
				
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
		int returnCode = menu.onClick(coords, THIS_LEVEL_CODE);

		if (returnCode != MENU_NO_BTN_ACTION_ACCEPTED && returnCode != MENU_NO_BTN_ACTION_REJECTED
			&& returnCode == MENU_BTN) // last one is temporary as we only have this level implemented for now...
		{
			return returnCode;
		}

		SEED_CARD card = bar.onClick(coords);

		if (bar.hasGameStarted())
		{
			if (displayedSuns.size() != 0)
				for (unsigned int i = 0; i < displayedSuns.size(); i++)
				{
					if (coords.x < (displayedSuns.at(i)->GetLeft() + displayedSuns.at(i)->GetWidth()) && coords.x > displayedSuns.at(i)->GetLeft()
						&& coords.y < (displayedSuns.at(i)->GetTop() + displayedSuns.at(i)->GetHeight()) && coords.y > displayedSuns.at(i)->GetTop())
					{
						bar.addSuns(displayedSuns.at(i)->getValue());
						removeSunFromVector(i);
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
				
				plantsMap[pos.y][pos.x] = currentSelectPlant->getType();
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

		return MENU_NO_BTN_ACTION_ACCEPTED;
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

		if (displayedSuns.size() != 0)
		{
			for (unsigned int i = 0; i < displayedSuns.size(); i++)
			{

				if (displayedSuns.at(i)->update() == Sun_status::INVALID)
				{
					removeSunFromVector(i);
				}
					
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
	void Map::removeSunFromVector(unsigned int index)
	{
		displayedSuns.at(index)->unshow();
		delete displayedSuns.at(index);
		displayedSuns.erase(displayedSuns.begin() + index);
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