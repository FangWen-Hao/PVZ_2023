#pragma once

namespace game_framework
{

	class Cooldown
	{
	public:
		Cooldown();
		~Cooldown();

		void setCooldown(int cooldown);
		void overrideCooldownStatus(bool status);


		int getCooldown();
		time_t getLastUse();
		bool isOnCooldown();

		void startCooldown();
		void updateCooldown();

	private:
		int _cooldown;
		time_t _lastUse;
		bool _onCooldown = false;
	};
}