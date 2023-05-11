#pragma once;
#include "Background.h"
#include "../Utils/GameModeConsts.h"
#include <vector>

using namespace std;
namespace game_framework
{
	const string gameOverBitmap = "Resources/Background/GAME OVER/gameOver.bmp";

	class GameOver
	{
	public:
		GameOver() {};
		~GameOver() {};

		void init();
		void show();
		void triggerGameOver();
		int onClick(int currentLevel);

		bool getIsGameOver() { return isGameOver; }

	private:
		Background gameOverBg;
		bool isGameOver;
	};
}