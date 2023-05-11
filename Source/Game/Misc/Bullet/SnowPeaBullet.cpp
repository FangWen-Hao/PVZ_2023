#include "stdafx.h"
#include "Bullet.h"

using namespace game_framework;

SnowPeaBullet::SnowPeaBullet(int x, int y, int damage) : Bullet(damage)
{
	LoadBitmapByString({
		"Resources/Plants/SnowPea/BMP/SnowPeaBullet.bmp",
	}, RGB(255, 255, 255));

	SetTopLeft(x, y);
}

bool SnowPeaBullet::detectCollison(vector<Zombie*>* zombies)
{
	for (Zombie* zombie : *zombies) {
		if (findObjInVector(*zombies, zombie) &&
			!zombie->isDead() &&
			GetLeft() < zombie->right() && (GetLeft() + GetWidth()) > zombie->left() &&
			GetTop() < zombie->bottom() && (GetTop() + GetHeight()) > zombie->top()) {
			zombie->beingAttacked(_damage);
			zombie->setSlow(true);
			return true;
		}
	}
	return false;
}