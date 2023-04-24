#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

Squash::Squash(CPoint pos) : DisposablePlant(PLANT::SQUASH, Squash::price, 30, 1800)
{
	animate.LoadBitmapByString({
		"Resources/Plants/Squash/BMP/Squash_0.bmp",
		"Resources/Plants/Squash/BMP/Squash_1.bmp",
		"Resources/Plants/Squash/BMP/Squash_2.bmp",
		"Resources/Plants/Squash/BMP/Squash_3.bmp",
		"Resources/Plants/Squash/BMP/Squash_4.bmp",
		"Resources/Plants/Squash/BMP/Squash_5.bmp",
		"Resources/Plants/Squash/BMP/Squash_6.bmp",
		"Resources/Plants/Squash/BMP/Squash_7.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}
