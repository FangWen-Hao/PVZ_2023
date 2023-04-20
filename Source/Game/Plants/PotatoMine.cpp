#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PotatoMine::PotatoMine(CPoint pos)
{
	_type = PLANT::POTATO_MINE;

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

	_attackSpeed = 100;
	_damage = 10;
	_hp = 100;
	_price = PotatoMine::price;
}

PotatoMine::~PotatoMine()
{
}

void PotatoMine::onMove(vector<Bullet*>* bullets, vector<Zombie*>* zombies)
{
	if (_isDetected)
	{
		if (animate.IsAnimationDone()) _isDead = true;
		return;
	}

	for (Zombie* zombie : *zombies) {
		if (animate.GetLeft() < (zombie->GetLeft() + zombie->GetWidth()) &&
			(animate.GetLeft() + animate.GetWidth()) > zombie->GetLeft() &&
			animate.GetTop() < (zombie->GetTop() + zombie->GetHeight()) &&
			(animate.GetTop() + animate.GetHeight()) > zombie->GetTop())
		{
			_isDetected = true;
			animate.ToggleAnimation();
			return;
		}
	}
}
