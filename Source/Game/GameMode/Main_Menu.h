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
		void OnHover(CPoint coords);
		int OnLClick(CPoint coords);
		int OnRClick(CPoint coords);

	protected:

	private:
		const string MENU_BITMAP_FILEPATH = "Resources/Background/MAIN MENU/BMP/MainMenu.bmp";
		const vector<vector<vector<string>>> MENU_BUTTONS_BITMAP_FILEPATH {
			// { {Filepaths name}, {offsetX, offsetY} }
			{ {"Resources/Misc/Buttons/Start/BMP/Adventure0.bmp", "Resources/Misc/Buttons/Start/BMP/Adventure1.bmp"}, {"382", "69" } },
			{ {"Resources/Almanac/BMP/almanac.bmp", "Resources/Almanac/BMP/almanac.bmp"}, {"327", "426" } }
		};

		vector<Button> MenuButtons;
	};
}