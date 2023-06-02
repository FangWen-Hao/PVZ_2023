#include "stdafx.h"
#include "Plant.h"
#include "../Misc/NormalSun.h"

using namespace game_framework;

SunFlower::SunFlower(CPoint pos, bool isDay) : GenerateSunPlant(PLANT::SUN_FLOWER, SunFlower::price, 7.5, false, isDay, 23.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/SunFlower/BMP/SunFlower_0.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_1.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_2.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_3.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_4.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_5.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_6.bmp",
		"Resources/Plants/SunFlower/BMP/SunFlower_7.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void SunFlower::generateSun(vector<Sun*>* suns)
{
	// Though players may be tempted to use Sunflowers in Night levels,
	// I would strongly recommend against it, though I will cover why later 
	// hen we talk about Sun-shrooms.
	// It should be noted that while Day Plants are awake
	// during both Night and Day levels, Night Plants will remain asleep
	// during Night levels, unless players use a Coffee Bean,
	// which is acquired much later in the series during the Roof levels.
	// https://basicallyaverage.com/plants-vs-zombies-complete-guide/

	suns->push_back(new NormalSun());
	suns->back()->init(
		animate.GetLeft(),
		animate.GetTop(),
		animate.GetTop() + animate.GetHeight());
}
