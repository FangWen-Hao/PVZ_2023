#pragma once
#include <chrono>

using namespace std::chrono;
namespace game_framework
{

	class Cooldown
	{
	public:
		Cooldown();
		~Cooldown();

		void setCooldown(double cooldown);
		void overrideCooldownStatus(bool status);

		static high_resolution_clock::time_point getGameClock();
		static long unsigned int getGameClockForPRNGSeed();
		double getCooldown();
		high_resolution_clock::time_point getLastUse();
		bool isOnCooldown();
		int getCoolDownProgressInPercentage();

		static void updateGameClock();
		void startCooldown();
		void updateCooldown();

	private:
		static high_resolution_clock::time_point gameClock; // this clock is used so we can just call the current time once and then compare all the cooldowns with this one
								// instead of calling the system clock for every cooldown since we want to updateCooldown every second of the game.
		double _cooldown; // in seconds
		high_resolution_clock::time_point _lastUse;
		bool _onCooldown = false;
	};
}