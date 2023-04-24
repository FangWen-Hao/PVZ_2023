#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

CherryBomb::CherryBomb(CPoint pos) : DisposablePlant(PLANT::CHERRY_BOMB, CherryBomb::price, 50, 1800)
{
	animate.LoadBitmapByString({
		"Resources/Plants/CherryBomb/BMP/CherryBomb_0.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_1.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_2.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_3.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_4.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_5.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_6.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}
