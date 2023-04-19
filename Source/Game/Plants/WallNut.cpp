#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

WallNut::WallNut(CPoint pos)
{
	_type = PLANT::SQUASH;

	animate.LoadBitmapByString({
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_0.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_1.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_2.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_3.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_4.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_5.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_6.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_7.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_attackSpeed = 100;
	_damage = 10;
	_hp = 100;
	_price = WallNut::price;
}

WallNut::~WallNut()
{
}