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

	const vector<string> PREVIOUS_LEVEL_BTN_BITMAPS{
		"Resources/In Game Menu/BMP/previousLevel.bmp",
	};

	const vector<string> NEXT_LEVEL_BTN_BITMAPS{ 
		"Resources/In Game Menu/BMP/nextLevel.bmp",

	};

	const string GAME_MENU_BACKGROUND_BITMAP = "Resources/In Game Menu/BMP/wholeMenuEmpty.bmp";

	const int GAME_MENU_BTNS_PADDING = 43;

	class GameMenu
	{
	public:
		GameMenu() {};
		~GameMenu() {};

		void init(int previousLevel, int currentLevel, int nextLevel);
		void show();
		void onHover(CPoint coords);
		int onClick(CPoint coords);

		bool getIsGamePaused();

	private:
		bool isGamePaused = false;
		int previousLevel;
		int currentLevel;
		int nextLevel;

		CMovingBitmap background;
		Button menuCallerBtn;
		CheckBox musicChkBox;
		CheckBox soundFXChkBox;
		Button previousLvlBtn;
		Button nextLvlBtn;
		Button restartLvlBtn;
		Button mainMenuBtn;
		Button backToGameBtn;
		
	};
}