#pragma once;
#include "../../Zombies/Zombie.h"

namespace game_framework {

	static vector<vector<int>> DEMO {
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		{(int)ZOMBIE_TYPE::NORMAL, 10, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 11, 0, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 13, 1, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 15, 3, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 16, 4, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 18, 2, 0},
	};
}