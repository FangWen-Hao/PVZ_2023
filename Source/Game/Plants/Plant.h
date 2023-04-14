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

		virtual void attack() {};
		virtual void SetTopLeft(CPoint pos) {
			animate.SetTopLeft(pos.x, pos.y);
		}
		virtual void SetTopLeft(int x, int y) {
			animate.SetTopLeft(x, y);
		}
		virtual void onShow() {
			animate.ShowBitmap();
		}
		virtual void onMove() {

		}

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

	class Chomper : public Plant
	{
	public:
		Chomper();
		~Chomper();
	};

	class HypnoShroom : public Plant
	{
	public:
		HypnoShroom();
		~HypnoShroom();
	};

	class IceShroom : public Plant
	{
	public:
		IceShroom();
		~IceShroom();
	};

	class Jalapeno : public Plant
	{
	public:
		Jalapeno();
		~Jalapeno();
	};

	class PeaShooter : public Plant
	{
	public:
		PeaShooter(CPoint);
		~PeaShooter();
	};

	class PotatoMine : public Plant
	{
	public:
		PotatoMine();
		~PotatoMine();
	};

	class PuffShroom : public Plant
	{
	public:
		PuffShroom();
		~PuffShroom();
	};

	class RepeaterPea : public Plant
	{
	public:
		RepeaterPea();
		~RepeaterPea();
	};

	class ScaredyShroom : public Plant
	{
	public:
		ScaredyShroom();
		~ScaredyShroom();
	};

	class SnowPea : public Plant
	{
	public:
		SnowPea();
		~SnowPea();
	};

	class Spikeweed : public Plant
	{
	public:
		Spikeweed();
		~Spikeweed();
	};

	class Squash : public Plant
	{
	public:
		Squash();
		~Squash();
	};

	class SunFlower : public Plant
	{
	public:
		SunFlower();
		~SunFlower();
	};

	class Threepeater : public Plant
	{
	public:
		Threepeater();
		~Threepeater();
	};

	class WallNut : public Plant
	{
	public:
		WallNut();
		~WallNut();
	};
}