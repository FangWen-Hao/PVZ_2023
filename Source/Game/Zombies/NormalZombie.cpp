#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

NormalZombie::NormalZombie() : Zombie(ZOMBIE_TYPE::NORMAL, 4, 0.04, 4.7)
{
	normalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_0.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_1.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_2.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_3.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_4.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_5.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_6.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_7.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_8.bmp",
		"Resources/Zombies/BMP/NormalState/Zombie/Zombie_9.bmp",
	}, RGB(255, 255, 255));

	deadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_0.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_1.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_2.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_3.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_4.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_5.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_6.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_7.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_8.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_9.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_10.bmp",
		"Resources/Zombies/BMP/DeadState/ZombieDie/ZombieDie_11.bmp",
	}, RGB(255, 255, 255));

	attackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/ZombieAttack/ZombieAttack_6.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);
	attackAnimate.SetAnimation(100, false);

	_hp = 270;
}
