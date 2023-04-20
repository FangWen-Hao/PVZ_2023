#pragma once

// #include "../Terrain/Lane.h"
#include "../../Library/gameutil.h"
#include "../Misc/Bullet/Bullet.h"
#include "../Misc/Sun.h"
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
		virtual int getPrice() { return _price; }

		virtual void attack(vector<Bullet*>*) {};
		virtual void generateSun(vector<Sun*>*) {};
		virtual void SetTopLeft(CPoint pos) { animate.SetTopLeft(pos.x, pos.y); }
		virtual void SetTopLeft(int x, int y) { animate.SetTopLeft(x, y); }
		virtual void onShow() { animate.ShowBitmap(); }

		virtual void onMove(vector<Bullet*>* bullets, vector<Zombie*>* zombies) {
			++_ttlAttack %= _attackSpeed;

			if (_ttlAttack == 0)
			{
				attack(bullets);
			}

			detectCollision(zombies);
		}
		virtual void onMove(vector<Sun*>* suns, vector<Zombie*>* zombies) {
			++_ttlAttack %= _attackSpeed;

			if (_ttlAttack == 0)
			{
				generateSun(suns);
			}

			detectCollision(zombies);
		}

		int width() { return animate.GetWidth(); }
		int height() { return animate.GetHeight(); }
		bool isDead() { return _isDead; }

	protected:
		// Lane *_currentLane;
		PLANT _type;
		time_t lastAttackTime;
		int secondsCoolDown;
		int _hp;
		int _damage;
		int _attackSpeed;
		int _ttlAttack = 0;
		int _price;
		bool _isDead = false;

		CMovingBitmap animate;

	private:
		void detectCollision(vector<Zombie*>* zombies) {
			for (Zombie* zombie : *zombies) {
				if (animate.GetLeft() < (zombie->GetLeft() + zombie->GetWidth()) &&
					(animate.GetLeft() + animate.GetWidth()) > zombie->GetLeft() &&
					animate.GetTop() < (zombie->GetTop() + zombie->GetHeight()) &&
					(animate.GetTop() + animate.GetHeight()) > zombie->GetTop())
				{
					_hp -= zombie->getDamage();
					if (_hp <= 0) _isDead = true;
				}
			}
		}
	};

	// inheritance class
	class CherryBomb : public Plant
	{
	public:
		CherryBomb(CPoint);
		~CherryBomb();

		static const int price = 150;
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

		static const int price = 100;

		void attack(vector<Bullet*>*) override;		
	};

	class PotatoMine : public Plant
	{
	public:
		PotatoMine(CPoint);
		~PotatoMine();

		static const int price = 25;

		void onMove(vector<Bullet*>*, vector<Zombie*>*) override;

	private:
		CMovingBitmap mine;
		CMovingBitmap explode;

		bool _isDetected = false;
	};

	class PuffShroom : public Plant
	{
	public:
		PuffShroom(CPoint);
		~PuffShroom();

		static const int price = 0;
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
		SnowPea(CPoint);
		~SnowPea();

		static const int price = 175;

		void attack(vector<Bullet*>*) override;
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
		Squash(CPoint);
		~Squash();

		static const int price = 50;
	};

	class SunFlower : public Plant
	{
	public:
		SunFlower(CPoint);
		~SunFlower();

		static const int price = 50;

		void generateSun(vector<Sun*>*) override;
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
		WallNut(CPoint);
		~WallNut();

		static const int price = 50;
	};
}


