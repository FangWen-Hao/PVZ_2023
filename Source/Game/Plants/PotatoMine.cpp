#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PotatoMine::PotatoMine(CPoint pos, bool isDay) : DisposablePlant(PLANT::POTATO_MINE, PotatoMine::price, 30, isDay, 1800, 15)
{
	animate.LoadBitmapByString({
		"Resources/Plants/PotatoMine/BMP/PotatoMineInit_0.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_0.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_1.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_2.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_3.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_4.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_5.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_6.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMine_7.bmp",
		"Resources/Plants/PotatoMine/BMP/PotatoMineExplode_0.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, true);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void PotatoMine::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies)
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
					animate.ToggleAnimation();
				}
				else if (animate.IsAnimationDone())
				{
					zombie->beingAttacked(_damage);
					_isDead = true;
				}
			}
		}
	}
}
