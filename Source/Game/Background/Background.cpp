#pragma once
#include "stdafx.h"
#include <vector>
#include "Background.h"


using namespace game_framework;

Background::Background() : CMovingBitmap()
{
}

void Background::init(string filePath)
{
	CMovingBitmap::LoadBitmapByString({ filePath });
	CMovingBitmap::SetTopLeft(0, 0);
}

void Background::show()
{
	ShowBitmap();
}