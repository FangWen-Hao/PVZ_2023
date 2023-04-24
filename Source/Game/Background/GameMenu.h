#pragma once
#include "Button.h"
#include "../GameMode/GameMode.h"
#include <vector>
#include <string>
#include <atltypes.h>

using namespace std;

namespace game_framework
{
	class GameMenu
	{
	public:
		void Init();
		void Show();

		void onHover(CPoint point);
		int onClick(CPoint point, int currentLevelCode); // this will return either go back 1 level, go forward 1 level, or go back to the main menu. This will be used in conjunction with the enum in GameMode.h

		bool getGameIsPaused();

	private:
		const vector<string> MenuBtnBitmapsFilepaths {
			"",
			""
		};

		const string dialogueBoxBitmapFilepath = "";

		const vector<vector<string>> dialogueBoxBtnsBitmapsFilepaths {
			{"", ""},
			{"", ""},
		};

		const vector<vector<int>> dialogueBoxBtnsPosition{
		// {x, y},
			
		};

		bool gameIsPaused;
		Button MenuBtn;
		CMovingBitmap dialogueBox;

		vector<Button> dialogueBoxBtns;
	};
}
