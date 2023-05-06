#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

FlagZombie::FlagZombie() : Zombie(ZOMBIE_TYPE::FLAG, 4, 0.04, 3.7)
{
	normalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_0.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_1.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_2.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_3.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_4.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_5.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_6.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_7.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_8.bmp",
		"Resources/Zombies/BMP/NormalState/FlagZombie/FlagZombie_9.bmp",
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
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_6.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_7.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_8.bmp",
		"Resources/Zombies/BMP/AttackState/FlagZombieAttack/FlagZombieAttack_9.bmp",
	}, RGB(255, 255, 255));

	slowNormalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_0.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_1.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_2.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_3.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_4.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_5.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_6.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_7.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_8.bmp",
		"Resources/Zombies/BMP/FrozenNormalState/FlagZombie/FlagZombie_9.bmp",
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
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_0.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_1.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_2.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_3.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_4.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_5.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_6.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_7.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_8.bmp",
		"Resources/Zombies/BMP/FrozenAttackState/FlagZombieAttack/FlagZombieAttack_9.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	attackAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);

	slowNormalAnimate.SetAnimation(100, false);
	slowAttackAnimate.SetAnimation(100, false);
	slowDeadAnimate.SetAnimation(100, true);

	_hp = 270;
}
