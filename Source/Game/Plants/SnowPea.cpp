#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

SnowPea::SnowPea(CPoint pos, bool isDay) : ShootingPlant(PLANT::SNOW_PEA, SnowPea::price, 7.5, isDay, 20, 1.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/SnowPea/BMP/SnowPea_0.bmp",
		"Resources/Plants/SnowPea/BMP/SnowPea_1.bmp",
		"Resources/Plants/SnowPea/BMP/SnowPea_2.bmp",
		"Resources/Plants/SnowPea/BMP/SnowPea_3.bmp",
		"Resources/Plants/SnowPea/BMP/SnowPea_4.bmp",
		"Resources/Plants/SnowPea/BMP/SnowPea_5.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void SnowPea::attack(vector<Bullet*>* bullets)
{
	bullets->push_back(
		new SnowPeaBullet(animate.GetLeft() + animate.GetWidth(), animate.GetTop(), _damage));
}
