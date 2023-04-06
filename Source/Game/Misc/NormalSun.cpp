#include "stdafx.h"
#include "NormalSun.h"


using namespace game_framework;
void NormalSun::initiateBitMap()
{
	LoadBitmapByString(BITMAP_FILE_PATHS, RGB(255, 255, 255));
	SetAnimation(10, false);	// FIXME: no animation is showing after setting this
}

void NormalSun::initiateSunValue()
{
	_value = NORMAL_SUN_VALUE;
}

int NormalSun::getLifeSpan()
{
	return LIFESPAN;
}
