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

	void Almanac::OnHover(CPoint coords)
	{
	}

	int Almanac::OnClick(CPoint coords)
	{
		return 0;
	}
}
