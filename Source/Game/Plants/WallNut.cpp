#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

WallNut::WallNut(CPoint pos) : DefensivePlant(PLANT::WALL_NUT, WallNut::price, 30)
{
	animate.LoadBitmapByString({
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_0.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_1.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_2.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_3.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_4.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_5.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_6.bmp",
		"Resources/Plants/WallNut/BMP/WallNut/WallNut_7.bmp",
	}, RGB(255, 255, 255));

	crackedAnimate1.LoadBitmapByString({
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_0.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_1.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_2.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_3.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_4.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_5.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_6.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked1/WallNut_cracked1_7.bmp",
	}, RGB(255, 255, 255));

	crackedAnimate2.LoadBitmapByString({
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_0.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_1.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_2.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_3.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_4.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_5.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_6.bmp",
		"Resources/Plants/WallNut/BMP/WallNut_cracked2/WallNut_cracked2_7.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	crackedAnimate1.SetAnimation(100, false);
	crackedAnimate2.SetAnimation(100, false);

	animate.SetTopLeft(pos.x, pos.y);
	crackedAnimate1.SetTopLeft(pos.x, pos.y);
	crackedAnimate2.SetTopLeft(pos.x, pos.y);

	_hp = 4000;
}

void WallNut::onShow()
{
	if (_hp <= brokenThreshold2)
	{
		crackedAnimate2.SetTopLeft(animate.GetLeft(), animate.GetTop());
		crackedAnimate2.ShowBitmap();
	}
	else if (_hp <= brokenThreshold1)
	{
		crackedAnimate1.SetTopLeft(animate.GetLeft(), animate.GetTop());
		crackedAnimate1.ShowBitmap();
	}
	else
	{
		animate.ShowBitmap();
	}
}
