#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include "../../Library/gameutil.h"
#include "../Misc/Cooldown.h"
#include "SeedCard.h"

using namespace game_framework;

SeedCard::SeedCard()
{
}

SeedCard::~SeedCard()
{
}

SeedCard::SeedCard(SeedCard *other)
{
	this->_type = other->_type;
	this->_price = other->_price;
	this->_cooldown.setCooldown(other->_cooldown.getCooldown());
	this->_filePath = other->_filePath;
	this->LoadBitmapByString(_filePath);
}

void SeedCard::init(vector<string> filePath, int offsetX, int offsetY, int price, int cooldown, SEED_CARD_TYPE type)
{
	_type = type;
	_price = price;
	_cooldown.setCooldown(cooldown);
	_filePath = filePath;
	LoadBitmapByString(_filePath);
	setCardPos(offsetX, offsetY);
	SetFrameIndexOfBitmap(SEED_CARD_STATE::ALIVE);
}

void SeedCard::show()
{
	ShowBitmap();
}

void SeedCard::unshow()
{
	UnshowBitmap();
}

SEED_CARD_TYPE SeedCard::clicked()
{
	// if it wasnt clicked before, put it up
	if (!_cooldown.isOnCooldown() && GetTop() == _posY && GetLeft() == _posX)
	{
		SetTopLeft(_posX, _posY - 10);
	}

	else // if it was clicked but not used, reset the card pos
	{
		resetCardPos();
	}

	return _type;
}

void SeedCard::resetCardPos()
{
	SetTopLeft(_posX, _posY);
}

void SeedCard::used()
{
	_cooldown.startCooldown();
	resetCardPos();
	SetFrameIndexOfBitmap(SEED_CARD_STATE::COOLDOWN_0); // needed?
}

void SeedCard::updateCooldown()
{
	_cooldown.updateCooldown();

	int progress = _cooldown.getCoolDownProgressInPercentage();

	if (progress <= 100 && progress > 75)
		SetFrameIndexOfBitmap(SEED_CARD_STATE::COOLDOWN_0);

	else if (progress <= 75 && progress > 50)
		SetFrameIndexOfBitmap(SEED_CARD_STATE::COOLDOWN_1);

	else if (progress <= 50 && progress > 25)
		SetFrameIndexOfBitmap(SEED_CARD_STATE::COOLDOWN_2);

	else if (progress <= 25 && progress > 0)
		SetFrameIndexOfBitmap(SEED_CARD_STATE::COOLDOWN_3);
}

void SeedCard::setCardPos(int x, int y)
{
	_posX = x;
	_posY = y;
	SetTopLeft(_posX, _posY);
}

void SeedCard::invalidateCard()
{
	_type = SEED_CARD_TYPE::REFUSED;
}

SEED_CARD_TYPE SeedCard::getType()
{
	return _type;
}

int SeedCard::getPrice()
{
	return _price;
}

bool SeedCard::isOnCooldown()
{
	return _cooldown.isOnCooldown();
}
