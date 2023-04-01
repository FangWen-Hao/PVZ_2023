#include "GameMode.h"
#include "Main_Menu.h"
#include "Map.h"
#include "Almanac.h"
#include "LoadingScreen.h"
#include "../Misc/Cooldown.h"

using namespace std;
namespace game_framework {
	
	static void changeGameMode(GameMode *&GameModePtr, int newGameMode)
	{
		if (newGameMode == MENU_NO_BTN_ACTION_REJECTED
			|| newGameMode == MENU_NO_BTN_ACTION_ACCEPTED)
			return;

		delete GameModePtr;
		switch (newGameMode)
		{
		case ADVENTURE_MODE_BTN:
			GameModePtr = new Map();
			break;

		case ALMANAC_BTN:
			GameModePtr = new Almanac();
			break;

		case MENU_BTN:
			GameModePtr = new MainMenu();
			break;

		case LOADING:
			GameModePtr = new LoadingScreen();
			break;

		default:
			break;
		}


		GameModePtr->init();
		GameModePtr->show();
	}

	static int integerPRNG(int min, int max)
	{
		// https://www.geeksforgeeks.org/pseudo-random-number-generator-prng/
		srand(Cooldown::getGameClockForPRNGSeed()); // we use the game clock instead of calling "time(NULL)".

		// https://cplusplus.com/reference/cstdlib/rand/
		return (rand() % max + min);
	}
}

