#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

Jalapeno::Jalapeno(CPoint pos, bool isDay) : DisposablePlant(PLANT::JALAPENO, Jalapeno::price, 50, false, isDay, 1800, 1)
{
	animate.LoadBitmapByString({
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_0.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_1.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_2.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_3.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_4.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_5.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_6.bmp",
		"Resources/Plants/Jalapeno/BMP/Jalapeno/Jalapeno_7.bmp",
	}, RGB(255, 255, 255));

	explodeAnimate.LoadBitmapByString({
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_0.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_1.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_2.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_3.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_4.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_5.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_6.bmp",
		"Resources/Plants/Jalapeno/BMP/JalapenoExplode/JalapenoExplode_7.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	explodeAnimate.SetAnimation(100, true);
	explodeAnimate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void Jalapeno::PlaceDown(int row, int col)
{
	DisposablePlant::PlaceDown(row, col);
	explodeAnimate.SetTopLeft(LEFT_TILES_POSITION_ON_MAP.at(0), BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(row) - explodeAnimate.GetHeight());
}

void Jalapeno::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies)
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
			if (findObjInVector(*zombies, zombie))
			{
				if (!isExplode && zombie->row() == _row && zombie->col() == _col)
				{
					isExplode = true;
					explodeAnimate.ToggleAnimation();
				} 
				else if (isExplode && explodeAnimate.IsAnimationDone() && zombie->row() == _row)
				{
					zombie->beingAttacked(_damage);
					_isDead = true;
				}
			}
		}
	}
}

void Jalapeno::onShow()
{
	if (isExplode)
		explodeAnimate.ShowBitmap();
	else
		animate.ShowBitmap();
}
