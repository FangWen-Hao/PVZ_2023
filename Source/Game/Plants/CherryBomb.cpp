#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"
#include "../Misc/Sun.h"
#include "../Zombies/Zombie.h"

using namespace game_framework;

CherryBomb::CherryBomb(CPoint pos, bool isDay) : DisposablePlant(PLANT::CHERRY_BOMB, CherryBomb::price, 50, false, isDay, 1800, 1)
{
	animate.LoadBitmapByString({
		"Resources/Plants/CherryBomb/BMP/CherryBomb_0.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_1.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_2.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_3.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_4.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_5.bmp",
		"Resources/Plants/CherryBomb/BMP/CherryBomb_6.bmp",
	}, RGB(255, 255, 255));

	boomAnimate.LoadBitmapByString({
		"Resources/Plants/CherryBomb/BMP/Boom.bmp",
	}, RGB(255, 255, 255));
	
	animate.SetAnimation(100, false);
	boomAnimate.SetAnimation(1000, true);
	
	animate.SetTopLeft(pos.x, pos.y);
	boomAnimate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void CherryBomb::PlaceDown(int row, int col)
{
	DisposablePlant::PlaceDown(row, col);
	boomAnimate.SetTopLeft(animate.GetLeft(), animate.GetTop());
}

void CherryBomb::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies)
{
	Plant::onMove(bullets, suns, zombies);

	if (!isReady)
	{
		if (!readyClock.isOnCooldown())
			isReady = true;
	}
	else
	{
		for (Zombie* zombie : *zombies) {
			if (findObjInVector(*zombies, zombie) &&
				zombie->row() == _row && zombie->col() == _col)
			{
				if (!isBoom)
				{
					isBoom = true;
					boomAnimate.ToggleAnimation();
				}
				else if (boomAnimate.IsAnimationDone())
				{
					zombie->beingAttacked(_damage);
					_isDead = true;
				}
			}
		}
	}
}

void CherryBomb::onShow()
{
	if (isBoom)
		boomAnimate.ShowBitmap();
	else
		animate.ShowBitmap();
}
