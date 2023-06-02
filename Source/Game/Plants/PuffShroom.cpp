#include "stdafx.h"
#include "Plant.h"
#include "../Utils/EntitiesUtil.h"

using namespace game_framework;

PuffShroom::PuffShroom(CPoint pos, bool isDay) : ShootingPlant(PLANT::PUFF_SHROOM, PuffShroom::price, 7.5, isDay, 20, 1.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/PuffShroom/BMP/PuffShroom_0.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_1.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_2.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_3.bmp",
		"Resources/Plants/PuffShroom/BMP/PuffShroom_4.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void PuffShroom::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies)
{
	Plant::onMove(bullets, suns, zombies);

	bool hasZombieInAttackRange = false;

	for (Zombie* zombie : *zombies) {
		if (findObjInVector(*zombies, zombie)
			&& !zombie->isDead() && zombie->row() == _row && zombie->col() != -1) {
			if (_col + 3 > 8)
			{
				hasZombieInAttackRange = true;
				break;
			}
			else if ((zombie->right() - zombie->width() / 2) <= RIGHT_TILES_POSITION_ON_MAP.at(_col + 3))
			{
				hasZombieInAttackRange = true;
				break;
			}
		}
	}

	if (hasZombieInAttackRange && !attackCooldown.isOnCooldown())
	{
		attack(bullets);
		attackCooldown.startCooldown();
	}
}

void PuffShroom::attack(vector<Bullet*>* bullets)
{
	bullets->push_back(
		new PuffShroomBullet(animate.GetLeft() + animate.GetWidth(), animate.GetTop(), _damage, _col));
}
