#pragma once
#include "GameMode.h"
#include "../Background/GameBar.h"
#include "../Plants/Plant.h"
#include "../Zombies/Zombie.h"
#include "../Misc/Sun.h"

using namespace std;
namespace game_framework {
	const string MAP_BG_DAY = "Resources/Background/GAME/DAY/BMP/Background.bmp";
	const string MAP_BG_NIGHT = "Resources/Background/GAME/NIGHT/BMP/Background.bmp";
	const int SUN_PRODUCTION_COOLDOWN = 10;
	const unsigned int MAX_SUNS_FALLEN = 10;

	// temporary put it here: do we want to migrate these 2 const?
	const map<int, int> LANE_POSITION_ON_SCREEN_MAP = {
		{0, 128},
		{1, 228},
		{2, 328},
		{3, 428},
		{4, 528},
	};

	const map<int, int> TILES_POSITION_ON_MAP = {
		{0, 90},
		{1, 168},
		{2, 250},
		{3, 330},
		{4, 410},
		{5, 490},
		{6, 570},
		{7, 650},
		{8, 740},
	};

	class Map : public GameMode
	{
	public:
		Map();
		~Map();

		void init();
		void show();
		void OnMove();
		void OnHover(CPoint coords);
		int OnClick(CPoint coords);

		void setIsDay(bool val);
		bool getIsDay();

		void sunFactoryLogic();

	private:
		void removeSunFromVector(unsigned int index);

		int ZombiesKilled = 0;
		int sunsAmount = 50;
		bool isDay;
		GameBar bar;
	
		bool isSelectedPlant;
		PLANT plantsMap[9][5];	// the grid for the plants place on the map, not sure where to define this so I put it here first

		// GameMenu menu;
		// ProgressBar progress;
		// vector<Lane> lanes;
		vector<Zombie*> zombies;

		Cooldown sunProductionCooldown;
		vector<Sun*> displayedSuns;
	};

}