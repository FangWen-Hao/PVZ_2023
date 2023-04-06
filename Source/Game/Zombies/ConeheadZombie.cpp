#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

ConeheadZombie::ConeheadZombie()
{
	_type = ZOMBIE_TYPE::CONEHEAD;

	normalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_0.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_1.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_2.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_3.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_4.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_5.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_6.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_7.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_8.bmp",
		"Resources/Zombies/BMP/NormalState/ConeheadZombie/ConeheadZombie_9.bmp",
	}, RGB(255, 255, 255));

	/* images are missing
	deadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_0.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_1.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_2.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_3.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_4.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_5.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_6.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_7.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_8.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_9.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_10.bmp",
		"Resources/Zombies/BMP/DeadState/ConeheadZombieDie/ConeheadZombieDie_11.bmp",
	}, RGB(255, 255, 255));
	*/

	attackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_6.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_7.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_8.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_9.bmp",
		"Resources/Zombies/BMP/AttackState/ConeheadZombieAttack/ConeheadZombieAttack_10.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);
	attackAnimate.SetAnimation(100, false);

	_hp = 640;
	_damage = 4;
	_attackFrequency = 1;
}

ConeheadZombie::~ConeheadZombie()
{
}
