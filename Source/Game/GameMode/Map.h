#pragma once
#include "GameMode.h"
#include "../Background/GameBar.h"
#include "../Background/ProgressBar.h"
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
		bool getIsDay() { return isDay; }

	private:
		// Constructor helper methods
		void SetUpGameBoard();

		// Destructor helper methods
		void DeleteEntities();

		// Init helper methods
		void InitUI();
		void InitGameBoard();

		// Show helper methods
		void ShowEntities();
		void ShowUI();

		// OnHover helper methods
		void OnHoverCursor(CPoint &coords);

		// OnMove helper methods
		void sunFactoryLogic();
		void CreateZombieOnInstruction();
		void collisionDetection(vector<Zombie*>*);
		void UpdatePlantsState();
		void UpdateZombiesState();
		void UpdateBulletsState();
		void UpdateLawnmowers();

		// OnClick helper methods
		void AddSunOnClick(CPoint &coords);
		void CreatePlantOnClick(const CPoint &coords);

		// Helpers Helper methods
		Zombie* zombieFactory();
		CPoint _mousePos2TilePos(CPoint);
		void removeSunFromVector(Sun*);
		int countTotalZombies();
		
		// Stats attributes
		int ZombiesKilled = 0;
		int sunsAmount = 50;
		bool isDay;
		
		// Game Logic attributes
		Cooldown sunProductionCooldown;
		// vector<Lane> lanes;
		vector<Sun*> displayedSuns;
		vector<Zombie*> zombies;
		vector<vector<int>> zombiesSpawningInstructions;
		vector<vector<Plant*>> plants;
		vector<Bullet*> bullets;
		vector<Lawnmower*> lawnmowers;

		// UI Elements attributes
		GameBar bar;
		// GameMenu menu;
		ProgressBar progress;
		CMovingBitmap shovelCursor;
		Plant* currentSelectPlant = nullptr;
		SEED_CARD_TYPE currentSelectedSeedCard = REFUSED;
	};
}