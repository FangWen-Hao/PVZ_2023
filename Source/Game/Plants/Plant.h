#pragma once

#include <vector>
#include <algorithm>
#include "../../Library/gameutil.h"
#include "../Misc/Cooldown.h"
#include "../Misc/Sun.h"
#include "../Zombies/Zombie.h"
#include "../Misc/Bullet/Bullet.h"
#include "../Utils/Soundboard.h"

using namespace std;

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
		virtual ~Plant() {}

		PLANT_TYPE type() { return _type; }
		PLANT name() { return _name; }

		int price() { return _price; }
		int width() { return animate.GetWidth(); }
		int height() { return animate.GetHeight(); }
		int top() { return animate.GetTop(); }
		int left() { return animate.GetLeft(); }
		int right() { return left() + width(); }
		int bottom() { return top() + height(); }
		int row() { return _row; }
		int col() { return _col; }

		bool isDead() { return _isDead; }

		void SetTopLeft(CPoint pos) { animate.SetTopLeft(pos.x, pos.y); }
		void beingAttack(int damage) { _hp -= damage; }

		virtual void PlaceDown(int row, int col)
		{
			_row = row;
			_col = col;

			animate.SetTopLeft(MIDDLE_TILES_POSITION_ON_MAP.at(col) - width() / 2,
				MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(row) - height() / 2);
			if (_isNightPlant)
				sleepAnimate.SetTopLeft(MIDDLE_TILES_POSITION_ON_MAP.at(col) - width() / 2,
					MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(row) - height() / 2);

			_isPlaceDown = true;
		}
		virtual void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) { if (_hp < 0) _isDead = true; }
		virtual void onShow() {
			if (_isNightPlant && _isDay) sleepAnimate.ShowBitmap();
			else animate.ShowBitmap();
		}

	protected:
		Plant(const PLANT_TYPE type, const PLANT name, const int price, const double coolDown, const bool isNightPlant, const bool isDay)
			: _type(type), _name(name), _price(price), _coolDown(coolDown), _isNightPlant(isNightPlant), _isDay(isDay) {}

		const PLANT_TYPE _type;
		const PLANT _name;
		const int _price;
		const double _coolDown;
		const bool _isNightPlant;

		int _hp;
		int _row;
		int _col;
		bool _isDay;
		bool _isDead = false;
		bool _isPlaceDown = false;

		CMovingBitmap animate;
		CMovingBitmap sleepAnimate;
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Classes of Plant
	//////////////////////////////////////////////////
	class DefensivePlant : public Plant
	{
	protected:
		DefensivePlant(const PLANT name, const int price, const int coolDown, const bool isNightPlant, const bool isDay)
			: Plant(PLANT_TYPE::DEFENSIVE, name, price, coolDown, isNightPlant, isDay) {}
		virtual ~DefensivePlant() {}
	};

	class DisposablePlant : public Plant
	{
	protected:
		DisposablePlant(const PLANT name, const int price, const double coolDown, const bool isNightPlant, const bool isDay, const int damage, const int perpareTime)
			: Plant(PLANT_TYPE::DISPOSABLE, name, price, coolDown, isNightPlant, isDay), _damage(damage), _perpareTime(perpareTime)
		{
			readyClock.initCooldown(_perpareTime);
		}
		virtual ~DisposablePlant() {}

		virtual void PlaceDown(int row, int col) override {
			Plant::PlaceDown(row, col);
			readyClock.startCooldown();
		}

		const int _damage;
		const int _perpareTime;

		bool isReady = false;
		Cooldown readyClock;
	};

	class GenerateSunPlant : public Plant
	{
	public:
		virtual void generateSun(vector<Sun*>*) = 0;

		virtual void onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies) override {
			Plant::onMove(bullets, suns, zombies);

			if (!generateCooldown.isOnCooldown())
			{
				generateSun(suns);
				generateCooldown.startCooldown();
			}
		}

		virtual void PlaceDown(int row, int col) override {
			Plant::PlaceDown(row, col);

			generateCooldown.startCooldown();
		}

	protected:
		GenerateSunPlant(const PLANT name, const int price, const double coolDown, const bool isNightPlant, const bool isDay, const double generateSpeed)
			: Plant(PLANT_TYPE::GENERATE_SUN, name, price, coolDown, isNightPlant, isDay), _generateSpeed(generateSpeed)
		{
			generateCooldown.initCooldown(generateSpeed);
		}
		virtual ~GenerateSunPlant() {}

		const double _generateSpeed;
		Cooldown generateCooldown;
	};

	class ShootingPlant : public Plant
	{
	public:
		virtual void attack(vector<Bullet*>*) = 0;

		virtual void onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies) override {
			Plant::onMove(bullets, suns, zombies);

			bool hasZombieInRow = false;

			for (Zombie* zombie : *zombies) {
				if (findObjInVector(*zombies, zombie) &&
					!zombie->isDead() && zombie->row() == _row && zombie->col() >= _col) {
					hasZombieInRow = true;
					break;
				}
			}

			if (hasZombieInRow && !attackCooldown.isOnCooldown())
			{
				attack(bullets);
				attackCooldown.startCooldown();
			}
		}

		virtual void PlaceDown(int row, int col) override {
			Plant::PlaceDown(row, col);
			attackCooldown.startCooldown();
		}

	protected:
		ShootingPlant(const PLANT name, const int price, const double coolDown, const bool isNightPlant, const bool isDay, const int damage, const double attackSpeed)
			: Plant(PLANT_TYPE::SHOOTING, name, price, coolDown, isNightPlant, isDay), _damage(damage), _attackSpeed(attackSpeed)
		{
			attackCooldown.initCooldown(_attackSpeed);
		}
		virtual ~ShootingPlant() {}

		const int _damage;
		const double _attackSpeed;
		Cooldown attackCooldown;
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Class of DefensivePlant
	//////////////////////////////////////////////////
	class WallNut : public DefensivePlant
	{
	public:
		WallNut(CPoint, bool);
		virtual ~WallNut() {}

		static const int price = 50;

		void onShow() override;
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
		CherryBomb(CPoint, bool);
		virtual ~CherryBomb() {}

		static const int price = 150;

		void PlaceDown(int, int) override;
		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
		void onShow() override;
	protected:
		bool isBoom = false;
		CMovingBitmap boomAnimate;
	};


	class PotatoMine : public DisposablePlant
	{
	public:
		PotatoMine(CPoint, bool);
		virtual ~PotatoMine() {}

		static const int price = 25;

		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
	private:
		bool isBoom = false;
	};

	class Squash : public DisposablePlant
	{
	public:
		Squash(CPoint, bool);
		virtual ~Squash() {}

		static const int price = 50;

		void PlaceDown(int, int) override;
		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
		void onShow() override;
	private:
		bool isActivate = false;
		CMovingBitmap activeAnimate;
	};

	class Jalapeno : public DisposablePlant
	{
	public:
		Jalapeno(CPoint, bool);
		virtual ~Jalapeno() {}

		static const int price = 125;

		void PlaceDown(int, int) override;
		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
		void onShow() override;
	private:
		bool isExplode = false;
		CMovingBitmap explodeAnimate;
	};

	class IceShroom : public DisposablePlant
	{
	public:
		IceShroom(CPoint, bool);
		virtual ~IceShroom() {}

		static const int price = 75;

		void PlaceDown(int, int) override;
		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
		void onShow() override;
	private:
		int _freezeTime;
		int _slowTime;
	};

	class HypnoShroom : public DisposablePlant
	{
	public:
		HypnoShroom(CPoint, bool);
		virtual ~HypnoShroom() {}

		static const int price = 75;
		void PlaceDown(int, int) override;
	};
	//////////////////////////////////////////////////



	//////////////////////////////////////////////////
	// Inheritance Class of GenerateSunPlant
	//////////////////////////////////////////////////
	class SunFlower : public GenerateSunPlant
	{
	public:
		SunFlower(CPoint, bool);
		virtual ~SunFlower() {}

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
		PeaShooter(CPoint, bool);
		virtual ~PeaShooter() {}

		static const int price = 100;

		void attack(vector<Bullet*>*) override;
	};

	class RepeaterPea : public ShootingPlant
	{
	public:
		RepeaterPea(CPoint, bool);
		virtual ~RepeaterPea() {}

		static const int price = 200;

		void attack(vector<Bullet*>*) override;
	};

	class Threepeater : public ShootingPlant
	{
	public:
		Threepeater(CPoint, bool);
		virtual ~Threepeater() {}

		static const int price = 325;

		void attack(vector<Bullet*>*) override;
		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
	};

	class SnowPea : public ShootingPlant
	{
	public:
		SnowPea(CPoint, bool);
		virtual ~SnowPea() {}

		static const int price = 175;

		void attack(vector<Bullet*>*) override;
	};

	class PuffShroom : public ShootingPlant
	{
	public:
		PuffShroom(CPoint, bool);
		virtual ~PuffShroom() {}

		static const int price = 0;

		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
		void attack(vector<Bullet*>*) override;
	};

	class ScaredyShroom : public ShootingPlant
	{
	public:
		ScaredyShroom(CPoint, bool);
		virtual ~ScaredyShroom() {}

		static const int price = 25;

		void PlaceDown(int, int) override;
		void onMove(vector<Bullet*>*, vector<Sun*>*, vector<Zombie*>*) override;
		void onShow() override;
		void attack(vector<Bullet*>*) override;
	private:
		bool isCrying = false;
		CMovingBitmap cryAnimate;
	};
	//////////////////////////////////////////////////

	/*
	class Chomper : public Plant
	{
	public:
		Chomper(CPoint, bool);
		virtual ~Chomper();
	};

	class Spikeweed : public Plant
	{
	public:
		Spikeweed(CPoint, bool);
		virtual ~Spikeweed();
	};
	*/
}
