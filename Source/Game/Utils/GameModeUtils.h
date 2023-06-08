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
	
	static void stopSongForAdventureMode()
	{
		if (SoundBoard::isSoundBeingPlayed(soundID::TITLE_SCREEN))
			SoundBoard::stopSound(soundID::TITLE_SCREEN);

		if (SoundBoard::isSoundBeingPlayed(soundID::MAIN_MENU))
			SoundBoard::stopSound(soundID::MAIN_MENU);

		if (SoundBoard::isSoundBeingPlayed(soundID::DAY_MAP))
			SoundBoard::stopSound(soundID::DAY_MAP);

		if (SoundBoard::isSoundBeingPlayed(soundID::NIGHT_MAP))
			SoundBoard::stopSound(soundID::NIGHT_MAP);

		if (SoundBoard::isSoundBeingPlayed(soundID::ON_NOTE_UI))
			SoundBoard::stopSound(soundID::ON_NOTE_UI);

	}

	static void stopSongForMainMenu()
	{
		if (SoundBoard::isSoundBeingPlayed(soundID::TITLE_SCREEN))
			SoundBoard::stopSound(soundID::TITLE_SCREEN);

		if (SoundBoard::isSoundBeingPlayed(soundID::CHOOSE_YOUR_SEEDS))
			SoundBoard::stopSound(soundID::CHOOSE_YOUR_SEEDS);

		if (SoundBoard::isSoundBeingPlayed(soundID::DAY_MAP))
			SoundBoard::stopSound(soundID::DAY_MAP);

		if (SoundBoard::isSoundBeingPlayed(soundID::NIGHT_MAP))
			SoundBoard::stopSound(soundID::NIGHT_MAP);

		if (SoundBoard::isSoundBeingPlayed(soundID::ON_NOTE_UI))
			SoundBoard::stopSound(soundID::ON_NOTE_UI);

		if (!SoundBoard::isSoundBeingPlayed(soundID::MAIN_MENU))
			SoundBoard::playMusic(soundID::MAIN_MENU, true);
	}

	static void changeGameMode(GameMode **GameModePtr, int newGameMode)
	{
		if (newGameMode == MENU_NO_BTN_ACTION_REJECTED
			|| newGameMode == MENU_NO_BTN_ACTION_ACCEPTED)
			return;

		GameMode *oldGameMode = (*GameModePtr);

		switch (newGameMode)
		{
		case ADVENTURE_MODE_BTN:
		case LEVEL_1:
			stopSongForAdventureMode();
			(*GameModePtr) = new Level1();
			break;

		case LEVEL_2:
			stopSongForAdventureMode();
			(*GameModePtr) = new Level2();
			break;

		case LEVEL_3:
			stopSongForAdventureMode();
			(*GameModePtr) = new Level3();
			break;

		case LEVEL_4:
			stopSongForAdventureMode();
			(*GameModePtr) = new Level4();
			break;

		case LEVEL_5:
			stopSongForAdventureMode();
			(*GameModePtr) = new Level5();
			break;

		case LEVEL_6:
			GameModePtr = new Level6();
			break;

		case LEVEL_7:
			GameModePtr = new Level7();
			break;

		case LEVEL_8:
			GameModePtr = new Level8();
			break;

		case LEVEL_9:
			GameModePtr = new Level9();
			break;

		case LEVEL_10:
			GameModePtr = new Level10();
			break;

		case ABOUT_US:
			stopSongForMainMenu();
			(*GameModePtr) = new AboutUs();
			break;

		case MENU_BTN:
			stopSongForMainMenu();
			(*GameModePtr) = new MainMenu();
			break;

		case LOADING:
			stopSongForMainMenu();
			(*GameModePtr) = new LoadingScreen();
			break;

		default:
			break;
		}


		(*GameModePtr)->init();
		(*GameModePtr)->show();

		delete oldGameMode;
	}

	static int integerPRNG(int min, int max)
	{
		// https://www.geeksforgeeks.org/pseudo-random-number-generator-prng/
		srand(Cooldown::getGameClockForPRNGSeed()); // we use the game clock instead of calling "time(NULL)".

		// https://cplusplus.com/reference/cstdlib/rand/
		return (rand() % max + min);
	}
}

