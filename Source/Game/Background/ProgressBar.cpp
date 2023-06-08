#include "stdafx.h"
#include "../config.h"
#include "ProgressBar.h"
#include <string>
#include "../Utils/GameModeConsts.h"
#include <strstream>

#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../../Library/gamecore.h"

using namespace std;
using namespace game_framework;

ProgressBar::ProgressBar()
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::init(int totalZombies)
{
	this->totalZombies = totalZombies;
	image.LoadBitmapByString(PROGRESS_BAR_BITMAPS, RGB(142, 144, 143));
	// image.SetTopLeft(RESOLUTION_X / 2, RESOLUTION_Y / 2);
	image.SetTopLeft(RESOLUTION_X - image.GetWidth() - PADDING, RESOLUTION_Y - image.GetHeight() - PADDING);
	image.SetFrameIndexOfBitmap(0);
}

void ProgressBar::show(int currentLevel)
{
	image.ShowBitmap();
	drawCurrentLevel(currentLevel);
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

void ProgressBar::drawCurrentLevel(int currentLevel)
{
	CDC *pDC = CDDraw::GetBackCDC();
	const int size = 20;

	string msg = getCurrentLevelMsg(currentLevel);


	/* Print title */
	CTextDraw::ChangeFontLog(pDC, size, "微軟正黑體", RGB(0, 0, 0), 800);
	CTextDraw::Print(pDC, image.GetLeft() - msg.size() * (int)(size / 1.5),  image.GetTop(), msg); // wip

	CDDraw::ReleaseBackCDC();
}

string ProgressBar::getCurrentLevelMsg(int currentLevel)
{
	int pos = 0;

	for (pair<int, int> bound : LEVEL_SETS_BOUNDERIES)
	{		
		if (currentLevel >= bound.second)
		{
			pos++;
		}
	}

	if (pos <= 0)
		return "Demo Level";

	strstream ret;

	ret << "Level " << pos << "-" << currentLevel - LEVEL_SETS_BOUNDERIES.at(pos) + 1 << ends;

	return ret.str();
}
