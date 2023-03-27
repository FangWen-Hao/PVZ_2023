#pragma once

#include "../Zombies/Zombie.h"

using namespace std;
namespace game_framework {
	class Lane
	{
	public:
		Lane();
		~Lane();

		void setTiles(vector<Tile*> tiles);
		void addZombie(Zombie* zombie);
		void activateLawnMowner();
		void doesLawnMownerExist();


	private:
		vector<Tile*> _tiles;
		vector<Zombie*> _zombies;
		// Lawnmowner* _lawnMowner;
	};
}