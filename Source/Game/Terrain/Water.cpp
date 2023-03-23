#include "stdafx.h"
#include "Tile.h"
#include <vector>
#include "../Plants/WaterPlant.h"
#include "../../Library/gameutil.h"
#include "Water.h"

namespace game_framework {
	Water::Water()
	{
	}

	Water::~Water()
	{
		delete _plant;
	}

	void Water::init(int posInLane, int lane)
	{
		_bitmap.LoadBitmapByString(WATER_BITMAP_FILEPATHS);
		int x = posInLane; // TODO: change pos to match the screen;
		int y = lane; // TODO: change pos to match the pos in the screen;
		_bitmap.SetTopLeft(x, y);
	}

	void Water::show()
	{
		_bitmap.ShowBitmap();
	}

	Plant * Water::getPlant()
	{
		return _plant;
	}

	void Water::setPlant(Plant * plant)
	{
		if (plant.getType() != "Water)
			return;

		if (_plant != nullptr)
			return;

		_plant = plant;
	}
}