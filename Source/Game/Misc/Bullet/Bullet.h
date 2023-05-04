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
		virtual void onMove()
		{
			SetTopLeft(GetLeft() + 5, GetTop());
		}
		virtual void onShow(double factor = 1)
		{
			ShowBitmap(factor);
		}
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
		int _damage = 0;
	};

	class PeaShooterBullet : public Bullet
	{
	public:
		PeaShooterBullet(int, int, int);
		~PeaShooterBullet();
	};

	class SnowPeaBullet : public Bullet
	{
	public:
		SnowPeaBullet(int, int, int);
		~SnowPeaBullet();
	};

	class PuffShroomBullet : public Bullet
	{
	public:
		PuffShroomBullet(int, int, int);
		~PuffShroomBullet();
	};
}
