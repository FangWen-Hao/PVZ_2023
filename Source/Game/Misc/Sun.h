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
		Sun() { lifespan.setCooldown(disappearAfterXSeconds); };
		~Sun() {};

		virtual void init(int finalPosX, int finalPosY) = 0;
		virtual void show();
		virtual void unshow();
		virtual int update();

		virtual int getValue() { return _value; };

	protected:
		static const int TOP_SPAWN_LOCATION = 50; // WIP
		int _value;
		int _finalPosX;
		int _finalPosY;
		Cooldown lifespan;

	private:
		static const int disappearAfterXSeconds = 30;
	};
}