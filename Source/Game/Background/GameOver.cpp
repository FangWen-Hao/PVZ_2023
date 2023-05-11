#include "stdafx.h"
#include "GameOver.h"

using namespace game_framework;

void GameOver::init()
{
	gameOverBg.init({ gameOverBitmap });
	isGameOver = false;
}

void GameOver::show()
{
	if (isGameOver)
		gameOverBg.show();
}

void GameOver::triggerGameOver()
{
	isGameOver = true;
}

int GameOver::onClick(int currentLevel)
{
	if (isGameOver)
		return currentLevel;

	return MENU_NO_BTN_ACTION_ACCEPTED;
}
