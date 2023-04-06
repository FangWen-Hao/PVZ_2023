#include "stdafx.h"
#include "./Sun.h"

using namespace game_framework;

Sun::Sun()
{
}

void Sun::init(int posX, int startingPosY, int finalPosY)
{
	// initiate the sun with the values from the child class.
	lifespan.setCooldown(getLifeSpan());
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

	lifespan.setCooldown(getLifeSpan());
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

	lifespan.updateCooldown();

	if (GetTop() < _finalPosY)
	{
		SetTopLeft(_posX, GetTop() + 1);
	}

	return VALID;
}