#pragma once;
#include "../../Utils/GameModeConsts.h"
#include "../Map.h"
#include <vector>

namespace game_framework
{
	const vector<vector<int>> Level_7_zombie_instruction{
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// Normal, flag & newspaper

		// starting stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 30, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 50, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 70, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 90, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 110, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 130, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 131, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 132, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 150, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 151, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 180, 0, 0},

		// middle wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 180, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 0, 0},


		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 182, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 180, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 184, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 182, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 4, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::WAIT, 220, 0, 0},

		// in-between stream
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 220, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 240, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 240, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 270, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 270, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 300, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 300, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 320, 0, 0},

		// final wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 320, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NEWSPAPER, 322, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 320, 0, 0},
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

	const string LEVEL_7_MSG_BITMAP = "Resources/Background/Level Up/BMP/Level2-2.bmp";

	class Level7 : public Map
	{
	public:
		Level7() : Map(Level_7_zombie_instruction, LEVEL_7_MSG_BITMAP, false) {};

		~Level7() {};

	protected:
		int getPreviousLevel() { return LEVEL_6; }
		int getCurrentLevel() { return LEVEL_7; }
		int getNextLevel() { return LEVEL_8; }
	};

}