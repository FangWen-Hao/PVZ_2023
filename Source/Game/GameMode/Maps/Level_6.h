#pragma once;
#include "../../Utils/GameModeConsts.h"
#include "../Map.h"
#include <vector>

namespace game_framework
{
	const vector<vector<int>> Level_6_zombie_instruction{
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// Normal & flag only

		// starting stream
		// {(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 0, 2, 0}, // tmp
		// {(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 60, 2, 0}, // tmp

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 30, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 50, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 70, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 90, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 110, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 130, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 131, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 132, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 150, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 151, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 180, 0, 0},

		// final wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 180, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 4, 0},
	};

	const string LEVEL_6_MSG_BITMAP = "Resources/Background/Level Up/BMP/Level2-1.bmp";

	class Level6 : public Map
	{
	public:
		Level6() : Map(Level_6_zombie_instruction, LEVEL_6_MSG_BITMAP, false) {};

		~Level6() {};

	protected:
		int getPreviousLevel() { return LEVEL_5; }
		int getCurrentLevel() { return LEVEL_6; }
		int getNextLevel() { return LEVEL_7; }
	};

}