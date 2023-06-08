#pragma once 
#include "../Background/Button.h"
#include "GameMode.h"


using namespace std;
namespace game_framework{
	const int ADVENTURE_BUTTON_REPETITIONS = 16;

	class MainMenu : public GameMode {
	public:
		MainMenu();
		~MainMenu();
		void init();
		void show();
		void OnMove();
		void OnKeyUp(UINT);
		void OnHover(CPoint);
		int OnLClick(CPoint);
		int OnRClick(CPoint);

	protected:

	private:
		const string MENU_BITMAP_FILEPATH = "Resources/Background/MAIN MENU/BMP/MainMenu.bmp";
		const vector<vector<vector<string>>> MENU_BUTTONS_BITMAP_FILEPATH {
			// { {Filepaths name}, {offsetX, offsetY} }
			{ {"Resources/Misc/Buttons/Start/BMP/Adventure0.bmp", "Resources/Misc/Buttons/Start/BMP/Adventure1.bmp"}, {"382", "69" } },
			{ {"Resources/About us/aboutUsButton.bmp", "Resources/About us/aboutUsButton.bmp"}, {"327", "426" } }
		};

		const vector<string> CHEAT_MSGS {
			"List of cheat codes",
			"Q + Left Click: Go to the previous level",
			"W : Add 500 suns",
			"E + Left Click: Go to the next level",
			"A : Zombies move twice as fast",
			"S : Zombies move normally",
			"D : Zombies move half as fast",
			"Z : Reset all the cooldowns for planting plants",
			"X : Kill all zombies on screen and drop the note",
			"C : Kill all zombies on screen",
		};

		void drawCheatSheet();

		vector<Button> MenuButtons;
	};
}