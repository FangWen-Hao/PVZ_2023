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

		static void updateGameClock();
		static high_resolution_clock::time_point getGameClock();
		static long unsigned int getGameClockForPRNGSeed();
		static void initGamePauseTime();
		static void pauseClockBegin();
		static void pauseClockEnd();

		void initCooldown(double cooldown);

		double getCooldown() const { return _cooldown; }
		high_resolution_clock::time_point getLastUse();
		int getCoolDownProgressInPercentage();
		bool isOnCooldown();
		void startCooldown();

	private:
		static high_resolution_clock::time_point gameClock; // this clock is used so we can just call the current time once and then compare all the cooldowns with this one
								// instead of calling the system clock for every cooldown since we want to updateCooldown every second of the game.
		static high_resolution_clock::time_point gamePauseBegin;
		static double gamePauseTime; // doesnt work
		
		double _cooldown; // in seconds
		high_resolution_clock::time_point _lastUse;
	};
}