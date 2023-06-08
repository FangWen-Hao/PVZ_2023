#pragma once
#include "../GameMode/GameMode.h"
#include "GameModeConsts.h"
#include "../GameMode/Main_Menu.h"
#include "../GameMode/Map.h"
#include "../GameMode/Maps/MapsDependencies.h"
#include "../GameMode/AboutUs.h"
#include "../GameMode/LoadingScreen.h"
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
		case LEVEL_1:
			GameModePtr = new Level1();
			break;

		case LEVEL_2:
			GameModePtr = new Level2();
			break;

		case LEVEL_3:
			GameModePtr = new Level3();
			break;

		case LEVEL_4:
			GameModePtr = new Level4();
			break;

		case LEVEL_5:
			GameModePtr = new Level5();
			break;

		case ABOUT_US:
			GameModePtr = new AboutUs();
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

