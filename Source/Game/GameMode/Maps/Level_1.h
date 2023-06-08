#pragma once;
#include "../../Utils/GameModeConsts.h"
#include "../Map.h"
#include <vector>

namespace game_framework
{
	const vector<vector<int>> Level_1_zombie_instruction {
		// {zombie type, zombie time to spawn in seconds, zombie row pos, zombie has spawned}
		// Normal & flag only

		// starting stream
		// {(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 0, 2, 0}, // tmp
		// {(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 60, 2, 0}, // tmp

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 30, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 50, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 70, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 90, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 110, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 130, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 131, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 132, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 150, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 151, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::WAVE_CHKPOINT, 180, 0, 0},

		// final wave
		{(int)ZOMBIE_INSTRUCTION_TYPE::FLAG, 180, 0, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 0, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 1, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 1, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 2, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 2, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 3, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 3, 0},

		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 180, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 182, 4, 0},
		{(int)ZOMBIE_INSTRUCTION_TYPE::NORMAL, 184, 4, 0},
	};

	const string LEVEL_1_MSG_BITMAP = "Resources/Background/Level Up/BMP/Level1-1.bmp";

	class Level1 : public Map
	{
	public:
		Level1() : Map(Level_1_zombie_instruction, LEVEL_1_MSG_BITMAP, true) {};

		~Level1() {};

	protected:
		int getPreviousLevel() { return MENU_BTN; }
		int getCurrentLevel() { return LEVEL_1; }
		int getNextLevel() { return LEVEL_2; }
	};

}