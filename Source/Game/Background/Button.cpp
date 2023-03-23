#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include "../../Library/gameutil.h"
#include "Button.h"

using namespace std;
using namespace game_framework;

Button::Button()
{
}

void Button::init(vector<string> filePath, string offsetX, string offsetY)
{
	LoadBitmapByString(filePath);
	SetTopLeft(stoi(offsetX), stoi(offsetY));
	SetFrameIndexOfBitmap(0);
}

void Button::init(vector<string> filePath, int offsetX, int offsetY)
{
	LoadBitmapByString(filePath);
	SetTopLeft(offsetX, offsetY);
	SetFrameIndexOfBitmap(0);
}

void Button::show()
{
	ShowBitmap();
}

void Button::clicked()
{
	SetFrameIndexOfBitmap(1);
}
