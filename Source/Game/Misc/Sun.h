#pragma once
#include "../../Library/gameutil.h"
#include "Cooldown.h"

namespace game_framework
{
	enum Sun_status
	{
		INVALID = -1,
		VALID = 0
	};

	class Sun : public CMovingBitmap
	{
	public:
		Sun();
		~Sun() {};

		virtual void init(int posX, int startingPosY, int finalPosY);
		virtual void show();
		virtual void unshow();
		virtual int update();

		virtual int getValue() { return _value; };

	protected:
		static const int TOP_SPAWN_LOCATION = 50; // WIP
		int _value;
		int dropRatePerUpdate;
		int _posX;
		int _finalPosY;
		Cooldown lifespan;

	private:
		virtual void initiateBitMap() = 0;
		virtual void initiateSunValue() = 0;
		virtual int getLifeSpan() = 0;
	};
}