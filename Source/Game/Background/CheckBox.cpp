#include "stdafx.h"
#include "CheckBox.h"
#include <atltypes.h>

using namespace game_framework;

void CheckBox::init(string unchecked, string checked, bool& boolVariable, int coordsX, int coordsY)
{
	LoadBitmapByString({ unchecked, checked }, RGB(255, 255, 255));
	SetTopLeft(coordsX, coordsY);

	boolVariablePtr = &boolVariable;
	if ((*boolVariablePtr))
	{
		SetFrameIndexOfBitmap(1);
	}
	else
	{
		SetFrameIndexOfBitmap(0);
	}
}

void CheckBox::show()
{
	ShowBitmap();
}

bool CheckBox::onClick(CPoint coords)
{
	bool wasClicked = coords.x < (GetLeft() + GetWidth()) && coords.x > GetLeft()
		&& coords.y < (GetTop() + GetHeight()) && coords.y > GetTop();
	if (wasClicked)
	{
		(*boolVariablePtr) = !(*boolVariablePtr);
		if ((*boolVariablePtr))
		{
			SetFrameIndexOfBitmap(1);
		}
		else
		{
			SetFrameIndexOfBitmap(0);
		}
	}
	return wasClicked;
}

bool CheckBox::isChked()
{
	return (*boolVariablePtr);
}
