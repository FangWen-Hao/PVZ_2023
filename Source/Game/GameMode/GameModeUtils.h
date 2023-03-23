#include "GameMode.h"
#include "Main_Menu.h"
#include "Map.h"
#include "Almanac.h"
#include "LoadingScreen.h"

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
}