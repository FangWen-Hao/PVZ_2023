#include "stdafx.h"
#include "LoadingScreen.h"

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
		// Animation logic here.
	}
	void LoadingScreen::OnHover(CPoint coords)
	{
	}
	int LoadingScreen::OnClick(CPoint coords)
	{
		if (isDone)
			return MENU_NO_BTN_ACTION_ACCEPTED;

		return MENU_NO_BTN_ACTION_REJECTED;
	}
	bool LoadingScreen::getIsDone()
	{
		return isDone;
	}
}