#pragma once
#include "GameMode.h"
#include "../Background/GameBar.h"

using namespace std;
namespace game_framework {
	const string MAP_BG_DAY = "Resources/Background/GAME/DAY/BMP/Background.bmp";
	const string MAP_BG_NIGHT = "Resources/Background/GAME/NIGHT/BMP/Background_1.bmp";

	class Map : public GameMode
	{
	public:
		Map();
		~Map();

		void init();
		void show();
		void OnHover(CPoint coords);
		int OnClick(CPoint coords);

		void setIsDay(bool val);
		bool getIsDay();

	private:
		int ZombiesKilled = 0;
		int sunsAmount = 50;
		bool isDay;
		GameBar bar;
		// GameMenu menu;
		// ProgressBar progress;
		// vector<Lane> lanes;
		// vecctor<Zombies> zombs;

	};

}