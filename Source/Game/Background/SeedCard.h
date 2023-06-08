#pragma once
#include "../../Library/gameutil.h"
#include"../Misc/Cooldown.h"

using namespace std;
namespace game_framework {
	const enum SEED_CARD_STATE : int {
		ALIVE,
		UNABLE,
		COOLDOWN_0, // full cooldown
		COOLDOWN_1, // 75%
		COOLDOWN_2, // 50%
		COOLDOWN_3, // 25%
	};

	const enum SEED_CARD_TYPE : int {
		REFUSED,
		PEA_SHOOTER,
		SUN_FLOWER,
		CHERRY_BOMB,
		WALL_NUT,
		POTATO_MINE,
		SNOW_PEA,
		CHOMPER,
		REPEATER_PEA,
		PUFF_SHROOM,
		SUN_SHROOM,
		HYPNO_SHROOM,
		SCAREDY_SHROOM,
		ICE_SHROOM,
		SQUASH,
		THREE_PEATER,
		JALAPENO,
		SPIKE_WEED,
		SHOVEL
	};
	
	class SeedCard : public CMovingBitmap
	{
	public:
		SeedCard();
		SeedCard(SeedCard *other);
		~SeedCard();
		void init(SEED_CARD_TYPE type, int price, int cooldown, vector<string> filePath, int offsetX, int offsetY);
		void show();
		void unshow();
		SEED_CARD_TYPE clicked();
		void resetCardPos();
		void used();
		void updateCooldown();
		void setCardPos(int x, int y);

		void invalidateCard();

		SEED_CARD_TYPE getType();
		int getPrice();
		bool isOnCooldown();
		void overrideCooldown() { _cooldown.overrideCooldown(); }

	private:
		SEED_CARD_TYPE _type;
		int _posX;
		int _posY;
		int _price;
		Cooldown _cooldown;
		vector<string> _filePath;

	};
}