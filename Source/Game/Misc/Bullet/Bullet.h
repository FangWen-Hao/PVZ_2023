#pragma once

#include "../../../Library/gameutil.h"

namespace game_framework
{
	enum class BULLET {
		
	};

	class Bullet : public CMovingBitmap
	{
	public:
		virtual void onMove()
		{
			SetTopLeft(GetLeft() + 2, GetTop());
		}
		virtual void onShow(double factor = 1)
		{
			ShowBitmap(factor);
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
}
