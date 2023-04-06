#pragma once
#include <map>

using namespace std;
namespace game_framework {
	// Day
		// Lane -> Y
	const map<int, int> TOP_LANE_POSITION_ON_SCREEN_MAP = {
		{0, 76},
		{1, 178},
		{2, 275},
		{3, 377},
		{4, 472},
	};

	const map<int, int> MIDDLE_LANE_POSITION_ON_SCREEN_MAP = {
		{0, 126},
		{1, 226},
		{2, 325},
		{3, 424},
		{4, 522},
	};

	const map<int, int> BOTTOM_LANE_POSITION_ON_SCREEN_MAP = {
		{0, 177},
		{1, 274},
		{2, 376},
		{3, 471},
		{4, 572},
	};

		// Tiles -> X
		// 0 to 8 <=> Left to right
	const map<int, int> LEFT_TILES_POSITION_ON_MAP = {
		{0, 47},
		{1, 132},
		{2, 209},
		{3, 296},
		{4, 373},
		{5, 454},
		{6, 535},
		{7, 614},
		{8, 693},
	};

	const map<int, int> MIDDLE_TILES_POSITION_ON_MAP = {
		{0, 89},
		{1, 170},
		{2, 252},
		{3, 334},
		{4, 413},
		{5, 494},
		{6, 574},
		{7, 653},
		{8, 733},
	};

	const map<int, int> RIGHT_TILES_POSITION_ON_MAP = {
		{0, 131},
		{1, 208},
		{2, 295},
		{3, 372},
		{4, 453},
		{5, 534},
		{6, 613},
		{7, 692},
		{8, 773},
	};
}