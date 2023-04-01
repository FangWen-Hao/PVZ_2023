#pragma once
#include "GameMode.h"
#include "../Background/GameBar.h"
<<<<<<< HEAD
#include "../Plants/Plant.h"
#include "../Zombies/Zombie.h"
=======
>>>>>>> parent of d82ec6e (Implemented falling-suns logic)

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
		void move();
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
		
		bool isStarted = bar.isGameStarted();
		bool isSelectedPlant;
		PLANT plantsMap[9][5];	// the grid for the plants place on the map, not sure where to define this so I put it here first

		// GameMenu menu;
		// ProgressBar progress;
		// vector<Lane> lanes;
		vector<Zombie> zombies;

	};

}