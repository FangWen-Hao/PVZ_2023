#pragma once

// #include "../Terrain/Lane.h"
#include "../../Library/gameutil.h"
#include <string>
#include <ctime>

using namespace std;
namespace game_framework {
	const enum class PLANT {
		EMPTY,
		CHERRY_BOMB,
		CHOMPER,
		HYPNO_SHROOM,
		ICE_SHROOM,
		JALAPENO,
		PEA_SHOOTER,
		POTATO_MINE,
		PUFF_SHROOM,
		REPEATER_PEA,
		SCAREDY_SHROOM,
		SNOW_PEA,
		SPIKE_WEED,
		SQUASH,
		SUN_FLOWER,
		SUN_SHROOM,
		THREE_PEATER,
		WALL_NUT,
	};

	// base class
	class Plant
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

		CMovingBitmap animate;
	};

	// inheritance class
	class CherryBomb : public Plant
	{
	public:
		CherryBomb();
		~CherryBomb();
	};

	class Chomper : private Plant
	{
	public:
		Chomper();
		~Chomper();
	};

	class HypnoShroom : private Plant
	{
	public:
		HypnoShroom();
		~HypnoShroom();
	};

	class IceShroom : private Plant
	{
	public:
		IceShroom();
		~IceShroom();
	};

	class Jalapeno : private Plant
	{
	public:
		Jalapeno();
		~Jalapeno();
	};

	class PeaShooter : private Plant
	{
	public:
		PeaShooter();
		~PeaShooter();
	};

	class PotatoMine : private Plant
	{
	public:
		PotatoMine();
		~PotatoMine();
	};

	class PuffShroom : private Plant
	{
	public:
		PuffShroom();
		~PuffShroom();
	};

	class RepeaterPea : private Plant
	{
	public:
		RepeaterPea();
		~RepeaterPea();
	};

	class ScaredyShroom : private Plant
	{
	public:
		ScaredyShroom();
		~ScaredyShroom();
	};

	class SnowPea : private Plant
	{
	public:
		SnowPea();
		~SnowPea();
	};

	class Spikeweed : private Plant
	{
	public:
		Spikeweed();
		~Spikeweed();
	};

	class Squash : private Plant
	{
	public:
		Squash();
		~Squash();
	};

	class SunFlower : private Plant
	{
	public:
		SunFlower();
		~SunFlower();
	};

	class Threepeater : private Plant
	{
	public:
		Threepeater();
		~Threepeater();
	};

	class WallNut : private Plant
	{
	public:
		WallNut();
		~WallNut();
	};
}