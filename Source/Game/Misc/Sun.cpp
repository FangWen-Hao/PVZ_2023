#include "stdafx.h"
#include "./Sun.h"

using namespace game_framework;

void Sun::show()
{
	SetAnimation(1, false);

	ShowBitmap();
	ToggleAnimation();
}

void Sun::unshow()
{
	ToggleAnimation();
	UnshowBitmap();
}

int Sun::update()
{
	lifespan.updateCooldown();

	if (GetTop() == _finalPosY - 10)
	{
		lifespan.startCooldown();
	}

	if (GetTop() < _finalPosY)
	{
		SetTopLeft(_finalPosX, GetTop() + 1);
	}

	if (GetTop() == _finalPosY)
	{
		if (!lifespan.isOnCooldown())
			return INVALID;
	}

	return VALID;
}