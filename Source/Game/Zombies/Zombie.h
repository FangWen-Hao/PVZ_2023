#pragma once

#include "../../Library/gameutil.h"
#include "../GameMode/Maps/Tile_Positions.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace game_framework
{
	class Plant;	// Forward declaration

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

	//////////////////////////////////////////////////
	// Base Class
	//////////////////////////////////////////////////
	class Zombie
	{
	public:
		~Zombie() {}

		// virtual Lane getLane() { return _currentLane; }
		ZOMBIE_TYPE getType() { return _type; }
		int getDamage() { return _damage; }
		int width() { return normalAnimate.GetWidth(); }
		int height() { return normalAnimate.GetHeight(); }
		int left() { return _posX; }
		int top() { return _posY; }
		int right() { return _posX + width(); }
		int bottom() { return _posY + height(); }

		virtual int getCurrentHp() { return _hp; }
		virtual int getSpeed() { return _speed; }
		virtual bool isDead() { return _isDead; }
		virtual bool isDeadDone() { return deadAnimate.IsAnimationDone(); }
		virtual bool ableToAttack() { 
			duration<double> time_span = duration_cast<duration<double>>(high_resolution_clock::now() - lastAttackTime);
			return time_span.count() >= _attackSpeed;
		}

		virtual void setIsAttacking(bool isAttacking) {
			_isAttacking = isAttacking;
			lastAttackTime = high_resolution_clock::now();
		}
		// virtual void setLane(Lane* lane) { _currentLane = lane; }
		virtual void setHp(int hp) { _hp = hp; }
		virtual void setSpeed(int speed) { _speed = speed; }
		void beingAttacked(int damage) { _hp -= damage; }

		virtual void attack(Plant*);
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
			else if (!_isAttacking && !_isDead) {
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
		Zombie(const ZOMBIE_TYPE type, const int damage, const double attackSpeed)
			: _type(type), _damage(damage), _attackSpeed(attackSpeed) {}
		
		//Lane *_currentLane;
		const ZOMBIE_TYPE _type;
		const int _damage;
		const double _attackSpeed;
		int _speed = 1;
		int _moveFrequency = 10;

		int _posX;
		int _posY;
		int _lane;

		int _hp;
		int _ttlMove = 0;

		bool _isAttacking = false;
		bool _isDead = false;

		high_resolution_clock::time_point lastAttackTime = high_resolution_clock::now();

		CMovingBitmap normalAnimate;
		CMovingBitmap deadAnimate;
		CMovingBitmap attackAnimate;
	};
	//////////////////////////////////////////////////
	
	//////////////////////////////////////////////////
	// Inheritance Classes of Zombie
	//////////////////////////////////////////////////
	class NormalZombie : public Zombie {
	public:
		NormalZombie();
		~NormalZombie() {}
	};

	class BucketheadZombie : public Zombie {
	public:
		BucketheadZombie();
		~BucketheadZombie() {}
	};

	class ConeheadZombie : public Zombie {
	public:
		ConeheadZombie();
		~ConeheadZombie() {}
	};

	class FlagZombie : public Zombie {
		FlagZombie();
		~FlagZombie() {}
	};

	class NewspaperZombie : public Zombie {
		NewspaperZombie();
		~NewspaperZombie() {}
	};

	class NewpaperZombieNoPaper : public Zombie {
		NewpaperZombieNoPaper();
		~NewpaperZombieNoPaper() {}
	};
}
