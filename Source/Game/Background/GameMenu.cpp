#include "stdafx.h"
#include "GameMenu.h"
#include "../GameMode/GameMapsEnum.h"
#include "../config.h"
#include "../Misc/Cooldown.h"

using namespace game_framework;

bool GameMenu::isMusicOn;
bool GameMenu::isSoundFXOn;

void GameMenu::init()
{
	background.LoadBitmapByString({ GAME_MENU_BACKGROUND_BITMAP }, RGB(255, 255, 255));
	background.SetTopLeft((RESOLUTION_X - background.GetWidth()) / 2, (RESOLUTION_Y - background.GetHeight()) / 2);

	int backgroundX = background.GetLeft();
	int backgroundY = background.GetTop();

	menuCallerBtn.LoadBitmapByString(MENU_CALLER_BTN_BITMAPS, RGB(255, 255, 255));
	menuCallerBtn.SetTopLeft(RESOLUTION_X - menuCallerBtn.GetWidth(), 0);

	musicChkBox.init(CHKBOX_BITMAPS.at(0), CHKBOX_BITMAPS.at(1), isMusicOn, backgroundX + 205, backgroundY + 129);
	soundFXChkBox.init(CHKBOX_BITMAPS.at(0), CHKBOX_BITMAPS.at(1), isSoundFXOn, backgroundX + 205, backgroundY + 157);

	restartLvlBtn.LoadBitmapByString(RESTART_LEVEL_BTN_BITMAPS, RGB(255, 255, 255));
	restartLvlBtn.SetTopLeft(backgroundX + 112, backgroundY + 282);

	mainMenuBtn.LoadBitmapByString(MAIN_MENU_BTN_BITMAPS, RGB(255, 255, 255));
	mainMenuBtn.SetTopLeft(backgroundX + 112, backgroundY + 325);

	backToGameBtn.LoadBitmapByString(BACK_TO_GAME_BTN_BITMAPS, RGB(255, 255, 255));
	backToGameBtn.SetTopLeft(backgroundX + 43, backgroundY + 375);

	Cooldown::initGamePauseTime();
}

void GameMenu::show()
{
	if (isGamePaused)
	{
		background.ShowBitmap();
		musicChkBox.show();
		soundFXChkBox.show();
		restartLvlBtn.show();
		mainMenuBtn.show();
		backToGameBtn.show();
	}
	else
	{
		menuCallerBtn.show();
	}
}


void GameMenu::onHover(CPoint coords)
{
	if (isGamePaused)
	{
		if (coords.x < (restartLvlBtn.GetLeft() + restartLvlBtn.GetWidth()) && coords.x > restartLvlBtn.GetLeft()
			&& coords.y < (restartLvlBtn.GetTop() + restartLvlBtn.GetHeight()) && coords.y > restartLvlBtn.GetTop())
		{
			restartLvlBtn.SetFrameIndexOfBitmap(1);
			mainMenuBtn.SetFrameIndexOfBitmap(0);
			backToGameBtn.SetFrameIndexOfBitmap(0);
		}
		else if (coords.x < (mainMenuBtn.GetLeft() + mainMenuBtn.GetWidth()) && coords.x > mainMenuBtn.GetLeft()
			&& coords.y < (mainMenuBtn.GetTop() + mainMenuBtn.GetHeight()) && coords.y > mainMenuBtn.GetTop())
		{
			mainMenuBtn.SetFrameIndexOfBitmap(1);
			restartLvlBtn.SetFrameIndexOfBitmap(0);
			backToGameBtn.SetFrameIndexOfBitmap(0);
		}
		else if (coords.x < (backToGameBtn.GetLeft() + backToGameBtn.GetWidth()) && coords.x > backToGameBtn.GetLeft()
			&& coords.y < (backToGameBtn.GetTop() + backToGameBtn.GetHeight()) && coords.y > backToGameBtn.GetTop())
		{
			backToGameBtn.SetFrameIndexOfBitmap(1);
			restartLvlBtn.SetFrameIndexOfBitmap(0);
			mainMenuBtn.SetFrameIndexOfBitmap(0);
		}
		else
		{
			backToGameBtn.SetFrameIndexOfBitmap(0);
			restartLvlBtn.SetFrameIndexOfBitmap(0);
			mainMenuBtn.SetFrameIndexOfBitmap(0);
		}
	}
	else
	{
		if (coords.x < (menuCallerBtn.GetLeft() + menuCallerBtn.GetWidth()) && coords.x > menuCallerBtn.GetLeft()
			&& coords.y < (menuCallerBtn.GetTop() + menuCallerBtn.GetHeight()) && coords.y > menuCallerBtn.GetTop())
		{
			menuCallerBtn.SetFrameIndexOfBitmap(1);
		}
		else
		{
			menuCallerBtn.SetFrameIndexOfBitmap(0);
		}
	}
	
}

int GameMenu::onClick(CPoint coords, int currentLevel)
{
	if (!isGamePaused)
	{
		if (coords.x < (menuCallerBtn.GetLeft() + menuCallerBtn.GetWidth()) && coords.x > menuCallerBtn.GetLeft()
			&& coords.y < (menuCallerBtn.GetTop() + menuCallerBtn.GetHeight()) && coords.y > menuCallerBtn.GetTop())
		{
			isGamePaused = true;
			Cooldown::pauseClockBegin();
			return MENU_NO_BTN_ACTION_ACCEPTED;
		}
	}
	else
	{
		if (coords.x < (restartLvlBtn.GetLeft() + restartLvlBtn.GetWidth()) && coords.x > restartLvlBtn.GetLeft()
			&& coords.y < (restartLvlBtn.GetTop() + restartLvlBtn.GetHeight()) && coords.y > restartLvlBtn.GetTop())
		{
			return currentLevel;
		}
		else if (coords.x < (mainMenuBtn.GetLeft() + mainMenuBtn.GetWidth()) && coords.x > mainMenuBtn.GetLeft()
			&& coords.y < (mainMenuBtn.GetTop() + mainMenuBtn.GetHeight()) && coords.y > mainMenuBtn.GetTop())
		{
			return MENU_BTN;
		}
		else if (coords.x < (backToGameBtn.GetLeft() + backToGameBtn.GetWidth()) && coords.x > backToGameBtn.GetLeft()
			&& coords.y < (backToGameBtn.GetTop() + backToGameBtn.GetHeight()) && coords.y > backToGameBtn.GetTop())
		{
			isGamePaused = false;
			Cooldown::pauseClockEnd();
			return MENU_NO_BTN_ACTION_ACCEPTED;
		}

		if (musicChkBox.onClick(coords) || soundFXChkBox.onClick(coords))
		{
			return MENU_NO_BTN_ACTION_ACCEPTED;
		}
	}
	return MENU_NO_BTN_ACTION_REJECTED;
}

bool GameMenu::getIsGamePaused()
{
	return isGamePaused;
}
