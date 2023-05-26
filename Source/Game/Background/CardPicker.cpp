#include "stdafx.h"
#include <vector>
#include <string>
#include <atltypes.h>
#include "../../Library/gameutil.h"
#include "SeedCard.h"
#include "CardPicker.h"
#include "../Utils/Soundboard.h"

using namespace std;
using namespace game_framework;

CardPicker::CardPicker()
{
}

CardPicker::~CardPicker()
{
}

int CardPicker::GetLeft()
{
	return background.GetLeft();
}

int CardPicker::GetWidth()
{
	return background.GetWidth();
}

int CardPicker::GetTop()
{
	return background.GetTop();
}

int CardPicker::GetHeight()
{
	return background.GetHeight();
}

void CardPicker::init()
{
	background.LoadBitmapByString({ PICKER_BACKGROUND });
	background.SetTopLeft(LEFT, TOP);

	int cardLeft = LEFT + CARD_LEFT;
	int cardTop = TOP + CARD_TOP;
	int iterator = -1;

	for (pair<vector<int>, vector<string>> cardInfo: CARDS_DATA_MAP)
	{
		SeedCard tmp;
		tmp.init(static_cast<SEED_CARD_TYPE>(cardInfo.first.at(0)), cardInfo.first.at(1), cardInfo.first.at(2), cardInfo.second, cardLeft, cardTop);
		cards.push_back(tmp);

		cardLeft += CARD_LEFT_PADDING;
		iterator++;

		if (iterator % CARD_PER_ROW == CARD_PER_ROW - 1)
		{
			cardLeft = LEFT + CARD_LEFT;
			cardTop += CARD_TOP_PADDING;
		}
	}
}

void CardPicker::show()
{
	background.ShowBitmap();
	for (unsigned int i = 0; i < cards.size(); i++)
	{
		cards.at(i).show();
	}
}

void CardPicker::unshow()
{
	for (unsigned int i = 0; i < cards.size(); i++)
	{
		cards.at(i).unshow();
	}
	background.UnshowBitmap();
}

void CardPicker::OnHover(CPoint coords)
{
}

SeedCard* CardPicker::OnClick(CPoint coords)
{
	for (unsigned int i = 0; i < cards.size(); i++)
	{
		if (coords.x < (cards.at(i).GetLeft() + cards.at(i).GetWidth()) && coords.x > cards.at(i).GetLeft()
			&& coords.y < (cards.at(i).GetTop() + cards.at(i).GetHeight()) && coords.y > cards.at(i).GetTop())
		{
			// card was selected
			if (cards.at(i).clicked() != SEED_CARD_TYPE::REFUSED)
			{
				// SoundBoard::playSfx(soundID::plantPicked);
				return &(cards.at(i));
			}
		}
	}

	return nullptr;
}
