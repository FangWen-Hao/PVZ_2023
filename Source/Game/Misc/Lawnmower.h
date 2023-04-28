#pragma once
#include "../../Library/gameutil.h"

namespace game_framework
{
	const vector<string> LAWNMOWER_BITMAP{
		"Resources/Misc/Landmower/BMP/car.bmp",
	};

	const int LAWNMOWER_MOVEMENT_SPEED = 5;

	class Lawnmower
	{
	public:
		Lawnmower() {};
		~Lawnmower() {};
		void init(int row);
		void show();
		void activate();
		bool isActive();
		void move();
		bool isDone();

		int getRow();
		int getRight();


	protected:
		int _row;
		bool active;
		CMovingBitmap bitmap;
	};
}