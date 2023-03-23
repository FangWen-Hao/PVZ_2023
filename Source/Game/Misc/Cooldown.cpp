#include "stdafx.h"
#include <ctime>
#include "Cooldown.h"

namespace game_framework
{
	Cooldown::Cooldown()
	{
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
		if ((time(0) - _lastUse) >= _cooldown)
			_onCooldown = false;
	}
}