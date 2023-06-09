#pragma once
#include "../../Library/gameutil.h"
#include <vector>

using namespace std;
namespace game_framework {

	const int PADDING = 20;

	const vector<string> PROGRESS_BAR_BITMAPS {
		"Resources/Misc/Progress Bar/progress0.bmp",
		"Resources/Misc/Progress Bar/progress1.bmp",
		"Resources/Misc/Progress Bar/progress2.bmp",
		"Resources/Misc/Progress Bar/progress3.bmp",
		"Resources/Misc/Progress Bar/progress4.bmp",
		"Resources/Misc/Progress Bar/progress5.bmp",
		"Resources/Misc/Progress Bar/progress6.bmp",
		"Resources/Misc/Progress Bar/progress7.bmp",
		"Resources/Misc/Progress Bar/progress8.bmp",
		"Resources/Misc/Progress Bar/progress9.bmp",
		"Resources/Misc/Progress Bar/progress10.bmp",
	};

	const int PROGRESS_BAR_STATES = PROGRESS_BAR_BITMAPS.size();

	class ProgressBar
	{
	public:
		ProgressBar();
		~ProgressBar();

		void init(int totalZombies);
		void show(int currentLevel);
		void updateCount();
		bool isGameComplete();

		void setTotalZombies(int count) { totalZombies = count; }
		void setZombiesKilled(int count) { zombiesKilled = count; }

		int getTotalZombies() { return totalZombies; }
		int getZombiesKilled() { return zombiesKilled; }
		int getRemainingZombies() { return totalZombies - zombiesKilled; }

	private:
		void drawCurrentLevel(int currentLevel);
		string getCurrentLevelMsg(int currentLevel);

		CMovingBitmap image;

		int totalZombies;
		int zombiesKilled = 0;
	};

	

}