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

	Cooldown::~Cooldown() {}

	void Cooldown::initCooldown(double cooldown)
	{
		_cooldown = cooldown;
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
		return duration_cast<duration<double>>(gameClock - _lastUse).count() < _cooldown;
	}

	int Cooldown::getCoolDownProgressInPercentage()
	{
		if (isOnCooldown())
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
		_lastUse = high_resolution_clock::now();
	}
}