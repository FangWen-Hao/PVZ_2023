#pragma once

#include "../../../Library/gameutil.h"
#include "../../Zombies/Zombie.h"

namespace game_framework
{
	enum class BULLET {
		
	};

	class Bullet : public CMovingBitmap
	{
	public:
		~Bullet() {}

		bool isOutOfRange() { return outOfRange; }
		virtual void onMove() {
			SetTopLeft(GetLeft() + 5, GetTop());
			if (GetLeft() >= 900) outOfRange = true;
		}
		virtual void onShow(double factor = 1) { ShowBitmap(factor); }
		virtual bool detectCollison(vector<Zombie*>* zombies) {
			for (Zombie* zombie : *zombies) {
				if (!zombie->isDead() && 
					GetLeft() < zombie->right() && (GetLeft() + GetWidth()) > zombie->left() &&
					GetTop() < zombie->bottom() && (GetTop() + GetHeight()) > zombie->top()) {
					zombie->beingAttacked(_damage);
					return true;
				}
			}
			return false;
		}

	protected:
		Bullet(int damage) : _damage(damage) {}
		const int _damage;
		bool outOfRange = false;
	};

	class PeaShooterBullet : public Bullet
	{
	public:
		PeaShooterBullet(int, int, int);
		~PeaShooterBullet() {}
	};

	class SnowPeaBullet : public Bullet
	{
	public:
		SnowPeaBullet(int, int, int);
		~SnowPeaBullet() {}

		bool detectCollison(vector<Zombie*>*) override;
	};

	class ShroomBullet : public Bullet
	{
	public:
		ShroomBullet(int, int, int);
		~ShroomBullet() {}
	};

	class PuffShroomBullet : public ShroomBullet
	{
	public:
		PuffShroomBullet(int, int, int, int);
		~PuffShroomBullet() {}
	private:
		void onMove() override;

		int _plantCol;
	};
}
