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
	}
	void LoadingScreen::show()
	{
		background.show();
	}

	void LoadingScreen::OnMove()
	{
		// Animation logic here?
	}

	void LoadingScreen::OnKeyUp(UINT nChar)
	{
	}

	void LoadingScreen::OnHover(CPoint coords)
	{
	}

	int LoadingScreen::OnLClick(CPoint coords)
	{
		if (isDone)
			return MENU_NO_BTN_ACTION_ACCEPTED;

		return MENU_NO_BTN_ACTION_REJECTED;
	}
	int LoadingScreen::OnRClick(CPoint coords)
	{
		return 0;
	}
	bool LoadingScreen::getIsDone()
	{
		return isDone;
	}
}