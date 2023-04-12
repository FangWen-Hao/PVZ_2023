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
	};

	class PeaShooterBullet : public Bullet
	{
	public:
		PeaShooterBullet(int, int);
		~PeaShooterBullet();
	};
}
