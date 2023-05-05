#include "stdafx.h"
#include "../config.h"
#include "ProgressBar.h"
#include <string>

#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../../Library/gamecore.h"

using namespace game_framework;

ProgressBar::ProgressBar()
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::init(int totalZombies, int currentLevel)
{
	this->totalZombies = totalZombies;
	this->level = currentLevel;
	image.LoadBitmapByString(PROGRESS_BAR_BITMAPS);
	// image.SetTopLeft(RESOLUTION_X / 2, RESOLUTION_Y / 2);
	image.SetTopLeft(RESOLUTION_X - image.GetWidth() - PADDING, RESOLUTION_Y - image.GetHeight() - PADDING);
	image.SetFrameIndexOfBitmap(0);
}

void ProgressBar::show()
{
	image.ShowBitmap();
	drawCurrentLevel();
}

void ProgressBar::updateCount()
{
	zombiesKilled++;

	double progress = ((double)zombiesKilled) * ((double)PROGRESS_BAR_STATES) / ((double)totalZombies);
	image.SetFrameIndexOfBitmap((int)progress); // progress will be TRUNCATED
}

bool ProgressBar::isGameComplete()
{
	return totalZombies == zombiesKilled;
}

void ProgressBar::drawCurrentLevel()
{
	CDC *pDC = CDDraw::GetBackCDC();
	const int size = 20;

	string msg = level == 0 ? "Demo Level" : ("Level " + to_string(level));

	/* Print title */
	CTextDraw::ChangeFontLog(pDC, size, "微軟正黑體", RGB(0, 0, 0), 800);
	CTextDraw::Print(pDC, image.GetLeft() - msg.size() * (int)(size / 1.5),  image.GetTop(), msg); // wip

	CDDraw::ReleaseBackCDC();
}
