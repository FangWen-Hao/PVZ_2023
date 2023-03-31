#pragma once

#include "../../Library/gameutil.h"
#include <time.h>

using namespace std;

namespace game_framework {
	enum ZOMBIE_TYPE {
		EMPTY,
	};

	class Zombie : CMovingBitmap
	{
	public:

		// virtual Lane getLane() { return _currentLane; }
		virtual CPoint getPos() { return _pos; }
		virtual int getType() { return _type; }
		virtual int getCurrentHp() { return _hp; }
		virtual int getDamage() { return _damage; }
		virtual int getSpeed() { return _speed; }
		
		// virtual void setLane(Lane* lane) { _currentLane = lane; }
		virtual void setHp(int hp) { _hp = hp; }
		virtual void setDamage(int damage) { _damage = damage; }
		virtual void setSpeed(int speed) { _speed = speed; }

		virtual void attack() {}
		virtual void onInit() {
			// The follow code is just for testing
			LoadBitmapByString({ "Resources/Plants/Cards/BMP/card_peashooter_alive.bmp" });
			_pos.x = 700;
			//srand(time(nullptr));
			int _lane = rand() % 5;

			if (_lane == 0) _pos.y = 100;
			else if (_lane == 1) _pos.y = 200;
			else if (_lane == 2) _pos.y = 300;
			else if (_lane == 3) _pos.y = 400;
			else if (_lane == 4) _pos.y = 500;
		}
		virtual void onMove() { 
			// This is not working
			_pos.x -= 50;
		}
		virtual void onShow() {
			SetTopLeft(_pos.x, _pos.y);
			ShowBitmap();
		}
		
	protected:
		//Lane *_currentLane;
		time_t lastAttackTime;
		CPoint _pos;
		int _type;
		int _secondsCoolDown;
		int _lane;
		int _hp;
		int _damage;
		int _speed = 10;
	};

	class TestZombie : public Zombie {
	public:
		TestZombie() { }
	};
}