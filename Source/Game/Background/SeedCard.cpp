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

SeedCard::SeedCard(SeedCard &other, int posX, int posY)
{
	_name = other._name;
	_price = other._price;
	_cooldown.setCooldown(other._cooldown.getCooldown());
	_posX = posX;
	_posY = posY;
}

void SeedCard::init(vector<string> filePath, int offsetX, int offsetY, string price, string cooldown, int name)
{
	_name = name;
	_posX = offsetX;
	_posY = offsetY;
	_price = stoi(price);
	_cooldown.setCooldown(stoi(cooldown));
	LoadBitmapByString(filePath);
	SetTopLeft(_posX, _posY);
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

int SeedCard::clicked()
{
	// if it wasnt clicked before, put it up
	if (!_cooldown.isOnCooldown() && GetTop() == _posY && GetLeft() == _posX)
	{
		SetTopLeft(_posX, _posY - 10);
		return _name;
	}

	else // if it was clicked but not used, reset the card pos
	{
		resetCardPos();
	}
	return SEED_CARD_REFUSED;
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


int SeedCard::getName()
{
	return _name;
}

int SeedCard::getPrice()
{
	return _price;
}