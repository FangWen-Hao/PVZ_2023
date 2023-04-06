#include "stdafx.h"
#include "Zombie.h"

using namespace game_framework;

NewpaperZombieNoPaper::NewpaperZombieNoPaper()
{
	_type = ZOMBIE_TYPE::NEWSPAPERNOPAPER;

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

	/* images are missing
	deadAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_0.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_1.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_2.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_3.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_4.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_5.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_6.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_7.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_8.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_9.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_10.bmp",
		"Resources/Zombies/BMP/DeadState/NewspaperZombieNoPaperDie/ZombieDie_11.bmp",
	}, RGB(255, 255, 255));
	*/

	attackAnimate.LoadBitmapByString({
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_0.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_1.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_2.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_3.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_4.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_5.bmp",
		"Resources/Zombies/BMP/AttackState/NewspaperZombieNoPaperAttack/NewspaperZombieNoPaperAttack_6.bmp",
	}, RGB(255, 255, 255));

	normalAnimate.SetAnimation(100, false);
	deadAnimate.SetAnimation(100, true);
	attackAnimate.SetAnimation(100, false);

	_hp = 100;
	_speed = 1;
	_damage = 1;
	_moveFrequency = 10;
}

NewpaperZombieNoPaper::~NewpaperZombieNoPaper()
{
}
