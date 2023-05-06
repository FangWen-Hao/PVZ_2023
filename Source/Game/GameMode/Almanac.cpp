#include "stdafx.h"
#include "Almanac.h"

namespace game_framework {
	Almanac::Almanac()
	{
	}

	Almanac::~Almanac()
	{
	}

	void Almanac::init()
	{
		background.init(ALMANAC_BG_PATH);
	}

	void Almanac::show()
	{
		background.show();
	}

	void Almanac::OnMove()
	{

	}

	void Almanac::OnHover(CPoint coords)
	{
	}

	int Almanac::OnLClick(CPoint coords)
	{
		return 0;
	}

	int Almanac::OnRClick(CPoint coords)
	{
		return 0;
	}
}
