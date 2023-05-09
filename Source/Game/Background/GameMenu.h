#pragma once
#include "../Background/CheckBox.h"
#include "../Background/Button.h"
#include "../../Library/gameutil.h"
#include <atltypes.h>
#include <vector>

using namespace std;
namespace game_framework
{
	const vector<string> MENU_CALLER_BTN_BITMAPS{
		"Resources/In Game Menu/BMP/menu0.bmp", "Resources/In Game Menu/BMP/menu1.bmp"
	};

	const vector<string> CHKBOX_BITMAPS{
		"Resources/In Game Menu/BMP/checkbox0.bmp",
		"Resources/In Game Menu/BMP/checkbox1.bmp"
	};

	const vector<string> BACK_TO_GAME_BTN_BITMAPS{
		"Resources/In Game Menu/BMP/backToGame0.bmp",
		"Resources/In Game Menu/BMP/backToGame1.bmp"
	};

	const vector<string> MAIN_MENU_BTN_BITMAPS{
		"Resources/In Game Menu/BMP/mainMenu0.bmp",
		"Resources/In Game Menu/BMP/mainMenu1.bmp"
	};

	const vector<string> RESTART_LEVEL_BTN_BITMAPS{
		"Resources/In Game Menu/BMP/restartLevel0.bmp",
		"Resources/In Game Menu/BMP/restartLevel1.bmp"
	};

	const string GAME_MENU_BACKGROUND_BITMAP = "Resources/In Game Menu/BMP/wholeMenuEmpty.bmp";

	class GameMenu
	{
	public:
		GameMenu() {};
		~GameMenu() {};

		void init();
		void show();
		void onHover(CPoint coords);
		int onClick(CPoint coords, int currentLevel);

		bool getIsGamePaused();

		static void setIsMusicOn(bool val) { isMusicOn = val; }
		static void setIsSoundFXOn(bool val) { isSoundFXOn = val; }

		static bool getIsMusicOn() { return isMusicOn; }
		static bool getIsSoundFXOn() { return isSoundFXOn; }

	private:
		static bool isMusicOn;
		static bool isSoundFXOn;
		bool isGamePaused = false;

		CMovingBitmap background;
		Button menuCallerBtn;
		CheckBox musicChkBox;
		CheckBox soundFXChkBox;
		Button restartLvlBtn;
		Button mainMenuBtn;
		Button backToGameBtn;
		
	};
}