#include "stdafx.h"
#include "Tile.h"
#include <vector>
#include "../Plants/GrassPlant.h"
#include "../../Library/gameutil.h"
#include "Grass.h"


namespace game_framework {
	Grass::Grass()
	{
	}

	Grass::~Grass()
	{
		delete _plant;
	}

	void Grass::init(int posInLane, int lane)
	{
		_bitmap.LoadBitmapByString(GRASS_BITMAP_FILEPATH);
		int x = posInLane; // TODO: change pos to match the screen;
		int y = lane; // TODO: change pos to match the pos in the screen;
		_bitmap.SetTopLeft(x, y);
	}

	void Grass::show()
	{
		_bitmap.ShowBitmap();
	}

	Plant * Grass::getPlant()
	{
		return _plant;
	}

	void Grass::setPlant(Plant *plant)
	{
		if (plant.getType() != "Grass")
			return;

		if (_plant != nullptr)
			return;

		_plant = plant;
	}
}

