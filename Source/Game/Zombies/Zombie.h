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
		virtual int GetLeft() { return _posX; }
		virtual int GetTop() { return _posY; }
		virtual int getCurrentHp() { return _hp; }
		virtual int getDamage() { return _damage; }
		virtual int getSpeed() { return _speed; }
		virtual int GetWidth() { return normalAnimate.GetWidth(); }
		virtual int GetHeight() { return normalAnimate.GetHeight(); }
		virtual bool isDead() { return _isDead; }
		virtual bool isDeadDone() { return deadAnimate.IsAnimationDone(); }

		// virtual void setLane(Lane* lane) { _currentLane = lane; }
		virtual void setHp(int hp) { _hp = hp; }
		virtual void setDamage(int damage) { _damage = damage; }
		virtual void setSpeed(int speed) { _speed = speed; }
		virtual void beingAttacked(int damage) {
			_hp -= damage;
		}

		virtual void attack() {}
		virtual void onInit() {
			int _lane = rand() % 5;

			_posX = RIGHT_TILES_POSITION_ON_MAP.at(8);
			_posY = BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(_lane) - normalAnimate.GetHeight();
		}

		virtual void onMove() {

			if (_hp <= 0 && !_isDead)
			{
				_isDead = true;
				deadAnimate.ToggleAnimation();
			}

			if (_isAttacking) {
				++_ttlAttack %= _attackFrequency;

				if (_ttlAttack == 0) attack();
			}
			else if (!_isDead) {
				++_ttlMove %= _moveFrequency;

				if (_ttlMove == 0) _posX -= _speed;
			}

			attackAnimate.SetTopLeft(_posX, _posY);
			deadAnimate.SetTopLeft(_posX - 100, _posY - 25);
			normalAnimate.SetTopLeft(_posX, _posY);
		}

		virtual void onShow() {
			if (_isAttacking)
			{
				attackAnimate.ShowBitmap();
			}
			else if (_isDead)
			{
				deadAnimate.ShowBitmap();
			}
			else
			{
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