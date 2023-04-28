#include "stdafx.h"
#include "Lawnmower.h"
#include "../GameMode/Maps/Tile_Positions.h"
#include "../config.h"

using namespace game_framework;
void Lawnmower::init(int row)
{
	_row = row;
	bitmap.LoadBitmapByString(LAWNMOWER_BITMAP, RGB(255, 255, 255));
	bitmap.SetTopLeft(LEFT_TILES_POSITION_ON_MAP.at(0) - bitmap.GetWidth() + 1,
						MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row) - (bitmap.GetHeight() / 2));
	active = false;
}

void Lawnmower::show()
{
	bitmap.ShowBitmap();
}

void Lawnmower::activate()
{
	bitmap.SetAnimation(100, false);
	bitmap.ToggleAnimation();
	active = true;
}

bool Lawnmower::isActive()
{
	return active;
}

void Lawnmower::move()
{
	bitmap.SetTopLeft(bitmap.GetLeft() + LAWNMOWER_MOVEMENT_SPEED, bitmap.GetTop());
}

bool Lawnmower::isDone()
{
	return bitmap.GetLeft() > SIZE_X;
}

int Lawnmower::getRow()
{
	return _row;;
}

int game_framework::Lawnmower::getRight()
{
	return (bitmap.GetLeft() + bitmap.GetWidth());
}