#include <StdAfx.h>
#include "Zombie.h"
#include "../Plants/Plant.h"

using namespace game_framework;

void Zombie::onMove(vector<vector<Plant*>>* plants)
{
    if (_hp <= 0 && !_isDead)
	{
		_isDead = true;
		deadAnimate.ToggleAnimation();
	}
	else if (_isAttacking)
	{	
		if (!attackCooldown.isOnCooldown())
		{
			if ((*plants)[_row][_col] != nullptr)
				(*plants)[_row][_col]->begingAttack(_damage);
			attackCooldown.startCooldown();
		}
	}
	else if (!_isAttacking && !_isDead) {
		++_ttlMove %= _moveFrequency;

		if (_ttlMove == 0) _posX -= _speed;
	}
			
	_updateCol();

	attackAnimate.SetTopLeft(_posX, _posY);
	deadAnimate.SetTopLeft(_posX - 100, _posY - 25);
	normalAnimate.SetTopLeft(_posX, _posY);
}
