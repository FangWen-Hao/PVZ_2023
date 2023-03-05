#pragma once
#include "stdafx.h"
#include "../Library/gameutil.h"
#include "entity.h"


namespace game_framework {
	Entity::Entity() : CMovingBitmap() {};

	void Entity::UnshowBitmap()
	{
		visible = false;
		CMovingBitmap::UnshowBitmap();
	}

	void Entity::ShowBitmap()
	{
		visible = true;
		CMovingBitmap::ShowBitmap();
	}

	bool Entity::IsVisible()
	{
		return visible;
	}

	void Entity::SetFilterColor(COLORREF color)
	{
		filter_color = color;
	}
}