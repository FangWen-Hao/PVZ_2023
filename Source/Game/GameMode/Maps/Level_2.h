#pragma once;
#include "../../Utils/GameModeConsts.h"
#include "../Map.h"
#include <vector>

namespace game_framework
{
	const vector<vector<int>> Level_2_zombie_instruction {
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// Normal, flag & newspaper

		// starting stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 30, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 50, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 70, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 90, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 110, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 130, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 131, 1, 0},
		// let the player build up and then introduce new enemy
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 132, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 150, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 151, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 180, 0, 0},

		// middle wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 0, 0},
		
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 182, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 184, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 182, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 182, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 4, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::WAIT, 220, 0, 0},

		// in-between stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 240, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 240, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 270, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 300, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 320, 0, 0},

		// final wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 320, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 322, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 320, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 322, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 324, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 320, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 322, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 320, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 322, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 324, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 320, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 322, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 324, 4, 0},
	};

	const string LEVEL_2_MSG_BITMAP = "Resources/Background/Level Up/BMP/Level1-2.bmp";

	class Level2 : public Map
	{
	public:
		Level2() : Map(Level_2_zombie_instruction, LEVEL_2_MSG_BITMAP, true) {};

		~Level2() {};

	protected:
		int getPreviousLevel() { return LEVEL_1; }
		int getCurrentLevel() { return LEVEL_2; }
		int getNextLevel() { return LEVEL_3; }
	};

}