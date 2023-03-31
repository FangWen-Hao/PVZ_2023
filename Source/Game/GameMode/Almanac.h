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
		void move() {}
		void show();
		void OnHover(CPoint coords);
		int OnClick(CPoint coords);
	};
}