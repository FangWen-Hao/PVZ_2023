#pragma once

// #include "../Terrain/Lane.h"
#include "../../Library/gameutil.h"
#include "../Misc/Bullet/Bullet.h"
#include "../Zombies/Zombie.h"
#include "../Misc/Sun.h"
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

namespace game_framework
{
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

	const enum class PLANT_TYPE {
		DEFENSIVE,
		DISPOSABLE,
		GENERATE_SUN,
		SHOOTING,
	};

	//////////////////////////////////////////////////
	// Base Class
	//////////////////////////////////////////////////
	class Plant
	{
	public:
		~Plant() {}

		// virtual void setLane(Lane* lane) { _currentLane = lane; }
		PLANT_TYPE getType() { return _type; }
		PLANT getName() { return _name; }
		int getCurrentHp() { return _hp; }
		int getPrice() { return _price; }
		int width() { return animate.GetWidth(); }
		int height() { return animate.GetHeight(); }
		int top() { return animate.GetTop(); }
		int left() { return animate.GetLeft(); }
		int right() { return left() + width(); }
		int bottom() { return top() + height(); }
		bool isDead() { return _isDead; }

		void SetTopLeft(CPoint pos) { animate.SetTopLeft(pos.x, pos.y); }
		void SetTopLeft(int x, int y) { animate.SetTopLeft(x, y); }
		void beginAttack(int damage) { _hp -= damage; }
		void isAttackedBy(Zombie* zombie) {
			if (find(_isAttackedBy.begin(), _isAttackedBy.end(), zombie) == _isAttackedBy.end())
			{
				_isAttackedBy.push_back(zombie);
			}
		}
		void isNotAttackedBy(Zombie* zombie) {
			_isAttackedBy.erase(remove(_isAttackedBy.begin(), _isAttackedBy.end(), zombie), _isAttackedBy.end());
		}

		virtual void onMove() {
			for (Zombie* zombie : _isAttackedBy)
			{
				zombie->attack(this);
			}
		};
		virtual void onMove(vector<Sun*>*) { Plant::onMove(); };
		virtual void onMove(vector<Bullet*>*) { Plant::onMove(); };
		virtual void onShow() { animate.ShowBitmap(); }

	protected:
		Plant(const PLANT_TYPE type, const PLANT name, const int price, const double coolDown)
			: _type(type), _name(name), _price(price), _coolDown(coolDown) {}
		
		// Lane *_currentLane;
		const PLANT_TYPE _type;
		const PLANT _name;
		const int _price;
		const double _coolDown;
		
		CMovingBitmap animate;
		vector<Zombie*> _isAttackedBy;
		int _hp;
		bool _isDead = false;

		// time_t lastAttackTime;
		// int secondsCoolDown;	
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Classes of Plant
	//////////////////////////////////////////////////
	class DefensivePlant : public Plant
	{
	public:
		
	protected:
		DefensivePlant(const PLANT name, const int price, const int coolDown)
			: Plant(PLANT_TYPE::DEFENSIVE, name, price, coolDown) {}
		~DefensivePlant() {}
	};

	class DisposablePlant : public Plant
	{
	public:

	protected:
		DisposablePlant(const PLANT name, const int price, const double coolDown, const int damage)
			: Plant(PLANT_TYPE::DISPOSABLE, name, price, coolDown), _damage(damage) {}
		~DisposablePlant() {}

		const int _damage;
	};

	class GenerateSunPlant : public Plant
	{
	public:
		virtual void generateSun(vector<Sun*>*) = 0;

		virtual void onMove(vector<Sun*>* suns) override  {
			duration<double> durationTime = duration_cast<duration<double>>(high_resolution_clock::now() - lastGenerateTime);

			if (durationTime.count() >= _generateSpeed)
			{
				generateSun(suns);
				lastGenerateTime = high_resolution_clock::now();
			}
		}
	protected:
		GenerateSunPlant(const PLANT name, const int price, const double coolDown, const double generateSpeed)
			: Plant(PLANT_TYPE::GENERATE_SUN, name, price, coolDown), _generateSpeed(generateSpeed) {}
		~GenerateSunPlant() {}

		const double _generateSpeed;
		high_resolution_clock::time_point lastGenerateTime = high_resolution_clock::now();
	};

	class ShootingPlant : public Plant
	{
	public:
		virtual void attack(vector<Bullet*>*) = 0;

		virtual void onMove(vector<Bullet*>* bullets) override {
			duration<double> durationTime = duration_cast<duration<double>>(high_resolution_clock::now() - lastAttackTime);
			if (durationTime.count() >= _attackSpeed)
			{
				attack(bullets);
				lastAttackTime = high_resolution_clock::now();
			}
		}

	protected:
		ShootingPlant(const PLANT name, const int price, const double coolDown, const int damage, const double attackSpeed)
			: Plant(PLANT_TYPE::SHOOTING, name, price, coolDown), _damage(damage), _attackSpeed(attackSpeed) {}
		~ShootingPlant() {}
		
		const int _damage;
		const double _attackSpeed;
		high_resolution_clock::time_point lastAttackTime = high_resolution_clock::now();
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Class of DefensivePlant
	//////////////////////////////////////////////////
	class WallNut : public DefensivePlant
	{
	public:
		WallNut(CPoint);
		~WallNut() {}

		static const int price = 50;

		void onShow() override;

	protected:

	private:
		const int brokenThreshold1 = 2666;
		const int brokenThreshold2 = 1333;

		CMovingBitmap crackedAnimate1;
		CMovingBitmap crackedAnimate2;
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Class of DisposablePlant
	//////////////////////////////////////////////////
	class CherryBomb : public DisposablePlant
	{
	public:
		CherryBomb(CPoint);
		~CherryBomb() {}

		static const int price = 150;

	protected:
	};


	class PotatoMine : public DisposablePlant
	{
	public:
		PotatoMine(CPoint);
		~PotatoMine() {}

		static const int price = 25;

		void onMove() override;

	private:
		bool _isDetected = false;
	};

	class Squash : public DisposablePlant
	{
	public:
		Squash(CPoint);
		~Squash() {}

		static const int price = 50;
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Class of GenerateSunPlant
	//////////////////////////////////////////////////
	class SunFlower : public GenerateSunPlant
	{
	public:
		SunFlower(CPoint);
		~SunFlower() {}

		static const int price = 50;

		void generateSun(vector<Sun*>*) override;
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Class of ShootingPlant
	//////////////////////////////////////////////////
	class PeaShooter : public ShootingPlant
	{
	public:
		PeaShooter(CPoint);
		~PeaShooter() {}

		static const int price = 100;

		void attack(vector<Bullet*>*) override;
	};

	class SnowPea : public ShootingPlant
	{
	public:
		SnowPea(CPoint);
		~SnowPea() {}

		static const int price = 175;

		void attack(vector<Bullet*>*) override;
	};

	class PuffShroom : public ShootingPlant
	{
	public:
		PuffShroom(CPoint);
		~PuffShroom() {}

		static const int price = 0;

		void attack(vector<Bullet*>*) override;
	};
	//////////////////////////////////////////////////

	/*
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

	class Spikeweed : public Plant
	{
	public:
		Spikeweed();
		~Spikeweed();
	};

	class Threepeater : public Plant
	{
	public:
		Threepeater();
		~Threepeater();
	};
	*/
}
