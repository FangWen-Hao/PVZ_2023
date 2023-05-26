#include "stdafx.h"
#include "Lawnmower.h"
#include "../GameMode/Maps/Tile_Positions.h"
#include "../config.h"
#include "../Utils/Soundboard.h"

using namespace game_framework;
void Lawnmower::init(int row)
{
	bitmap.LoadBitmapByString(LAWNMOWER_BITMAP, RGB(255, 255, 255));
	bitmap.SetTopLeft(LEFT_TILES_POSITION_ON_MAP.at(0) - bitmap.GetWidth() + 1,
						MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(row) - (bitmap.GetHeight() / 2));
}

void Lawnmower::show()
{
	bitmap.ShowBitmap();
}

void Lawnmower::activate()
{
	SoundBoard::playSfx(soundID::SFX_LAWNMOWER);
	bitmap.SetAnimation(100, false);
	bitmap.ToggleAnimation();
}

bool Lawnmower::isActive()
{
	return bitmap.IsAnimation();
}

void Lawnmower::move()
{
	bitmap.SetTopLeft(bitmap.GetLeft() + LAWNMOWER_MOVEMENT_SPEED, bitmap.GetTop());
}

bool Lawnmower::isDone()
{
	return bitmap.GetLeft() > SIZE_X;
}


int game_framework::Lawnmower::getRight()
{
	return (bitmap.GetLeft() + bitmap.GetWidth());
}