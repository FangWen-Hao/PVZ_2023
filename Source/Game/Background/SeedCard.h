#pragma once
#include "../../Library/gameutil.h"
#include"../Misc/Cooldown.h"

using namespace std;
namespace game_framework {
	const enum SEED_CARD_PLANTS {
		SEED_CARD_REFUSED,
		SEED_CARD_PEA_SHOOTER,
		SEED_CARD_SUN_FLOWER,
		SEED_CARD_CHERRY_BOMB,
		SEED_CARD_WALL_NUT,
		SEED_CARD_POTATO_MINE,
		SEED_CARD_SNOW_PEA,
		SEED_CARD_CHOMPER,
		SEED_CARD_REPEATER_PEA,
		SEED_CARD_PUFF_SHROOM,
		SEED_CARD_HYPNO_SHROOM,
		SEED_CARD_SCAREDY_SHROOM,
		SEED_CARD_ICE_SHROOM,
		SEED_CARD_SQUASH,
		SEED_CARD_THREE_PEATER,
		SEED_CARD_JALAPENO,
		SEED_CARD_SPIKE_WEED
	};

	/*
	const int SEED_CARD_REFUSED = -1;
	const int SEED_CARD_PEA_SHOOTER = 1;
	const int SEED_CARD_SUN_FLOWER = 2;
	const int SEED_CARD_CHERRY_BOMB = 3;
	const int SEED_CARD_WALL_NUT = 4;
	const int SEED_CARD_POTATO_MINE = 5;
	const int SEED_CARD_SNOW_PEA = 6;
	const int SEED_CARD_CHOMPER = 7;
	const int SEED_CARD_REPEATER_PEA = 8;
	const int SEED_CARD_PUFF_SHROOM = 9;
	const int SEED_CARD_SUN_SHROOM = 10;
	const int SEED_CARD_HYPNO_SHROOM = 13;
	const int SEED_CARD_SCAREDY_SHROOM = 14;
	const int SEED_CARD_ICE_SHROOM = 15;
	const int SEED_CARD_SQUASH = 18;
	const int SEED_CARD_THREE_PEATER = 19;
	const int SEED_CARD_JALAPENO = 21;
	const int SEED_CARD_SPIKE_WEED = 22;
	*/

	
	class SeedCard : public CMovingBitmap
	{
	public:
		SeedCard();
		SeedCard(SeedCard *other);
		~SeedCard();
		void init(vector<string> filePath, int offsetX, int offsetY, string price, string cooldown, int name);
		void show();
		void unshow();
		int clicked();
		void resetCardPos();
		void used();
		void updateCooldown();
		void setCardPos(int x, int y);

		void invalidateCard();

		int getName();
		int getPrice();;

	private:
		int _name;
		int _posX;
		int _posY;
		int _price;
		Cooldown _cooldown;
		vector<string> _filePath;

	};
}