#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PuffShroom::PuffShroom(CPoint pos) : ShootingPlant(PLANT::PUFF_SHROOM, PuffShroom::price, 7.5, 20, 1.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/PuffShroom/BMP/PuffShroom_0.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_1.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_2.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_3.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_4.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void PuffShroom::attack(vector<Bullet*>* bullets)
{
	// TODO
}