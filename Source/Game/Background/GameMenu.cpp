#include "stdafx.h"
#include "GameMenu.h"
#include "../config.h"

using namespace game_framework;

void GameMenu::Init()
{
	MenuBtn.LoadBitmapByString(MenuBtnBitmapsFilepaths);
	MenuBtn.SetTopLeft(RESOLUTION_X - MenuBtn.GetWidth(), RESOLUTION_Y - MenuBtn.GetHeight());

	dialogueBox.LoadBitmapByString({ dialogueBoxBitmapFilepath });
	dialogueBox.SetTopLeft((RESOLUTION_X / 2) - (dialogueBox.GetWidth() / 2), (RESOLUTION_Y / 2) - (dialogueBox.GetHeight() / 2));
	for (unsigned int i = 0; i < dialogueBoxBtnsBitmapsFilepaths.size(); i++)
	{
		dialogueBoxBtns.push_back(Button());
		dialogueBoxBtns.at(dialogueBoxBtns.size() - 1).init(dialogueBoxBtnsBitmapsFilepaths.at(i), dialogueBoxBtnsPosition.at(i).at(0), dialogueBoxBtnsPosition.at(i).at(1));

	}
}

void GameMenu::Show()
{
	MenuBtn.show();
	if (gameIsPaused)
	{
		dialogueBox.ShowBitmap();
		for (unsigned int i = 0; i < dialogueBoxBtns.size(); i++)
		{
			dialogueBoxBtns.at(i).show();
		}
	}
}

void GameMenu::onHover(CPoint point)
{
	if (point.x < (MenuBtn.GetLeft() + MenuBtn.GetWidth()) && point.x > MenuBtn.GetLeft()
		&& point.y < (MenuBtn.GetTop() + MenuBtn.GetHeight()) && point.y > MenuBtn.GetTop())
		MenuBtn.SetFrameIndexOfBitmap(1);

	else
		MenuBtn.SetFrameIndexOfBitmap(0);

	if (gameIsPaused)
	{
		for (unsigned int i = 0; i < dialogueBoxBtns.size(); i++)
		{
			if (point.x < (dialogueBoxBtns.at(i).GetLeft() + dialogueBoxBtns.at(i).GetWidth()) && point.x > dialogueBoxBtns.at(i).GetLeft()
				&& point.y < (dialogueBoxBtns.at(i).GetTop() + dialogueBoxBtns.at(i).GetHeight()) && point.y > dialogueBoxBtns.at(i).GetTop())
				dialogueBoxBtns.at(i).SetFrameIndexOfBitmap(1);
			else
				dialogueBoxBtns.at(i).SetFrameIndexOfBitmap(0);
		}
	}
}

int GameMenu::onClick(CPoint point, int currentLevelCode)
{
	if (point.x < (MenuBtn.GetLeft() + MenuBtn.GetWidth()) && point.x > MenuBtn.GetLeft()
		&& point.y < (MenuBtn.GetTop() + MenuBtn.GetHeight()) && point.y > MenuBtn.GetTop())
	{
		gameIsPaused = true;
		return MENU_NO_BTN_ACTION_ACCEPTED;
	}

	if (gameIsPaused)
	{
		for (unsigned int i = 0; i < dialogueBoxBtns.size(); i++)
		{
			if (point.x < (dialogueBoxBtns.at(i).GetLeft() + dialogueBoxBtns.at(i).GetWidth()) && point.x > dialogueBoxBtns.at(i).GetLeft()
				&& point.y < (dialogueBoxBtns.at(i).GetTop() + dialogueBoxBtns.at(i).GetHeight()) && point.y > dialogueBoxBtns.at(i).GetTop())
			{
				switch (i)
				{
				case 0: // previous level
					return currentLevelCode - 1;
					break;

				case 1: // restart level
					return currentLevelCode;
					break;

				case 2: // next level
					return currentLevelCode + 1;
					break;

				case 3: // return to menu
					return MENU_BTN;
					break;

				case 4: // return to game
					return MENU_NO_BTN_ACTION_ACCEPTED;
					break;

				default:
					break;
				}
			}
			
		}
	}

	return MENU_NO_BTN_ACTION_REJECTED;
}

bool GameMenu::getGameIsPaused()
{
	return gameIsPaused;
}