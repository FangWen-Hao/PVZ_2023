#include "stdafx.h"
#include "Plant.h"
#include "../Misc/Bullet/Bullet.h"

using namespace game_framework;

ScaredyShroom::ScaredyShroom(CPoint pos, bool isDay) : ShootingPlant(PLANT::SCAREDY_SHROOM, ScaredyShroom::price, 7.5, true, isDay, 20, 1.5)
{
	animate.LoadBitmapByString({
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_0.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_1.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_2.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_3.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_4.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_5.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_6.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_7.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_8.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_9.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_10.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_11.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_12.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_13.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_14.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_15.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroom/ScaredyShroom_16.bmp",
	}, RGB(255, 255, 255));

	sleepAnimate.LoadBitmapByString({
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_0.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_1.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_2.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_3.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_4.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_5.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_6.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_7.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_8.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_9.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_10.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_11.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_12.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_13.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_14.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomSleep/ScaredyShroomSleep_15.bmp",
	}, RGB(255, 255, 255));

	cryAnimate.LoadBitmapByString({
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_0.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_1.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_2.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_3.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_4.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_5.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_6.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_7.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_8.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_9.bmp",
		"Resources/Plants/ScaredyShroom/BMP/ScaredyShroomCry/ScaredyShroomCry_10.bmp",
	}, RGB(255, 255, 255));

	animate.SetAnimation(100, false);
	animate.SetTopLeft(pos.x, pos.y);

	sleepAnimate.SetAnimation(100, false);
	sleepAnimate.SetTopLeft(pos.x, pos.y);

	cryAnimate.SetAnimation(100, false);
	cryAnimate.SetTopLeft(pos.x, pos.y);

	_hp = 300;
}

void ScaredyShroom::PlaceDown(int row, int col)
{
	ShootingPlant::PlaceDown(row, col);
	cryAnimate.SetTopLeft(animate.GetLeft(), animate.GetTop());
}

void ScaredyShroom::onMove(vector<Bullet*>* bullets, vector<Sun*>* suns, vector<Zombie*>* zombies) {
	Plant::onMove(bullets, suns, zombies);

	if (_isNightPlant && _isDay) return;

	bool hasZombieInRow = false;

	for (Zombie* zombie : *zombies) {
		if (!findObjInVector(*zombies, zombie)) continue;

		int zombieRow = zombie->row();
		int zombieCol = zombie->col();

		if (!zombie->isDead() && zombieRow >= _row - 1 && zombieRow <= _row + 1 &&
			zombieCol >= _col - 1 && zombieCol <= _col + 1)
		{
			isCrying = true;
			break;
		}

		if (zombieRow == _row)
			hasZombieInRow = true;
	}

	if (!isCrying && hasZombieInRow && !attackCooldown.isOnCooldown())
	{
		attack(bullets);
		attackCooldown.startCooldown();
	}
}

void ScaredyShroom::onShow()
{
	if (_isPlaceDown && _isNightPlant && _isDay)
		sleepAnimate.ShowBitmap();
	else if (isCrying)
		cryAnimate.ShowBitmap();
	else
		animate.ShowBitmap();
}

void ScaredyShroom::attack(vector<Bullet*>* bullets)
{
	if (_isNightPlant && _isDay) return;
	bullets->push_back(
		new ShroomBullet(animate.GetLeft() + animate.GetWidth(), animate.GetTop(), _damage));
}
