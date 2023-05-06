#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

BucketheadZombie::BucketheadZombie() : Zombie(ZOMBIE_TYPE::BUCKETHEAD, 4, 0.04, 4.7)
{
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

	slowNormalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_0.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_1.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_2.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_3.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_4.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_5.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_6.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_7.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_8.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/BucketheadZombie/BucketheadZombie_9.bmp",
	}, RGB(255, 255, 255));

	slowDeadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_0.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_1.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_2.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_3.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_4.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_5.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_6.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_7.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_8.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_9.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_10.bmp",
		"Resources/Zombies/BMP/FrozenDeadState/ZombieDie/ZombieDie_11.bmp",
	}, RGB(255, 255, 255));

	slowAttackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_0.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_1.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_2.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_3.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_4.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_5.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_6.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_7.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_8.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_9.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/BucketheadZombieAttack/BucketheadZombieAttack_10.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	attackAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);

	slowNormalAnimate.SetAnimation(100, false);
	slowAttackAnimate.SetAnimation(100, false);
	slowDeadAnimate.SetAnimation(100, true);

	_hp = 1370;
}
