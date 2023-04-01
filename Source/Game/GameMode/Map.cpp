#include "stdafx.h"
// #include "../Terrain/Lane.h"
#include "../Background/GameBar.h"
// #include "GameMenu.h"
// #include "ProgressBar.h"
// #include "Lanes.h"
// #include "Zombies.h"
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
	}

	void Map::init()
	{
		isDay = true;
		background.init(MAP_BG_DAY);
		bar.init(50);
<<<<<<< HEAD
	}

	void Map::move()
	{
		isStarted = bar.isGameStarted();

		if (isStarted)
		{
			for (auto z : zombies) {
				z.onMove();
			}
		}
=======
>>>>>>> parent of d82ec6e (Implemented falling-suns logic)
	}

	void Map::show()
	{
		background.show();
		bar.show();
<<<<<<< HEAD

		if (isStarted)
		{
			for (auto z : zombies) {
				z.onShow();
			}
		}
=======
>>>>>>> parent of d82ec6e (Implemented falling-suns logic)
	}

	void Map::OnHover(CPoint coords)
	{
	}

	int Map::OnClick(CPoint coords)
	{
		bar.onClick(coords);
<<<<<<< HEAD

		if (isStarted)
		{
			// Test zombie
			TestZombie tz = TestZombie();
			tz.onInit();

			zombies.push_back(tz);
		}

=======
>>>>>>> parent of d82ec6e (Implemented falling-suns logic)
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
}
