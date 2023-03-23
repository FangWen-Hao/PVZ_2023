#include "stdafx.h"
// #include "../Terrain/Lane.h"
// #include "plants.h"
#include "../Background/GameBar.h"
// #include "GameMenu.h"
// #include "ProgressBar.h"
// #include "Lanes.h"
// #include "Zombies.h"
#include "Map.h"

namespace game_framework {
	Map::Map()
	{
	}

	Map::~Map()
	{
	}

	void Map::init()
	{
		isDay = true;
		background.init(MAP_BG_DAY);
		bar.init(50);
	}

	void Map::show()
	{
		background.show();
		bar.show();
	}

	void Map::OnHover(CPoint coords)
	{
	}

	int Map::OnClick(CPoint coords)
	{
		bar.onClick(coords);
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
