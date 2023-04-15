#include "stdafx.h"
#include "Plant.h"
#include "../Misc/NormalSun.h"

using namespace game_framework;

SunFlower::SunFlower(CPoint pos)
{
	_type = PLANT::SUN_FLOWER;

	animate.LoadBitmapByString({
		"Resources/Plants/SunFlower/BMP/SunFlower_0.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_1.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_2.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_3.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_4.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_5.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_6.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_7.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_attackSpeed = 200;
	_price = SunFlower::price;
}

SunFlower::~SunFlower()
{
}

void SunFlower::generateSun(vector<Sun*>* suns)
{
	suns->push_back(new NormalSun());
	suns->back()->init(
		animate.GetLeft(),
		animate.GetTop(),
		animate.GetTop() + animate.GetHeight());
}
