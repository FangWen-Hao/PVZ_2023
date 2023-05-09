#include "stdafx.h"
#include "Plant.h"

using namespace game_framework;

PuffShroom::PuffShroom(CPoint pos) : ShootingPlant(PLANT::PUFF_SHROOM, PuffShroom::price, 7.5, 20, 1.5)
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
		if (!zombie->isDead() && zombie->row() == _row && zombie->col() != -1 &&
			zombie->right() <= RIGHT_TILES_POSITION_ON_MAP.at(_col + 3)) {
			hasZombieInAttackRange = true;
			break;
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
		new PuffShroomBullet(MIDDLE_TILES_POSITION_ON_MAP.at(_col), MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row), _damage, _col));
}
