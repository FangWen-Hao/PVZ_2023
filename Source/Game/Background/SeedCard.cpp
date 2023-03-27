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

void SeedCard::init(vector<string> filePath, int offsetX, int offsetY, int price, int cooldown, SEED_CARD type)
{
	_type = type;
	_price = price;
	_cooldown.setCooldown(cooldown);
	_filePath = filePath;
	LoadBitmapByString(_filePath);
	setCardPos(offsetX, offsetY);
	SetFrameIndexOfBitmap(0);	
}

void SeedCard::show()
{
	ShowBitmap();
}

void SeedCard::unshow()
{
	UnshowBitmap();
}

SEED_CARD SeedCard::clicked()
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
	SetFrameIndexOfBitmap(1);
}

void SeedCard::updateCooldown()
{
	_cooldown.updateCooldown();

	if (!_cooldown.isOnCooldown())
	{
		SetFrameIndexOfBitmap(0);
	}
}

void SeedCard::setCardPos(int x, int y)
{
	_posX = x;
	_posY = y;
	SetTopLeft(_posX, _posY);
}

void SeedCard::invalidateCard()
{
	_type = SEED_CARD::REFUSED;
}

SEED_CARD SeedCard::getType()
{
	return _type;
}

int SeedCard::getPrice()
{
	return _price;
}