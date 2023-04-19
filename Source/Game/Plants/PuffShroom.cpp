#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PuffShroom::PuffShroom(CPoint pos)
{
	_type = PLANT::PUFF_SHROOM;

	animate.LoadBitmapByString({
		"Resources/Plants/PuffShroom/BMP/PuffShroom_0.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_1.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_2.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_3.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_4.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_attackSpeed = 100;
	_damage = 10;
	_hp = 100;
	_price = PuffShroom::price;
}

PuffShroom::~PuffShroom()
{
}
