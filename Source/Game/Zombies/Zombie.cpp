#include <StdAfx.h>
#include "Zombie.h"
#include "../Plants/Plant.h"

using namespace game_framework;

void Zombie::onInit(int row)
{
	_row = row;
	_posX = RIGHT_TILES_POSITION_ON_MAP.at(8);
	_posY = BOTTOM_LANE_POSITION_ON_SCREEN_MAP.at(_row) - normalAnimate.GetHeight();
}

void Zombie::onMove(vector<vector<Plant*>>* plants)
{
	if (_isSlow) moveCooldown.initCooldown(2 * (_moveSpeed / PX_PER_TILES));

    if (_hp <= 0 && !_isDead)
	{
		_isDead = true;
		deadAnimate.ToggleAnimation();
		slowDeadAnimate.ToggleAnimation();
	}
	else if (_isAttacking && !attackCooldown.isOnCooldown())
	{
		auto plant = (*plants)[_row][_col];
		if (plant) plant->beingAttack(_damage);
		attackCooldown.startCooldown();
	}
	else if (!_isAttacking && !_isDead && !moveCooldown.isOnCooldown()) {
		_posX -= 1;
		moveCooldown.startCooldown();
	}
	
	_updateCol();

	attackAnimate.SetTopLeft(_posX, _posY);
	normalAnimate.SetTopLeft(_posX, _posY);
	deadAnimate.SetTopLeft(_posX - 100, _posY - 25);

	slowAttackAnimate.SetTopLeft(_posX, _posY);
	slowNormalAnimate.SetTopLeft(_posX, _posY);
	slowDeadAnimate.SetTopLeft(_posX - 100, _posY - 25);
}

void Zombie::onShow()
{
	if (_isSlow)
	{
		if (_isDead)
			slowDeadAnimate.ShowBitmap();
		else if (_isAttacking)
			slowAttackAnimate.ShowBitmap();
		else
			slowNormalAnimate.ShowBitmap();
	}
	else
	{
		if (_isDead)
			deadAnimate.ShowBitmap();
		else if (_isAttacking)
			attackAnimate.ShowBitmap();
		else
			normalAnimate.ShowBitmap();
	}
}
