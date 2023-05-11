#pragma once;
#include "../../Utils/GameModeConsts.h"
#include "../Map.h"
#include <vector>

namespace game_framework
{
	const vector<vector<int>> Level_4_zombie_instruction{
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// Normal, flag, cone & buckethead

		// starting stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 30, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 50, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 70, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 90, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 110, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 130, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 131, 2, 0},
		// let the player build up and then introduce new enemy
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 132, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 150, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 151, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 180, 0, 0},

		// middle wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 182, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 182, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 180, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 184, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAIT, 220, 0, 0},

		// in-between stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 240, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 240, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 240, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 270, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 270, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 330, 0, 0},

		// final wave

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 330, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 332, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 334, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 330, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 332, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 334, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 336, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 330, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 332, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 334, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 336, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 330, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 332, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 334, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 336, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 330, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 332, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::BUCKETHEAD, 334, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 336, 4, 0},
	};

	const string LEVEL_4_MSG_BITMAP = "Resources/Background/Level Up/BMP/Level1-4.bmp";

	class Level4 : public Map
	{
	public:
		Level4() : Map(Level_4_zombie_instruction, LEVEL_4_MSG_BITMAP) {};

		~Level4() {};

	protected:
		int getPreviousLevel() { return LEVEL_3; }
		int getCurrentLevel() { return LEVEL_4; }
		int getNextLevel() { return LEVEL_5; }
	};

}