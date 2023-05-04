#include "stdafx.h"
#include "Bullet.h"

using namespace game_framework;

PuffShroomBullet::PuffShroomBullet(int x, int y, int damage)
{
	LoadBitmapByString({
		"Resources/Plants/PuffShroom/BMP/BulletMushRoom_0.bmp",
		"Resources/Plants/PuffShroom/BMP/BulletMushRoom_1.bmp",
		"Resources/Plants/PuffShroom/BMP/BulletMushRoom_2.bmp",
	}, RGB(255, 255, 255));

	SetAnimation(100, false);

	SetTopLeft(x, y);
	_damage = damage;
}

PuffShroomBullet::~PuffShroomBullet()
{
}
