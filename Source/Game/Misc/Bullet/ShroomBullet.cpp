#include "stdafx.h"
#include "Bullet.h"

using namespace game_framework;

ShroomBullet::ShroomBullet(int x, int y, int damage) : Bullet(damage)
{
	LoadBitmapByString({
		"Resources/Plants/PuffShroom/BMP/BulletMushRoom_0.bmp",
		"Resources/Plants/PuffShroom/BMP/BulletMushRoom_1.bmp",
		"Resources/Plants/PuffShroom/BMP/BulletMushRoom_2.bmp",
	}, RGB(255, 255, 255));

	SetAnimation(100, false);

	SetTopLeft(x, y);
}

PuffShroomBullet::PuffShroomBullet(int x, int y, int damage, int plantCol) : ShroomBullet(x, y, damage)
{
	_plantCol = plantCol;
}

void PuffShroomBullet::onMove()
{
	ShroomBullet::onMove();

	if (GetLeft() + GetWidth() > RIGHT_TILES_POSITION_ON_MAP.at(_plantCol + 3))
		outOfRange = true;
}