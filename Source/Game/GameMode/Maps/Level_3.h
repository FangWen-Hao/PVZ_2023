#pragma once;
#include "../../Utils/GameModeConsts.h"
#include "../Map.h"
#include <vector>

namespace game_framework
{
	const vector<vector<int>> Level_3_zombie_instruction{
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// Normal, flag, newspaper & cone

		// starting stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 30, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 50, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 70, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 90, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 110, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 130, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 131, 0, 0},
		// let the player build up and then introduce new enemy
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 132, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 150, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 151, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 180, 0, 0},

		// middle wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 184, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 182, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 180, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 182, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 4, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::WAIT, 220, 0, 0},

		// in-between stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 240, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 240, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 270, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 300, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 300, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 320, 0, 0},

		// final wave
		
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 330, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 332, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 334, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 336, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 330, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 332, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 334, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 330, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 332, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 334, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 330, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 332, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 334, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 336, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 330, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::CONEHEAD, 332, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 334, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 336, 4, 0},
	};

	const string LEVEL_3_MSG_BITMAP = "Resources/Background/Level Up/BMP/Level1-3.bmp";

	class Level3 : public Map
	{
	public:
		Level3() : Map(Level_3_zombie_instruction, LEVEL_3_MSG_BITMAP) {};

		~Level3() {};

	protected:
		int getPreviousLevel() { return LEVEL_2; }
		int getCurrentLevel() { return LEVEL_3; }
		int getNextLevel() { return LEVEL_4; }
	};

}