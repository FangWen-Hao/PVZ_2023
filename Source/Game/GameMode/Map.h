#pragma once
#include "GameMode.h"
#include "../Background/GameBar.h"
#include "../Plants/Plant.h"
#include "../Zombies/Zombie.h"
#include "../Misc/Sun.h"
#include "../Misc/Lawnmower.h"

using namespace std;
namespace game_framework {
	const string MAP_BG_DAY = "Resources/Background/GAME/DAY/BMP/Background.bmp";
	const string MAP_BG_NIGHT = "Resources/Background/GAME/NIGHT/BMP/Background.bmp";
	const string SHOVEL_CURSOR_BITMAP = "Resources/Misc/Shovel/BMP/Shovel1.bmp";

	const int SUN_PRODUCTION_COOLDOWN = 10;
	const unsigned int MAX_SUNS_FALLEN = 10;
	const int FALLING_SUN_INITIAL_POSITION = 50;
	
	class Map : public GameMode
	{
	public:
		Map(vector<vector<int>> zombiesSpawningInstructions);
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
		void collisionDetection(vector<Zombie*>*);
		CPoint _mousePos2TilePos(CPoint);
		void UpdateBulletsState();
		void UpdateZombiesState();
		void UpdatePlantsState();
		void CreateZombieOnInstruction();
		Zombie* zombieFactory();
		void AddSunOnClick(CPoint &coords);
		void CreatePlantOnClick(const CPoint &coords);
		void UpdateLawnmowers();

		void CreateZombieOnInstruction();
		void UpdatePlantsState();
		void UpdateZombiesState();
		void UpdateBulletsState();

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
		vector<vector<int>> zombiesSpawningInstructions;
		vector<vector<Plant*>> plants;
		vector<Bullet*> bullets;
		vector<Lawnmower*> lawnmowers;

		CMovingBitmap shovelCursor;
		Plant* currentSelectPlant = nullptr;
		SEED_CARD_TYPE currentSelectedSeedCard = REFUSED;
	};
}