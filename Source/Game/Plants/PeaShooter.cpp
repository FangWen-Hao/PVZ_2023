#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

PeaShooter::PeaShooter(CPoint pos, bool isDay) : ShootingPlant(PLANT::PEA_SHOOTER, PeaShooter::price, 7.5, isDay, 20, 1.5)
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

	_hp = 300;
}

void PeaShooter::attack(vector<Bullet*>* bullets)
{
	bullets->push_back(
		new PeaShooterBullet(animate.GetLeft() + animate.GetWidth(), animate.GetTop(), _damage));
}
