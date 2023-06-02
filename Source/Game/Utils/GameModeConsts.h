#pragma once

namespace game_framework
{
	const enum MENU_BTN_STATE {
		MENU_NO_BTN_ACTION_REJECTED = -1,
		MENU_NO_BTN_ACTION_ACCEPTED,
		ADVENTURE_MODE_BTN,
		ABOUT_US,
		MENU_BTN,
		LEVEL_1,
		LEVEL_2,
		LEVEL_3,
		LEVEL_4,
		LEVEL_5,
		LEVEL_6, 
		LEVEL_7,
		LEVEL_8,
		LEVEL_9,
		LEVEL_10,
		LOADING,
	};

	const enum class ZOMBIE_INSTRUCTION_TYPE
	{
		WAIT = -2,
		WAVE_CHKPOINT = -1,
		EMPTY,
		NORMAL, // 1
		NEWSPAPER, // 2
		CONEHEAD, // 3
		BUCKETHEAD, // 4
		FLAG, // 5
		NEWSPAPERNOPAPER,
	};

	const map<int, int> LEVEL_SETS_BOUNDERIES
	{
		// indicates when a set starts
		// {set, starting level}
		{1, 1},
		{2, 6},
	};
}
