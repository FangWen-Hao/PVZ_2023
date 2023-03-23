#pragma once
#include "../Terrain/Lane.h"
#include <string>
#include <ctime>

using namespace std;
namespace game_framework {
	class Plant
	{
	public:
		Plant() {};
		~Plant() {};

		virtual void setLane(Lane* lane) { _currentLane = lane; }
		virtual string getType() { return _type; }
		virtual void attack() = 0;
		virtual int getCurrentHp() { return _hp; }

	private:
		Lane *_currentLane;
		string _type;
		int secondsCoolDown;
		time_t lastAttackTime;
		int _hp;
		int damage;
	};
}