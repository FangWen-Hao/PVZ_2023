#pragma once
#include "stdafx.h"
#include <vector>
#include "../../Library/gameutil.h"
#include "../Background/Button.h"
#include "Main_Menu.h"
#include "../Utils/GameModeConsts.h"
#include "../Utils/Soundboard.h"

// Includes for gamecore.h
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../../Library/gamecore.h"
#include "../config.h"

using namespace game_framework;

MainMenu::MainMenu() : GameMode()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
	background.init(MENU_BITMAP_FILEPATH);
	for (unsigned int i = 0; i < MENU_BUTTONS_BITMAP_FILEPATH.size(); i++)
	{
		MenuButtons.push_back(Button());
		MenuButtons.at(i).init(MENU_BUTTONS_BITMAP_FILEPATH.at(i).at(0),
						        MENU_BUTTONS_BITMAP_FILEPATH.at(i).at(1).at(0),
						        MENU_BUTTONS_BITMAP_FILEPATH.at(i).at(1).at(1));
	}

	if (!SoundBoard::isSoundBeingPlayed(soundID::MAIN_MENU))
		SoundBoard::playMusic(soundID::MAIN_MENU, true);
}

void MainMenu::show()
{
	background.show();
	for (unsigned int i = 0; i < MenuButtons.size(); i++)
	{
		MenuButtons.at(i).show();
	}

	drawCheatSheet();
}

void MainMenu::OnMove()
{
	// runtime function of the main menu.
	// implemented due to GameMode.h defining it and the usage in mygame_run
	// however I don't think we need to do anything for main menu.cpp, do we?
}

void MainMenu::OnKeyUp(UINT nChar)
{
}

void MainMenu::OnHover(CPoint coords)
{
	for (unsigned int i = 0; i < MenuButtons.size(); i++)
	{
		if (coords.x < (MenuButtons.at(i).GetLeft() + MenuButtons.at(i).GetWidth()) && coords.x > MenuButtons.at(i).GetLeft()
			&& coords.y < (MenuButtons.at(i).GetTop() + MenuButtons.at(i).GetHeight()) && coords.y > MenuButtons.at(i).GetTop()
			&& !MenuButtons.at(i).IsAnimation())
		{
			MenuButtons.at(i).SetFrameIndexOfBitmap(1);
			return;
		}

		MenuButtons.at(i).SetFrameIndexOfBitmap(0);
		// 16
	}
}

int MainMenu::OnLClick(CPoint coords)
{
	for (unsigned int i = 0; i < MenuButtons.size(); i++)
	{
		if (coords.x < (MenuButtons.at(i).GetLeft() + MenuButtons.at(i).GetWidth()) && coords.x > MenuButtons.at(i).GetLeft()
			&& coords.y < (MenuButtons.at(i).GetTop() + MenuButtons.at(i).GetHeight()) && coords.y > MenuButtons.at(i).GetTop()
			&& !MenuButtons.at(i).IsAnimation())
		{
			MenuButtons.at(i).SetFrameIndexOfBitmap(1);

			return (i + 1);
		}
	}

	return MENU_NO_BTN_ACTION_REJECTED;
}

int MainMenu::OnRClick(CPoint coords)
{
	return 0;
}

void MainMenu::drawCheatSheet()
{
	CDC *pDC = CDDraw::GetBackCDC();

	const int size = 16;
	const int xPos = 5;
	const int yPadding = 20;
	int yPos = 5;
	double descriptionXpos;

	for (unsigned int i = 0; i < CHEAT_MSGS.size(); i++)
	{
		vector<string> msg = CHEAT_MSGS.at(i);
		string key = msg.at(0);
		CTextDraw::ChangeFontLog(pDC, size, "微軟正黑體", RGB(255, 255, 255)); // text 
		CTextDraw::Print(pDC, xPos, yPos, key);

		if (msg.at(1).length() == 0)
		{
			yPos += yPadding;
			continue;
		}

		string description = "  : " + msg.at(1);
		descriptionXpos = xPos + (key.length() * size / 2);
		CTextDraw::ChangeFontLog(pDC, size, "微軟正黑體", RGB(0, 0, 0)); // text 
		CTextDraw::Print(pDC, (int)descriptionXpos, yPos, description);

		yPos += yPadding;
	}

	CDDraw::ReleaseBackCDC();
}
