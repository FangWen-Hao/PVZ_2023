#pragma once
#include "GameMode.h"
#include "../Background/GameBar.h"
#include "../Background/GameMenu.h"
#include "../Background/ProgressBar.h"
#include "../Background/GameOver.h"
#include "../Plants/Plant.h"
#include "../Zombies/Zombie.h"
#include "../Misc/Sun.h"
#include "../Misc/Lawnmower.h"

using namespace std;
namespace game_framework {
	const string MAP_BG_DAY = "Resources/Background/GAME/DAY/BMP/Background.bmp";
	const string MAP_BG_NIGHT = "Resources/Background/GAME/NIGHT/BMP/Background.bmp";
	const string SHOVEL_CURSOR_BITMAP = "Resources/Misc/Shovel/BMP/Shovel1.bmp";
	const string NOTE_BITMAP = "Resources/Background/Level Up/BMP/note.bmp";
	
	class Map : public GameMode
	{
	public:
		Map(vector<vector<int>> zombiesSpawningInstructions,
			string messageBitmap,
			bool isDay,
			double sunProductionCooldownVal = 10,
			unsigned int maxSunsFallen = 10,
			int startingSunHeight = 50,
			int sunsAmount = 50);

		virtual ~Map();

		virtual void init();
		virtual void show();
		virtual void OnMove();
		virtual void OnKeyUp(UINT);
		virtual void OnHover(CPoint);
		virtual int OnLClick(CPoint);
		virtual int OnRClick(CPoint);

		virtual void setIsDay(bool val);
		virtual bool getIsDay() { return isDay; }

	protected:
		// Constructor helper methods
		virtual void SetUpGameBoard();

		// Destructor helper methods
		virtual void DeleteEntities();

		// Init helper methods
		virtual void InitUI();
		virtual void InitGameBoard();

		// Show helper methods
		virtual void ShowEntities();
		virtual void ShowUI();

		// OnHover helper methods
		virtual void OnHoverCursor(CPoint &coords);

		// OnMove helper methods
		virtual void sunFactoryLogic();
		virtual void CreateZombieOnInstruction();
		virtual void collisionDetection(vector<Zombie*>*);
		virtual void UpdatePlantsState();
		virtual void UpdateZombiesState();
		virtual void UpdateBulletsState();
		virtual void UpdateLawnmowers();

		// OnClick helper methods
		virtual void AddSunOnClick(CPoint &coords);
		virtual void CreatePlantOnClick(const CPoint &coords);

		// Helpers Helper methods
		virtual Zombie* zombieFactory();
		virtual CPoint _mousePos2TilePos(CPoint);
		virtual int countTotalZombies();
		

		// inheritance
		double sunProductionCooldownVal; //default is 10; this changes by map
		unsigned int maxSunsFallen; //default is 10; this changes
		int startingSunHeight; // default is  50; this changes
		int startingSunsAmmount; //default is 50;
		bool isDay; // default is true

		// forced inheritance
		virtual int getPreviousLevel() = 0;
		virtual int getCurrentLevel() = 0;
		virtual int getNextLevel() = 0;
		
		
		// Game Logic attributes
		Cooldown sunProductionCooldown;
		// vector<Lane> lanes;
		vector<Sun*> displayedSuns; //delets
		vector<Zombie*> zombies; // deletes
		vector<vector<int>> zombiesSpawningInstructions; // this changes
		vector<vector<Plant*>> plants; // nullptr
		vector<Bullet*> bullets; // delete
		vector<Lawnmower*> lawnmowers; // nullptr

		CMovingBitmap note;
		Background endGameMsg;
		bool noteWasClicked = false;
		bool noteSpawned = false;

		// cheats
		int cheatChangeLvl = MENU_NO_BTN_ACTION_REJECTED;
		Cooldown cheatChangeLvlTimer;
		const double CHEAT_CHANGE_LVL_TIMER_DURATION = 3;
		bool spawnNoteCheat = false;

		// UI Elements attributes
		GameBar bar;
		GameMenu menu;
		ProgressBar progress;
		GameOver gameOver;
		CMovingBitmap shovelCursor;
		Plant* currentSelectPlant = nullptr;
		SEED_CARD_TYPE currentSelectedSeedCard = REFUSED;
	};
}