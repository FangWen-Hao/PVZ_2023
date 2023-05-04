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

		ZOMBIE_TYPE type() { return _type; }
		
		int width() { return normalAnimate.GetWidth(); }
		int height() { return normalAnimate.GetHeight(); }
		int left() { return _posX; }
		int top() { return _posY; }
		int right() { return _posX + width(); }
		int bottom() { return _posY + height(); }
		int row() { return _row; }
		int col() { return _col; }

		bool isDead() { return _isDead; }
		bool isDeadDone() { return deadAnimate.IsAnimationDone(); }

		void beingAttacked(int damage) { _hp -= damage; }
		void setIsAttacking(bool isAttacking) {
			if (!_isAttacking) attackCooldown.startCooldown();
			_isAttacking = isAttacking;
		}

		virtual void onInit(int);
		virtual void onMove(vector<vector<Plant*>>*);
		virtual void onShow();

	protected:
		Zombie(const ZOMBIE_TYPE type, const int damage, const double attackSpeed, const double moveSpeed)
			: _type(type), _damage(damage), _attackSpeed(attackSpeed), _moveSpeed(moveSpeed)
		{
			attackCooldown.initCooldown(attackSpeed);
			moveCooldown.initCooldown(moveSpeed / PX_PER_TILES);
		}
		
		//Lane *_currentLane;
		const ZOMBIE_TYPE _type;
		const int _damage;
		const double _attackSpeed;
		const double _moveSpeed;

		int _hp;
		int _posX;
		int _posY;
		int _row;
		int _col = -1;

		bool _isAttacking = false;
		bool _isDead = false;

		Cooldown attackCooldown;
		Cooldown moveCooldown;

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
