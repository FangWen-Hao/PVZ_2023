#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

RepeaterPea::RepeaterPea(CPoint pos) : ShootingPlant(PLANT::PEA_SHOOTER, PeaShooter::price, 7.5, 20, 1.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_0.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_1.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_2.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_3.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_4.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_5.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_6.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_7.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_8.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_9.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_10.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_11.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_12.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_13.bmp",
		"Resources/Plants/RepeaterPea/BMP/RepeaterPea_14.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void RepeaterPea::attack(vector<Bullet*>* bullets)
{
	bullets->push_back(
		new PeaShooterBullet(MIDDLE_TILES_POSITION_ON_MAP.at(_col), MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row), _damage));
	bullets->push_back(
		new PeaShooterBullet(LEFT_TILES_POSITION_ON_MAP.at(_col), MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row), _damage));
}