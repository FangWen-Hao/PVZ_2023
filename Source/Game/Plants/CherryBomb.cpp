#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

CherryBomb::CherryBomb(CPoint pos)
{
	_type = PLANT::CHERRY_BOMB;

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

	_attackSpeed = 100;
	_damage = 10;
	_hp = 100;
	_price = CherryBomb::price;
}

CherryBomb::~CherryBomb()
{
}
