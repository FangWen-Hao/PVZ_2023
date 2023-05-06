#pragma once
#include "../Background/Background.h"
#include <atltypes.h>

namespace game_framework {
	enum MENU_BTN_STATE {
		MENU_NO_BTN_ACTION_REJECTED = -1,
		MENU_NO_BTN_ACTION_ACCEPTED,
		ADVENTURE_MODE_BTN,
		ALMANAC_BTN,
		MENU_BTN,
		LOADING = 12,
	};

	class GameMode
	{
	public:
		GameMode() {};
		~GameMode() {};
		virtual void init() = 0;
		virtual void show() = 0;
		virtual void OnMove() = 0;
		virtual void OnHover(CPoint coords) = 0;
		virtual int OnLClick(CPoint coords) = 0;
		virtual int OnRClick(CPoint coords) = 0;

	protected:
		Background background;
	};
}