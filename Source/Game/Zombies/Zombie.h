#pragma once

#include "../../Library/gameutil.h"
#include "../Misc/Cooldown.h"
#include "../GameMode/Maps/Tile_Positions.h"

using namespace std;

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
		int row() { return _row; }
		int col() { return _col; }

		virtual int getCurrentHp() { return _hp; }
		virtual int getSpeed() { return _speed; }
		virtual bool isDead() { return _isDead; }
		virtual bool isDeadDone() { return deadAnimate.IsAnimationDone(); }

		virtual void setIsAttacking(bool isAttacking) {
			if (!_isAttacking) attackCooldown.startCooldown();
			_isAttacking = isAttacking;
		}
		// virtual void setLane(Lane* lane) { _currentLane = lane; }
		virtual void setHp(int hp) { _hp = hp; }
		virtual void setSpeed(int speed) { _speed = speed; }
		void beingAttacked(int damage) { _hp -= damage; }

		virtual void attack() {}
		virtual void onInit() {
			_row = rand() % 5;

			_posX = RIGHT_TILES_POSITION_ON_MAP.at(8);
			_posY = BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(_row) - normalAnimate.GetHeight();
		}

		virtual void onInit(int row) {
			_row = row;
			_posX = RIGHT_TILES_POSITION_ON_MAP.at(8);
			_posY = BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(_row) - normalAnimate.GetHeight();
		}

		virtual void onMove(vector<vector<Plant*>>*);

		virtual void onShow() {
			if (_isDead)
			{
				deadAnimate.ShowBitmap();
			}
			else if (_isAttacking)
			{
				attackAnimate.ShowBitmap();
			}
			else
			{
				normalAnimate.ShowBitmap();
			}
		}

	protected:
		Zombie(const ZOMBIE_TYPE type, const int damage, const double attackSpeed)
			: _type(type), _damage(damage), _attackSpeed(attackSpeed)
		{
			attackCooldown.initCooldown(attackSpeed);
		}
		
		//Lane *_currentLane;
		const ZOMBIE_TYPE _type;
		const int _damage;
		const double _attackSpeed;
		int _speed = 1;
		int _moveFrequency = 10;

		int _posX;
		int _posY;
		int _row;
		int _col = -1;

		int _hp;
		int _ttlMove = 0;

		bool _isAttacking = false;
		bool _isDead = false;

		Cooldown attackCooldown;

		CMovingBitmap normalAnimate;
		CMovingBitmap deadAnimate;
		CMovingBitmap attackAnimate;

		void _updateCol()
		{
			for (int i = 0; i < 9; ++i) {
				if (_posX >= LEFT_TILES_POSITION_ON_MAP.at(i) &&
					_posX <= RIGHT_TILES_POSITION_ON_MAP.at(i))
				{
					_col = i;
					return;
				}
			}
			_col = -1;
		}
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
