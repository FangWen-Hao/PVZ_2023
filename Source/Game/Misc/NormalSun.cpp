#include "stdafx.h"
#include "NormalSun.h"


using namespace game_framework;
void NormalSun::init(int finalPosX, int finalPosY)
{
	LoadBitmapByString(BITMAP_FILE_PATHS);
	_finalPosX = finalPosX;
	_finalPosY = finalPosY;
	_value = NORMAL_SUN_VALUE;
	SetTopLeft(_finalPosX, 50);
}
