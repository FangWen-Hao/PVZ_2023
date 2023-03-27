#pragma once
#include "../Background/Background.h"
#include <atltypes.h>

namespace game_framework {
	const int MENU_NO_BTN_ACTION_REJECTED = -1;
	const int MENU_NO_BTN_ACTION_ACCEPTED = 0;
	const int ADVENTURE_MODE_BTN = 1;
	const int ALMANAC_BTN = 2;
	const int MENU_BTN = 3;
	const int LOADING = 12;

	class GameMode
	{
	public:
		GameMode() {};
		~GameMode() {};
		virtual void init() = 0;
		virtual void show() = 0;
		virtual void OnHover(CPoint coords) = 0;
		virtual int OnClick(CPoint coords) = 0;

	protected:
		Background background;
	};
}