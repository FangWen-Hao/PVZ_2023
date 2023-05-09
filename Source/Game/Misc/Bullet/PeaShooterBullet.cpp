#include "stdafx.h"
#include "Bullet.h"

using namespace game_framework;

PeaShooterBullet::PeaShooterBullet(int x, int y, int damage) : Bullet(damage)
{
	LoadBitmapByString({
		"Resources/Plants/PeaShooter/BMP/PeaShooterBullet.bmp",
	}, RGB(255, 255, 255));

	SetTopLeft(x, y);
}
