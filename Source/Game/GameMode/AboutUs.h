#pragma once
#include "GameMode.h"
#include "../Background/Background.h"

namespace game_framework {
	const string AboutUs_BG_PATH = "Resources/About us/aboutUs.bmp";


	class AboutUs : public GameMode
	{
	public:
		AboutUs();
		~AboutUs();

		void init();
		void show();
		void OnMove();
		void OnKeyUp(UINT);
		void OnHover(CPoint);
		int OnLClick(CPoint);
		int OnRClick(CPoint);

	private:
		Background bg;
	};
}