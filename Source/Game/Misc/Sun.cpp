#include "stdafx.h"
#include "./Sun.h"

using namespace game_framework;

Sun::Sun()
{
}

void Sun::init(int posX, int startingPosY, int finalPosY)
{
	// initiate the sun with the values from the child class.
	lifespan.initCooldown(getLifeSpan());
	initiateBitMap();
	initiateSunValue();

	// normalized so the sun goes in the midle.
	_posX = posX + (GetWidth() / 2);
	_finalPosY = finalPosY - (GetHeight() / 2);
	SetTopLeft(posX, startingPosY);
}

void Sun::show()
{
	SetAnimation(1, false);

	ShowBitmap();
	ToggleAnimation();

	lifespan.initCooldown(getLifeSpan());
	lifespan.startCooldown();
}

void Sun::unshow()
{
	ToggleAnimation();
	UnshowBitmap();
}

int Sun::update()
{
	if (!lifespan.isOnCooldown())
		return INVALID;

	if (GetTop() < _finalPosY)
	{
		SetTopLeft(_posX, GetTop() + 1);
	}

	return VALID;
}

bool Sun::onClick(CPoint pos)
{
	if (pos.x < right() && pos.x > left() &&
		pos.y < bottom() && pos.y > top())
		return true;
	return false;
}
