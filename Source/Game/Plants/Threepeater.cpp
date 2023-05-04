#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

Threepeater::Threepeater(CPoint pos) : ShootingPlant(PLANT::PEA_SHOOTER, PeaShooter::price, 7.5, 20, 1.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/Threepeater/BMP/Threepeater_0.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_1.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_2.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_3.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_4.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_5.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_6.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_7.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_8.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_9.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_10.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_11.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_12.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_13.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_14.bmp",
		"Resources/Plants/Threepeater/BMP/Threepeater_15.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void Threepeater::attack(vector<Bullet*>* bullets)
{
	bullets->push_back(
		new PeaShooterBullet(MIDDLE_TILES_POSITION_ON_MAP.at(_col), MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row - 1), _damage));
	bullets->push_back(
		new PeaShooterBullet(MIDDLE_TILES_POSITION_ON_MAP.at(_col), MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row), _damage));
	bullets->push_back(
		new PeaShooterBullet(MIDDLE_TILES_POSITION_ON_MAP.at(_col), MIDDLE_LANE_POSITION_ON_SCREEN_MAP.at(_row + 1), _damage));
}

void Threepeater::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies) {
	Plant::onMove(bullets, suns, zombies);

	bool hasZombieInRow = false;

	for (Zombie* zombie : *zombies) {
		if (zombie->row() == _row - 1 ||
			zombie->row() == _row ||
			zombie->row() == _row + 1) {
			hasZombieInRow = true;
			break;
		}
	}

	if (hasZombieInRow && !attackCooldown.isOnCooldown())
	{
		attack(bullets);
		attackCooldown.startCooldown();
	}
}