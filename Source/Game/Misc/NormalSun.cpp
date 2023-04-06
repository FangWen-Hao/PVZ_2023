#include "stdafx.h"
#include "NormalSun.h"


using namespace game_framework;
void NormalSun::initiateBitMap()
{
	LoadBitmapByString(BITMAP_FILE_PATHS);
}

void NormalSun::initiateSunValue()
{
	_value = NORMAL_SUN_VALUE;
}

int NormalSun::getLifeSpan()
{
	return LIFESPAN;
}
