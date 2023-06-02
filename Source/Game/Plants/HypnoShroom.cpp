#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"
#include "../Misc/Sun.h"
#include "../Zombies/Zombie.h"

using namespace game_framework;

HypnoShroom::HypnoShroom(CPoint pos, bool isDay) : DisposablePlant(PLANT::HYPNO_SHROOM, HypnoShroom::price, 30, true, isDay, 0, 0)
{
	animate.LoadBitmapByString({
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom0.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom1.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom2.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom3.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom4.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom5.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom6.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom7.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom8.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom9.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom10.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom11.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom12.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom13.bmp",
		"Resources/Plants/HypnoShroom/BMP/HypnoShroom/HypnoShroom14.bmp",
	}, RGB(255, 255, 255));

	sleepAnimate.LoadBitmapByString({
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep0.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep1.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep2.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep3.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep4.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep5.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep6.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep7.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep8.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep9.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep10.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep11.bmp",
		"Resources/Plants/HypnoShroomSleep/BMP/HypnoShroomSleep/HypnoShroomSleep12.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	sleepAnimate.SetAnimation(100, false);

	animate.SetTopLeft(pos.x, pos.y);
	sleepAnimate.SetAnimation(pos.x, pos.y);

	_hp = 300;
}

void HypnoShroom::PlaceDown(int row, int col)
{
	DisposablePlant::PlaceDown(row, col);
	sleepAnimate.SetTopLeft(animate.GetLeft(), animate.GetTop());
}
