#include "stdafx.h"
#include "Zombie.h"
#include "../Plants/Plant.h"

using namespace game_framework;

void Zombie::attack(Plant* plant)
{
	if (_isAttacking) {
		duration<double> duration_time = duration_cast<duration<double>>(high_resolution_clock::now() - lastAttackTime);

		if (duration_time.count() >= _attackSpeed) {
			plant->beginAttack(_damage);
			lastAttackTime = high_resolution_clock::now();
		}
	}
}