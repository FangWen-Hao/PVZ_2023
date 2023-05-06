#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

NewpaperZombieNoPaper::NewpaperZombieNoPaper() : Zombie(ZOMBIE_TYPE::NEWSPAPERNOPAPER, 4, 0.04, 1.8)
{
	normalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_0.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_1.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_2.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_3.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_4.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_5.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_6.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_7.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_8.bmp",
		"Resources/Zombies/BMP/NormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_9.bmp",
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
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_6.bmp",
	}, RGB(255, 255, 255));

	slowNormalAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_0.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_1.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_2.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_3.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_4.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_5.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_6.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_7.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_8.bmp",
		"Resources/Zombies/BMP//FrozenNormalState/NewspaperZombieNoPaper/NewspaperZombieNoPaper_9.bmp",
	}, RGB(255, 255, 255));

	slowDeadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_0.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_1.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_2.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_3.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_4.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_5.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_6.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_7.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_8.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_9.bmp",
		"Resources/Zombies/BMP//FrozenDeadState/NewspaperZombieDie/NewspaperZombieDie_10.bmp",
	}, RGB(255, 255, 255));

	slowAttackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_0.bmp",
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_1.bmp",
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_2.bmp",
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_3.bmp",
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_4.bmp",
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_5.bmp",
		"Resources/Zombies/BMP//FrozenAttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_6.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	attackAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);

	slowNormalAnimate.SetAnimation(100, false);
	slowAttackAnimate.SetAnimation(100, false);
	slowDeadAnimate.SetAnimation(100, true);

	_hp = 270;
}
