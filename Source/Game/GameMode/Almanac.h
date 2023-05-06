#pragma once
#include "GameMode.h"

namespace game_framework {
	const string ALMANAC_BG_PATH = "Resources/Background/Loading/Loading.bmp";


	class Almanac : public GameMode
	{
	public:
		Almanac();
		~Almanac();

		void init();
		void show();
		void OnMove();
		void OnHover(CPoint coords);
		int OnLClick(CPoint coords);
		int OnRClick(CPoint coords);
	};
}