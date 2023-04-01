#include "stdafx.h"
#include "Cooldown.h"

namespace game_framework
{
	time_t Cooldown::gameClock;

	Cooldown::Cooldown()
	{
		gameClock = time(0);
	}

	Cooldown::~Cooldown()
	{
	}

	void Cooldown::setCooldown(int cooldown)
	{
		_cooldown = cooldown;
	}

	void Cooldown::overrideCooldownStatus(bool status)
	{
		_onCooldown = status; // is this gonna even useful?
	}

	time_t Cooldown::getGameClock()
	{
		return gameClock;
	}

	unsigned int Cooldown::getGameClockForPRNGSeed()
	{
		return ((unsigned int)gameClock);
	}

	int Cooldown::getCooldown()
	{
		return _cooldown;
	}

	time_t Cooldown::getLastUse()
	{
		return _lastUse;
	}

	bool Cooldown::isOnCooldown()
	{
		return _onCooldown;
	}

	void Cooldown::updateGameClock()
	{
		gameClock = time(0);
	}

	void Cooldown::startCooldown()
	{
		if (!_onCooldown)
		{
			_lastUse = time(0);
			_onCooldown = true;
		}
	}

	void Cooldown::updateCooldown()
	{
		// https://www.codespeedy.com/how-to-create-a-timer-in-cpp/
		if ((gameClock - _lastUse) >= _cooldown)
			_onCooldown = false;
	}
}