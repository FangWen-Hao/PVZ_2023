#pragma once;
#include "../../Zombies/Zombie.h"

namespace game_framework {

	static vector<vector<int>> DEMO {
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// for testing
		{(int)ZOMBIE_TYPE::NORMAL, 1, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 2, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 3, 2, 0},

		{(int)ZOMBIE_TYPE::NORMAL, 30, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 50, 0, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 70, 1, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 90, 3, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 110, 4, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 130, 0, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 131, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 132, 4, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 150, 1, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 151, 3, 0},

		// final wave
		{(int)ZOMBIE_TYPE::NORMAL, 180, 0, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 181, 1, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 182, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 183, 3, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 184, 4, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 185, 1, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 186, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 187, 3, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 188, 4, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 189, 0, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 190, 2, 0},
		{(int)ZOMBIE_TYPE::NORMAL, 191, 4, 0},
	};
}