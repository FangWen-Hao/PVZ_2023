#include "stdafx.h"
#include "LoadingScreen.h"
#include "../Utils/GameModeConsts.h"

namespace game_framework {
	LoadingScreen::LoadingScreen()
	{
	}
	LoadingScreen::~LoadingScreen()
	{
	}
	void LoadingScreen::init()
	{
		background.init(loadingBackgroundFilePath);
		loadingTime.initCooldown(LOADING_TIME);
		loadingTime.startCooldown();
	}
	void LoadingScreen::show()
	{
		background.show();
	}

	void LoadingScreen::OnMove()
	{
		Cooldown::updateGameClock();
		loadingTime.updateGameClock();

		if (!loadingTime.isOnCooldown())
			background.SetFrameIndexOfBitmap(1);
	}

	void LoadingScreen::OnKeyUp(UINT nChar)
	{
	}

	void LoadingScreen::OnHover(CPoint coords)
	{
	}

	int LoadingScreen::OnLClick(CPoint coords)
	{
		return getIsDone();
	}
	int LoadingScreen::OnRClick(CPoint coords)
	{
		return getIsDone();
	}
	int LoadingScreen::getIsDone()
	{
		if (background.GetFrameIndexOfBitmap() == 1)
			return MENU_NO_BTN_ACTION_ACCEPTED;

		return MENU_NO_BTN_ACTION_REJECTED;
	}
}