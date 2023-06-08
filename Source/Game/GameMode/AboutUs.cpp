#include "stdafx.h"
#include "AboutUs.h"
#include "../Utils/GameModeConsts.h"

namespace game_framework {
	AboutUs::AboutUs()
	{
	}

	AboutUs::~AboutUs()
	{
	}

	void AboutUs::init()
	{
		background.init(AboutUs_BG_PATH);
	}

	void AboutUs::show()
	{
		background.show();
	}

	void AboutUs::OnMove()
	{

	}

	void AboutUs::OnKeyUp(UINT nChar)
	{
	}

	void AboutUs::OnHover(CPoint coords)
	{
	}

	int AboutUs::OnLClick(CPoint coords)
	{
		return MENU_BTN;
	}

	int AboutUs::OnRClick(CPoint coords)
	{
		return MENU_BTN;
	}
}
