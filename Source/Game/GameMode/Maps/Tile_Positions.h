#pragma once
#include <map>

using namespace std;
namespace game_framework {
	// Day
		// Lane -> Y
		// 96 px per each

	const int PX_PER_LANE = 96;
	const int PX_PER_TILES = 80;

	const map<int, int> TOP_LANE_POSITION_ON_SCREEN_MAP = {
		{0, 90},
		{1, 187},
		{2, 284},
		{3, 381},
		{4, 478},
	};

	const map<int, int> MIDDLE_LANE_POSITION_ON_SCREEN_MAP = {
		{0, 138},
		{1, 235},
		{2, 332},
		{3, 429},
		{4, 526},
	};

	const map<int, int> BOTTOM_LANE_POSITION_ON_SCREEN_MAP = {
		{0, 186},
		{1, 283},
		{2, 380},
		{3, 477},
		{4, 574},
	};

		// Tiles -> X
		// 0 to 8 <=> Left to right
		// 80 px per each
	const map<int, int> LEFT_TILES_POSITION_ON_MAP = {
		{0, 50},
		{1, 131},
		{2, 212},
		{3, 293},
		{4, 374},
		{5, 455},
		{6, 536},
		{7, 617},
		{8, 698},
	};

	const map<int, int> MIDDLE_TILES_POSITION_ON_MAP = {
		{0, 90},
		{1, 171},
		{2, 252},
		{3, 333},
		{4, 414},
		{5, 495},
		{6, 576},
		{7, 657},
		{8, 738},
	};

	const map<int, int> RIGHT_TILES_POSITION_ON_MAP = {
		{0, 130},
		{1, 211},
		{2, 292},
		{3, 373},
		{4, 454},
		{5, 535},
		{6, 616},
		{7, 697},
		{8, 778},
	};
}