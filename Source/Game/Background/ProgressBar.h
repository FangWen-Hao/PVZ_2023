#pragma once
#include "../../Library/gameutil.h"
#include <vector>

using namespace std;
namespace game_framework {

	// logic to add for waves:
	// bitmap needed: waves flag (2 bit maps: 1 in lower pos, 1 in higher pos)
	// 101 bitmaps of the progress bar's inner thingy (0 to 100)
	// 
	// idea: 
	// give the progress bar a vector of int of how many zombies before a chkpoint.
	// in the map function to count the numb of zombies, returns a vector of int:
	//	logic remains the same but when it encounters a wave checkpoint instruction, you add the count to the vecctor
	//	do NOT reset the count upon doing that.
	//
	// for counting progress: .
	// for int in vector:
	//	if zombie killed > value at pos: setBitmapIndexOfFlag(1)
	//	if zombies killed =< value at pos:
	//		progress = "zombies killed / value at that pos * (pos + 1) / size of vector" 
	//		break;
	// update progress [set frame index (progress)].
	// 
	// for flag thingies:
	// make a vector of bitmaps, and create a flag bitmap the size of the total zombies vector size.
	// init with the coloref for transparent
	// set their pos as: right (left + width) - (width * ( pos + 1) / size of vector), some padding you gotta find out
	// set their frame to 0
	// remember to show all of them in on:show
	// the progress bar is also simple: just set its left top the same as the progress bar + padding
	// remember that its only 1 bitmap for the progress bar

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