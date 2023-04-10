#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PeaShooter::PeaShooter(CPoint pos)
{
	animate.LoadBitmapByString({
		"Resources/Plants/PeaShooter/BMP/Peashooter_0.bmp",
		"Resources/Plants/PeaShooter/BMP/Peashooter_1.bmp",
		"Resources/Plants/PeaShooter/BMP/Peashooter_2.bmp",
		"Resources/Plants/PeaShooter/BMP/Peashooter_3.bmp",
		"Resources/Plants/PeaShooter/BMP/Peashooter_4.bmp",
		"Resources/Plants/PeaShooter/BMP/Peashooter_5.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);
}

PeaShooter::~PeaShooter()
{

}