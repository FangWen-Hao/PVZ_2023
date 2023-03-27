#pragma once

namespace game_framework {
	enum ZOMBIE_TYPE {
		EMPTY,
	};

	class Zombie : CMovingBitmap
	{
	public:
		Zombie() {};
		~Zombie() {};

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

		virtual void attack() = 0;
		virtual void move() { _pos.x -= _speed; }
		
	private:
		//Lane *_currentLane;
		time_t lastAttackTime;
		CPoint _pos;
		int _type;
		int _secondsCoolDown;
		int _hp;
		int _damage;
		int _speed;
	};
}