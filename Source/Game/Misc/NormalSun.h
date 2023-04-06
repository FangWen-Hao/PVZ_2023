#pragma once
#include "Sun.h"
#include <vector>
#include <string>

using namespace std;
namespace game_framework
{
	const vector<string> BITMAP_FILE_PATHS = {
			"Resources/Plants/Sun/BMP/Sun0.bmp",
			"Resources/Plants/Sun/BMP/Sun1.bmp",
			"Resources/Plants/Sun/BMP/Sun2.bmp",
			"Resources/Plants/Sun/BMP/Sun3.bmp",
			"Resources/Plants/Sun/BMP/Sun4.bmp",
			"Resources/Plants/Sun/BMP/Sun5.bmp",
			"Resources/Plants/Sun/BMP/Sun6.bmp",
			"Resources/Plants/Sun/BMP/Sun7.bmp"
	};

	const int NORMAL_SUN_VALUE = 25;

	class NormalSun : public Sun
	{
	public:
		void init(int finalPosX, int finalPosY);
	};
}