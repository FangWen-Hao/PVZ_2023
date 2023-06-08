#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

IceShroom::IceShroom(CPoint pos, bool isDay) : DisposablePlant(PLANT::ICE_SHROOM, IceShroom::price, 50, true, isDay, 20, 0)
{
	animate.LoadBitmapByString({
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom0.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom1.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom2.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom3.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom4.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom5.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom6.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom7.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom8.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom9.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroom/IceShroom10.bmp",
	}, RGB(255, 255, 255));

	sleepAnimate.LoadBitmapByString({
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep0.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep1.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep2.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep3.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep4.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep5.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep6.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep7.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep8.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep9.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep10.bmp",
		"Resources/Plants/IceShroom/BMP/IceShroomSleep/IceShroomSleep11.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	sleepAnimate.SetAnimation(100, false);

	animate.SetTopLeft(pos.x, pos.y);
	sleepAnimate.SetTopLeft(pos.x, pos.y);

	_hp = 300;

	_freezeTime = 3 + rand() % 4;
	_slowTime = 20 - _freezeTime;
}

void IceShroom::PlaceDown(int row, int col)
{
	DisposablePlant::PlaceDown(row, col);
	sleepAnimate.SetTopLeft(animate.GetLeft(), animate.GetTop());
}

void IceShroom::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies)
{
	if (_isDay) return;
}

void IceShroom::onShow()
{
	if (_isPlaceDown && _isDay)
	{
		sleepAnimate.ShowBitmap();
	}
	else
	{
		animate.ShowBitmap();
	}
}
