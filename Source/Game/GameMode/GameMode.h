#pragma once
#include "../Background/Background.h"
#include <atltypes.h>

namespace game_framework {
	class GameMode
	{
	public:
		GameMode() {};
		virtual ~GameMode() {};
		virtual void init() = 0;
		virtual void show() = 0;
		virtual void OnMove() = 0;
		virtual void OnKeyUp(UINT) = 0;
		virtual void OnHover(CPoint) = 0;
		virtual int OnLClick(CPoint) = 0;
		virtual int OnRClick(CPoint) = 0;

	protected:
		Background background;
	};
}