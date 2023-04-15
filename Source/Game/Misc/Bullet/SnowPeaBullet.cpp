#include "stdafx.h"
#include "Bullet.h"

using namespace game_framework;

SnowPeaBullet::SnowPeaBullet(int x, int y, int damage)
{
	LoadBitmapByString({
		"Resources/Plants/SnowPea/BMP/SnowPeaBullet.bmp",
		}, RGB(255, 255, 255));

	SetTopLeft(x, y);
	_damage = damage;
}

SnowPeaBullet::~SnowPeaBullet()
{
}