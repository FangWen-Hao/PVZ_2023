#pragma once
#include <ctime>

namespace game_framework
{

	class Cooldown
	{
	public:
		Cooldown();
		~Cooldown();

		void setCooldown(int cooldown);
		void overrideCooldownStatus(bool status);

		static time_t getGameClock();
		static unsigned int getGameClockForPRNGSeed();
		int getCooldown();
		time_t getLastUse();
		bool isOnCooldown();

		static void updateGameClock();
		void startCooldown();
		void updateCooldown();

	private:
		static time_t gameClock; // this clock is used so we can just call the current time once and then compare all the cooldowns with this one
								// instead of calling the system clock for every cooldown since we want to updateCooldown every second of the game.
		int _cooldown; // in seconds
		time_t _lastUse;
		bool _onCooldown = false;
	};
}