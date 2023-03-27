#pragma once

// #include "../Terrain/Lane.h"
#include "../../Library/gameutil.h"
#include <string>
#include <ctime>

using namespace std;
namespace game_framework {
	const enum class PLANT {
		EMPTY,
		PEA_SHOOTER,
		SUN_FLOWER,
		CHERRY_BOMB,
		WALL_NUT,
		POTATO_MINE,
		SNOW_PEA,
		CHOMPER,
		REPEATER_PEA,
		PUFF_SHROOM,
		HYPNO_SHROOM,
		SCAREDY_SHROOM,
		ICE_SHROOM,
		SQUASH,
		THREE_PEATER,
		JALAPENO,
		SPIKE_WEED
	};

	// base class
	class Plant : CMovingBitmap
	{
	public:
		Plant() {};
		~Plant() {};

		// virtual void setLane(Lane* lane) { _currentLane = lane; }

		virtual PLANT getType() { return _type; }
		virtual int getCurrentHp() { return _hp; }
		virtual int getDamage() { return _damage; }
		virtual int getAttackSpeed() { return _attackSpeed; }

		virtual void attack() = 0;

	protected:
		// Lane *_currentLane;
		PLANT _type;
		time_t lastAttackTime;
		int secondsCoolDown;
		int _hp;
		int _damage;
		int _attackSpeed;
	};

	// inheritance class
	class GrassPlant : private Plant
	{
	public:
		GrassPlant();
		~GrassPlant();
	};

	class WaterPlant : private Plant
	{
	public:
		WaterPlant();
		~WaterPlant();
	};
}