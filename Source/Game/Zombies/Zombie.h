#pragma once

#include "../../Library/gameutil.h"
#include "../GameMode/Maps/Tile_Positions.h"
#include <time.h>

using namespace std;

namespace game_framework {
	enum class ZOMBIE_TYPE
	{
		EMPTY,
		NORMAL,
		BUCKETHEAD,
		CONEHEAD,
		FLAG,
		NEWSPAPER,
		NEWSPAPERNOPAPER,
	};

	class Zombie
	{
	public:

		// virtual Lane getLane() { return _currentLane; }
		virtual ZOMBIE_TYPE getType() { return _type; }
		virtual int getPosX() { return _posX; }
		virtual int getPosY() { return _posY; }
		virtual int getCurrentHp() { return _hp; }
		virtual int getDamage() { return _damage; }
		virtual int getSpeed() { return _speed; }

		// virtual void setLane(Lane* lane) { _currentLane = lane; }
		virtual void setHp(int hp) { _hp = hp; }
		virtual void setDamage(int damage) { _damage = damage; }
		virtual void setSpeed(int speed) { _speed = speed; }

		virtual void attack() {}
		virtual void onInit() {
			int _lane = rand() % 5;

			_posX = RIGHT_TILES_POSITION_ON_MAP.at(8);
			_posY = BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(_lane);
		}

		virtual void onMove() {

			if (_hp <= 0) _isDead = true;

			if (_isAttacking) {
				++_ttlAttack %= _attackFrequency;

				if (_ttlAttack == 0) attack();
			}
			else if (!_isDead) {
				++_ttlMove %= _moveFrequency;

				if (_ttlMove == 0) _posX -= _speed;
			}
		}

		virtual void onShow() {
			if (_isAttacking)
			{
				attackAnimate.SetTopLeft(_posX, _posY - attackAnimate.GetHeight());
				attackAnimate.ShowBitmap();
			}
			else if (_isDead)
			{
				deadAnimate.SetTopLeft(_posX, _posY - deadAnimate.GetHeight());
				deadAnimate.ShowBitmap();
			}
			else
			{
				normalAnimate.SetTopLeft(_posX, _posY - normalAnimate.GetHeight());
				normalAnimate.ShowBitmap();
			}
		}

	protected:
		//Lane *_currentLane;
		ZOMBIE_TYPE _type;

		int _posX;
		int _posY;
		int _lane;

		int _ttlMove = 0;
		int _ttlAttack = 0;

		int _hp;
		int _speed = 1;
		int _damage;
		int _moveFrequency = 10;
		int _attackFrequency;

		bool _isAttacking = false;
		bool _isDead = false;

		time_t lastAttackTime;

		CMovingBitmap normalAnimate;
		CMovingBitmap deadAnimate;
		CMovingBitmap attackAnimate;
	};

	class NormalZombie : public Zombie {
	public:
		NormalZombie();
		~NormalZombie();
	};

	class BucketheadZombie : public Zombie {
	public:
		BucketheadZombie();
		~BucketheadZombie();
	};

	class ConeheadZombie : public Zombie {
	public:
		ConeheadZombie();
		~ConeheadZombie();
	};

	class FlagZombie : public Zombie {
		FlagZombie();
		~FlagZombie();
	};

	class NewspaperZombie : public Zombie {
		NewspaperZombie();
		~NewspaperZombie();
	};

	class NewpaperZombieNoPaper : public Zombie {
		NewpaperZombieNoPaper();
		~NewpaperZombieNoPaper();
	};
}