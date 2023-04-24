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
	const int FALLING_SUN_INITIAL_POSITION = 50;

	// temporary put it here: do we want to migrate these 2 const?

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
		void removeSunFromVector(Sun*);
		void collisionDetection(vector<Zombie*>*, vector<Plant*>*);
		CPoint _mousePos2TilePos(CPoint);

		int ZombiesKilled = 0;
		int sunsAmount = 50;
		bool isDay;
		GameBar bar;

		// GameMenu menu;
		// ProgressBar progress;
		// vector<Lane> lanes;
		Cooldown sunProductionCooldown;

		vector<Sun*> displayedSuns;
		vector<Zombie*> zombies;
		vector<Plant*> plants;
		vector<Bullet*> bullets;

		Plant* currentSelectPlant = nullptr;
		PLANT plantsMap[5][9];
	};

}