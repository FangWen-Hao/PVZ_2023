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
		background.LoadBitmapByString({BACKGROUND_BMP_FILEPATH}, RGB(255, 255, 255));
		background.SetTopLeft(0, 0);

		picker.init();

		// initialize the startGameButton.
		startGameButton.init(START_GAME_BMP_FILEPATH, 0, 0);
		startGameButton.SetTopLeft(picker.GetLeft() + ((picker.GetWidth() - startGameButton.GetWidth()) / 2), picker.GetTop() + picker.GetHeight() - startGameButton.GetHeight() - 20); // 20 because of padding from bottom
		shovelButton.init({ SHOVEL_BUTTON_FILEPATH }, background.GetWidth() + 5, 0);
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
			shovelButton.show();
			setSelectedCards();
		}
	}

	void GameBar::move()
	{
		updateCardsFrames();
	}

	void GameBar::onHover(CPoint coords)
	{
		if (!gameStarted)
		{
			//if (cards.size() == _maxNumberOfCards
			if (_selectedCards >= _maxNumberOfCards)
			{
				if (coords.x < (startGameButton.GetLeft() + startGameButton.GetWidth()) && coords.x > startGameButton.GetLeft()
					&& coords.y < (startGameButton.GetTop() + startGameButton.GetHeight()) && coords.y > startGameButton.GetTop())
					startGameButton.SetFrameIndexOfBitmap(1);

				else
					startGameButton.SetFrameIndexOfBitmap(0);
			}
			
		}
	}


	SEED_CARD_TYPE GameBar::onClick(CPoint coords)
	{
		// WIP
		if (!gameStarted)
		{
			if (_selectedCards >= _maxNumberOfCards
				&& coords.x < (startGameButton.GetLeft() + startGameButton.GetWidth()) && coords.x > startGameButton.GetLeft()
				&& coords.y < (startGameButton.GetTop() + startGameButton.GetHeight()) && coords.y > startGameButton.GetTop())
			{
				gameStarted = true;
				gameStartedTime = high_resolution_clock::now();
				background.UnshowBitmap();
				picker.unshow();
				startGameButton.UnshowBitmap();
				// updateCardsFrames();
				return SEED_CARD_TYPE::REFUSED; // tmp
			}

			if (coords.x < (picker.GetLeft() + picker.GetWidth()) && coords.x > picker.GetLeft()
				&& coords.y < (picker.GetTop() + picker.GetHeight()) && coords.y > picker.GetTop())
			{
				SeedCard* card = picker.OnClick(coords);

				if (card != nullptr)
				{
					bool cardIsAlreadySelected = checkIfCardIsAlreadySelected(card);
					if (_selectedCards >= _maxNumberOfCards && !cardIsAlreadySelected)
						// if the user already selected the max number of cards
						// and the card they clicked wasnt previously selected, then invalidate the click.
						card->resetCardPos();

					else
					{
						if (checkIfCardIsAlreadySelected(card))
							removeCard(card);

						else
							addCard(card);


						if (_selectedCards >= _maxNumberOfCards)
							startGameButton.SetFrameIndexOfBitmap(0);

						else
							startGameButton.SetFrameIndexOfBitmap(2);
					}
					
				}
					
			}
		}
		else
		{
			if (coords.x < (shovelButton.GetLeft() + shovelButton.GetWidth()) && coords.x > shovelButton.GetLeft()
				&& coords.y < (shovelButton.GetTop() + shovelButton.GetHeight()) && coords.y > shovelButton.GetTop())
			{
				shovelButton.clicked();
				return SEED_CARD_TYPE::SHOVEL;
			}

			// the shovel wasn't touched, so reset the bitmap if needed
			if (shovelButton.GetFrameIndexOfBitmap() != 0)
			{
				shovelButton.SetFrameIndexOfBitmap(0);
			}

			for (SeedCard card : cards)
			{
				if (coords.x < (card.GetLeft() + card.GetWidth()) && coords.x > card.GetLeft()
					&& coords.y < (card.GetTop() + card.GetHeight()) && coords.y > card.GetTop()
					&& (!card.isOnCooldown()))
				{
					return card.getType();
				}
			}
		}
		return SEED_CARD_TYPE::REFUSED;
	}

	void GameBar::setSeedCardCooldown(SEED_CARD_TYPE cardType)
	{
		for (unsigned int i = 0; i < cards.size(); i++)
		{
			if (cards.at(i).getType() == cardType)
			{
				cards.at(i).used();
				return;
			}
		}
	}

	void GameBar::addSuns(int suns)
	{
		_suns += suns;
		// updateCardsFrames();
	}

	void GameBar::setSuns(int suns)
	{
		_suns = suns;
		// updateCardsFrames();
	}

	int GameBar::getSuns(void)
	{
		return _suns;
	}

	bool GameBar::hasGameStarted(void)
	{
		return gameStarted;
	}

	high_resolution_clock::time_point GameBar::getGameStartedTime()
	{
		return gameStartedTime;
	}

	void GameBar::drawSun()
	{
		CDC *pDC = CDDraw::GetBackCDC();

		const int sunBarRight = background.GetLeft() + 39; // this is just try and luck finding
		int size = 20;
		string msg = to_string(_suns);

		
		// I have absolutely no clue at all, 0, nil, nada, on why I have to divide by 4
		// but this makes it work so....
		CTextDraw::ChangeFontLog(pDC, size, "微軟正黑體", RGB(0, 0, 0), 800);
		CTextDraw::Print(pDC, sunBarRight - (msg.size() * size / 4), 61, msg);

		CDDraw::ReleaseBackCDC();
	}

	void GameBar::setSelectedCards()
	{
		// the below for loop should be wrapped into a function;
		for (unsigned int i = 0; i < cards.size(); i++)
		{
			cards.at(i).setCardPos(80 + i * 55, 10);	// set the card position to the bar
			cards.at(i).show();						// show the card.
		}
	}

	bool GameBar::checkIfCardIsAlreadySelected(SeedCard *card)
	{
		for (unsigned int i = 0; i < cards.size(); i++)
		{
			if (cards.at(i).getType() == card->getType())
			{
				return true;
			}
		}

		return false;
	}


	void GameBar::addCard(SeedCard *card)
	{
		// there are cards selected.
		if (cards.size() > 0)
		{
			for (unsigned int i = 0; i < cards.size(); i++)
			{
				// check for invalid cards and replace them.
				if (cards.at(i).getType() == SEED_CARD_TYPE::REFUSED)
				{
					cards.at(i) = SeedCard(card);
					_selectedCards += 1;
					return;
				}
			}
		}

		// no invalid card was found so just push back or the selection is empty.

		cards.push_back(SeedCard(card));
		_selectedCards += 1;
		return;
	}

	void GameBar::removeCard(SeedCard *card)
	{
		for (unsigned int i = 0; i < cards.size(); i++)
		{
			if (cards.at(i).getType() == card->getType())
			{
				cards.at(i).invalidateCard();
				_selectedCards -= 1;
			}
		}
	}
	void GameBar::updateCardsFrames()
	{
			for (unsigned int i = 0; i < cards.size(); i++)
			{
				cards.at(i).updateCooldown();

				if (cards.at(i).isOnCooldown())
					continue; // updateCooldown already took care of it.
				else if (_suns < cards.at(i).getPrice())
					cards.at(i).SetFrameIndexOfBitmap(SEED_CARD_STATE::UNABLE);
				else
					cards.at(i).SetFrameIndexOfBitmap(SEED_CARD_STATE::ALIVE);
			}
	}
}