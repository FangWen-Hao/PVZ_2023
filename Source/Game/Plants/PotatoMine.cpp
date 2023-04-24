#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PotatoMine::PotatoMine(CPoint pos) : DisposablePlant(PLANT::POTATO_MINE, PotatoMine::price, 30, 1800)
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

void PotatoMine::onMove()
{
	if (_isDetected)
	{
		if (animate.IsAnimationDone()) _isDead = true;
		return;
	}
}
