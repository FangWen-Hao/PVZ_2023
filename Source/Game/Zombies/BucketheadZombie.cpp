#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

BucketheadZombie::BucketheadZombie()
{
	_type = ZOMBIE_TYPE::BUCKETHEAD;

	normalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_0.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_1.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_2.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_3.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_4.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_5.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_6.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_7.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_8.bmp",
		"Resources/Zombies/BMP/NormalState/BucketheadZombie/BucketheadZombie_9.bmp",
	}, RGB(255, 255, 255));

	/* images are missing
	deadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_0.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_1.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_2.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_3.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_4.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_5.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_6.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_7.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_8.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_9.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_10.bmp",
		"Resources/Zombies/BMP/DeadState/BucketheadZombieDie/BucketheadZombieDie_11.bmp",
	}, RGB(255, 255, 255));
	*/

	attackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_6.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_7.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_8.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_9.bmp",
		"Resources/Zombies/BMP/AttackState/BucketheadZombieAttack/BucketheadZombieAttack_10.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);
	attackAnimate.SetAnimation(100, false);

	_hp = 1370;
	_damage = 4;
	_attackFrequency = 1;
}

BucketheadZombie::~BucketheadZombie()
{
}
