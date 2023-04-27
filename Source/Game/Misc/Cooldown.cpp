#include "stdafx.h"
#include "Cooldown.h"

using namespace std::chrono;
namespace game_framework
{
	high_resolution_clock::time_point Cooldown::gameClock;

	Cooldown::Cooldown()
	{
		gameClock = high_resolution_clock::now();
	}

	Cooldown::~Cooldown()
	{
	}

	void Cooldown::setCooldown(double cooldown)
	{
		_cooldown = cooldown;
	}

	void Cooldown::overrideCooldownStatus(bool status)
	{
		_onCooldown = status; // is this gonna even useful?
	}

	high_resolution_clock::time_point Cooldown::getGameClock()
	{
		return gameClock;
	}

	long unsigned int Cooldown::getGameClockForPRNGSeed()
	{
		return (static_cast<long unsigned int>(gameClock.time_since_epoch().count()));
	}

	double Cooldown::getCooldown()
	{
		return _cooldown;
	}

	high_resolution_clock::time_point Cooldown::getLastUse()
	{
		return _lastUse;
	}

	bool Cooldown::isOnCooldown()
	{
		return _onCooldown;
	}

	int Cooldown::getCoolDownProgressInPercentage()
	{
		if (_onCooldown)
		{
			double percentage = (_cooldown - std::chrono::duration<double>(gameClock - _lastUse).count()) / _cooldown * 100;
			return (int(percentage));
		}

		return 0;
	}

	void Cooldown::updateGameClock()
	{
		gameClock = high_resolution_clock::now();
	}

	void Cooldown::startCooldown()
	{
		if (!_onCooldown)
		{
			_lastUse = high_resolution_clock::now();
			_onCooldown = true;
		}
	}

	void Cooldown::updateCooldown()
	{
		// https://www.codespeedy.com/how-to-create-a-timer-in-cpp/
		if (duration_cast<duration<double>>(gameClock - _lastUse).count() >= _cooldown)
			_onCooldown = false;
	}
}