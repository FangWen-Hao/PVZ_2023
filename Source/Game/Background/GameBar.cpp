#include "stdafx.h"
#include "SeedCard.h"
#include "CardPicker.h"
#include "Button.h"
#include "../../Library/gameutil.h"

// Includes for gamecore.h
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../../Library/gamecore.h"

#include <string>
#include <afxwin.h>
#include "GameBar.h"

namespace game_framework
{
	GameBar::GameBar()
	{
	}
	GameBar::~GameBar()
	{
	}

	void GameBar::init(int initialSuns)
	{
		_suns = initialSuns;
		background.LoadBitmapByString({BACKGROUND_BMP_FILEPATH});
		background.SetTopLeft(0, 0);

		picker.init();

		// initialize the startGameButton.
		startGameButton.init(START_GAME_BMP_FILEPATH, background.GetWidth() + 5, 0);
		startGameButton.SetFrameIndexOfBitmap(2);

	}

	void GameBar::show()
	{
		background.ShowBitmap();
		drawSun();

		// if the game is not started, show the card picker
		if (!gameStarted) {
			picker.show();
			startGameButton.show();
		} else { // else show the selected cards on the bar

			// the below for loop should be wrapped into a function;
			for (unsigned int i = 0; i < cards.size(); i++)
			{
				cards.at(i).SetTopLeft(80 + i*55, 10);	// set the card position to the bar
				cards.at(i).show();						// show the card.
			}
		}
	}

	void GameBar::onHover(CPoint coords)
	{
		if (!gameStarted)
		{
			//if (cards.size() == _maxNumberOfCards
			if (cards.size() > 0
				&& coords.x < (startGameButton.GetLeft() + startGameButton.GetWidth()) && coords.x > startGameButton.GetLeft()
				&& coords.y < (startGameButton.GetTop() + startGameButton.GetHeight()) && coords.y > startGameButton.GetTop())
			{
				startGameButton.SetFrameIndexOfBitmap(2);
			}
			else
			{
				startGameButton.SetFrameIndexOfBitmap(1);
			}
		}
	}


	int GameBar::onClick(CPoint coords)
	{
		// WIP
		if (!gameStarted)
		{
			// if (cards.size() == _maxNumberOfCards
			if (cards.size() > 0
				&& coords.x < (startGameButton.GetLeft() + startGameButton.GetWidth()) && coords.x > startGameButton.GetLeft()
				&& coords.y < (startGameButton.GetTop() + startGameButton.GetHeight()) && coords.y > startGameButton.GetTop())
			{
				gameStarted = true;
				background.UnshowBitmap();
				picker.unshow();
				startGameButton.UnshowBitmap();
			}

			if (coords.x < (picker.GetLeft() + picker.GetWidth()) && coords.x > picker.GetLeft()
				&& coords.y < (picker.GetTop() + picker.GetHeight()) && coords.y > picker.GetTop())
			{
				SeedCard* card = picker.OnClick(coords);

				if (card != nullptr)
					addCard(card);
			}
		}

		return 0;
	}

	void GameBar::addSuns(int suns)
	{
		_suns += suns;
	}

	void GameBar::setSuns(int suns)
	{
		_suns = suns;
	}

	int GameBar::getSuns(void)
	{
		return _suns;
	}

	void GameBar::drawSun()
	{
		CDC *pDC = CDDraw::GetBackCDC();

		/* Print title */
		CTextDraw::ChangeFontLog(pDC, 20, "微軟正黑體", RGB(0, 0, 0), 800);
		CTextDraw::Print(pDC, 25, 61, to_string(_suns));

		CDDraw::ReleaseBackCDC();
	}
	void GameBar::addCard(SeedCard * card)
	{
		cards.push_back(*card);
	}
}