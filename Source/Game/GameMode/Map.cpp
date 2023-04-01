#include "stdafx.h"
// #include "../Terrain/Lane.h"
#include "../Background/GameBar.h"
// #include "GameMenu.h"
// #include "ProgressBar.h"
// #include "Lanes.h"
// #include "Zombies.h"
#include "../Misc/NormalSun.h"
#include "GameModeUtils.h"
#include "Map.h"
#include "../Plants/Plant.h"

namespace game_framework {
	Map::Map()
	{
		isSelectedPlant = false;
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 9; x++) {
				plantsMap[x][y] = PLANT::EMPTY;
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
			for (auto z : zombies) {
				z->onShow();
			}
		}

		if (displayedSuns.size() != 0)
			for (unsigned int i = 0; i < displayedSuns.size(); i++)
			{
				displayedSuns.at(i)->show();
			}
	}

	void Map::OnHover(CPoint coords)
	{
	}

	void Map::OnMove()
	{
		// On Move is performed aprox 30 times per second.

		Cooldown::updateGameClock(); // update the universal clock the game uses to check all cooldowns.
		
		if (bar.hasGameStarted())
		{
			sunFactoryLogic();

			for (auto z : zombies) {
				z->onMove();
			}
		}
		

	}

	int Map::OnClick(CPoint coords)
	{
		bar.onClick(coords);

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
					}
				}
			
			// temp code
			TestZombie *tz = new TestZombie();
			tz->onInit();
			zombies.push_back(tz);
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
			displayedSuns.at(displayedSuns.size() - 1)
				->init(TILES_POSITION_ON_MAP.at(integerPRNG(0, 8)),
					LANE_POSITION_ON_SCREEN_MAP.at(integerPRNG(0, 4)));

			sunProductionCooldown.startCooldown();
		}
	}
	void Map::removeSunFromVector(unsigned int index)
	{
		displayedSuns.at(index)->unshow();
		delete displayedSuns.at(index);
		displayedSuns.erase(displayedSuns.begin() + index);
	}
}
