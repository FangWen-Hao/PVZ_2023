#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

Squash::Squash(CPoint pos) : DisposablePlant(PLANT::SQUASH, Squash::price, 30, 1800, 0)
{
	animate.LoadBitmapByString({
		"Resources/Plants/Squash/BMP/Squash_0.bmp",
		"Resources/Plants/Squash/BMP/Squash_1.bmp",
		"Resources/Plants/Squash/BMP/Squash_2.bmp",
		"Resources/Plants/Squash/BMP/Squash_3.bmp",
		"Resources/Plants/Squash/BMP/Squash_4.bmp",
		"Resources/Plants/Squash/BMP/Squash_5.bmp",
		"Resources/Plants/Squash/BMP/Squash_6.bmp",
		"Resources/Plants/Squash/BMP/Squash_7.bmp",
	}, RGB(255, 255, 255));

	activeAnimate.LoadBitmapByString({
		"Resources/Plants/Squash/BMP/SquashAim_0.bmp",
		"Resources/Plants/Squash/BMP/SquashAttack_0.bmp",
		"Resources/Plants/Squash/BMP/SquashAttack_1.bmp",
		"Resources/Plants/Squash/BMP/SquashAttack_2.bmp",
		"Resources/Plants/Squash/BMP/SquashAttack_3.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	activeAnimate.SetAnimation(100, true);

	animate.SetTopLeft(pos.x, pos.y);
	activeAnimate.SetTopLeft(pos.x, pos.y);
	
	_hp = 300;
}

void Squash::PlaceDown(int row, int col)
{
	DisposablePlant::PlaceDown(row, col);
	activeAnimate.SetTopLeft(animate.GetLeft(), animate.GetTop() + animate.GetHeight() - activeAnimate.GetHeight());
}

void Squash::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies)
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
			if (zombie->row() == _row && zombie->col() == _col)
			{
				if (!isActivate)
				{
					isActivate = true;
					activeAnimate.ToggleAnimation();
				}
				else if (activeAnimate.IsAnimationDone())
				{
					zombie->beingAttacked(_damage);
					_isDead = true;
				}
			}
		}
	}
}

void Squash::onShow()
{
	if (isActivate)
		activeAnimate.ShowBitmap();
	else
		animate.ShowBitmap();
}