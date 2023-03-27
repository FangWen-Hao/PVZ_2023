#pragma once
#include "../../Library/gameutil.h"
#include"../Misc/Cooldown.h"

using namespace std;
namespace game_framework {
	const enum SEED_CARD : int {
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
		HYPNO_SHROOM,
		SCAREDY_SHROOM,
		ICE_SHROOM,
		SQUASH,
		THREE_PEATER,
		JALAPENO,
		SPIKE_WEED
	};
	
	class SeedCard : public CMovingBitmap
	{
	public:
		SeedCard();
		SeedCard(SeedCard *other);
		~SeedCard();
		void init(vector<string> filePath, int offsetX, int offsetY, int price, int cooldown, SEED_CARD type);
		void show();
		void unshow();
		SEED_CARD clicked();
		void resetCardPos();
		void used();
		void updateCooldown();
		void setCardPos(int x, int y);

		void invalidateCard();

		SEED_CARD getType();
		int getPrice();

	private:
		SEED_CARD _type;
		int _posX;
		int _posY;
		int _price;
		Cooldown _cooldown;
		vector<string> _filePath;

	};
}