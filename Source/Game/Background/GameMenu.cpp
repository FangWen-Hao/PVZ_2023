#include "stdafx.h"
#include "GameMenu.h"
#include "../Utils/GameModeConsts.h"
#include "../config.h"
#include "../Misc/Cooldown.h"
#include "../Utils/Soundboard.h"

using namespace game_framework;

void GameMenu::init(int previousLevel, int currentLevel, int nextLevel)
{
	background.LoadBitmapByString({ GAME_MENU_BACKGROUND_BITMAP }, RGB(255, 255, 255));
	background.SetTopLeft((RESOLUTION_X - background.GetWidth()) / 2, (RESOLUTION_Y - background.GetHeight()) / 2);

	int backgroundX = background.GetLeft();
	int backgroundY = background.GetTop();

	this->previousLevel = previousLevel;
	this->currentLevel = currentLevel;
	this->nextLevel = nextLevel;

	int btnsXAlignement = backgroundX + 112;
	int btnsYAlignement = backgroundY + 325;

	menuCallerBtn.LoadBitmapByString(MENU_CALLER_BTN_BITMAPS, RGB(255, 255, 255));
	menuCallerBtn.SetTopLeft(RESOLUTION_X - menuCallerBtn.GetWidth(), 0);


	musicChkBox.init(CHKBOX_BITMAPS.at(0), CHKBOX_BITMAPS.at(1), SoundBoard::isMusicOn(), &SoundBoard::toggleMusic, backgroundX + 205, backgroundY + 129);
	
	
	soundFXChkBox.init(CHKBOX_BITMAPS.at(0), CHKBOX_BITMAPS.at(1), SoundBoard::isSfxOn(), &SoundBoard::toggleSFX, backgroundX + 205, backgroundY + 157);

	mainMenuBtn.LoadBitmapByString(MAIN_MENU_BTN_BITMAPS, RGB(255, 255, 255));
	mainMenuBtn.SetTopLeft(backgroundX + 112, btnsYAlignement);
	btnsYAlignement -= GAME_MENU_BTNS_PADDING;

	restartLvlBtn.LoadBitmapByString(RESTART_LEVEL_BTN_BITMAPS, RGB(255, 255, 255));
	restartLvlBtn.SetTopLeft(btnsXAlignement, btnsYAlignement);
	btnsYAlignement -= GAME_MENU_BTNS_PADDING;

	if (nextLevel != MENU_BTN)
	{
		nextLvlBtn.LoadBitmapByString(NEXT_LEVEL_BTN_BITMAPS, RGB(255, 255, 255));
		nextLvlBtn.SetTopLeft(btnsXAlignement, btnsYAlignement);
		btnsYAlignement -= GAME_MENU_BTNS_PADDING;
	}

	if (previousLevel != MENU_BTN)
	{
		previousLvlBtn.LoadBitmapByString(PREVIOUS_LEVEL_BTN_BITMAPS, RGB(255, 255, 255));
		previousLvlBtn.SetTopLeft(btnsXAlignement, btnsYAlignement);
	}

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

		if (previousLevel != MENU_BTN)
			previousLvlBtn.show();

		if (nextLevel != MENU_BTN)
			nextLvlBtn.show();

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

int GameMenu::onClick(CPoint coords, bool isDay, bool gameStarted)
{
	if (!isGamePaused)
	{
		if (coords.x < (menuCallerBtn.GetLeft() + menuCallerBtn.GetWidth()) && coords.x > menuCallerBtn.GetLeft()
			&& coords.y < (menuCallerBtn.GetTop() + menuCallerBtn.GetHeight()) && coords.y > menuCallerBtn.GetTop())
		{
			isGamePaused = true;
			Cooldown::pauseClockBegin();

			if (gameStarted)
			{
				if (isDay)
					SoundBoard::stopSound(soundID::DAY_MAP);
				else
				SoundBoard::stopSound(soundID::NIGHT_MAP);

				SoundBoard::playMusic(soundID::CHOOSE_YOUR_SEEDS, true);
			}

			return MENU_NO_BTN_ACTION_ACCEPTED;
		}
	}
	else
	{
		if (previousLevel != MENU_BTN
			&&coords.x < (previousLvlBtn.GetLeft() + previousLvlBtn.GetWidth()) && coords.x > previousLvlBtn.GetLeft()
			&& coords.y < (previousLvlBtn.GetTop() + previousLvlBtn.GetHeight()) && coords.y > previousLvlBtn.GetTop())
		{
			return previousLevel;
		}

		if (nextLevel != MENU_BTN
			&& coords.x < (nextLvlBtn.GetLeft() + nextLvlBtn.GetWidth()) && coords.x > nextLvlBtn.GetLeft()
			&& coords.y < (nextLvlBtn.GetTop() + nextLvlBtn.GetHeight()) && coords.y > nextLvlBtn.GetTop())
		
		{
			return nextLevel;
		}

		if (coords.x < (restartLvlBtn.GetLeft() + restartLvlBtn.GetWidth()) && coords.x > restartLvlBtn.GetLeft()
			&& coords.y < (restartLvlBtn.GetTop() + restartLvlBtn.GetHeight()) && coords.y > restartLvlBtn.GetTop())
		{
			return currentLevel;
		}
		if (coords.x < (mainMenuBtn.GetLeft() + mainMenuBtn.GetWidth()) && coords.x > mainMenuBtn.GetLeft()
			&& coords.y < (mainMenuBtn.GetTop() + mainMenuBtn.GetHeight()) && coords.y > mainMenuBtn.GetTop())
		{
			return MENU_BTN;
		}
		if (coords.x < (backToGameBtn.GetLeft() + backToGameBtn.GetWidth()) && coords.x > backToGameBtn.GetLeft()
			&& coords.y < (backToGameBtn.GetTop() + backToGameBtn.GetHeight()) && coords.y > backToGameBtn.GetTop())
		{
			isGamePaused = false;
			Cooldown::pauseClockEnd();

			if (gameStarted)
			{
				SoundBoard::stopSound(soundID::CHOOSE_YOUR_SEEDS);

				if (isDay)
					SoundBoard::playMusic(soundID::DAY_MAP, true);
				else
					SoundBoard::playMusic(soundID::NIGHT_MAP, true);
			}
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
