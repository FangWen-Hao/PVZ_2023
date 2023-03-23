#pragma once
#include "Plant.h"

using namespace game_framework {
	class GrassPlant : public Plant
	{
		GrassPlant() { _type = "Grass"; }
	};
}