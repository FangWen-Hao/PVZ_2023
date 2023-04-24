#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

NewspaperZombie::NewspaperZombie() : Zombie(ZOMBIE_TYPE::NEWSPAPER, 4, 0.04)
{
	normalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_0.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_1.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_2.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_3.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_4.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_5.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_6.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_7.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_8.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombie/NewspaperZombie_9.bmp",
	}, RGB(255, 255, 255));

	deadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_0.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_1.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_2.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_3.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_4.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_5.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_6.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_7.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_8.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_9.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieDie/NewspaperZombieDie_10.bmp",
	}, RGB(255, 255, 255));

	attackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_6.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieAttack/NewspaperZombieAttack_7.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);
	attackAnimate.SetAnimation(100, false);

	_hp = 270;
}
