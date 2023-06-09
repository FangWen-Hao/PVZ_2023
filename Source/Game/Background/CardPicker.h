#pragma once
#include "SeedCard.h"
#include "../Plants/Plant.h" // this is here so we can use the static consts.
#include <map>

using namespace std;
namespace game_framework
{
	class CardPicker
	{
	public:
		CardPicker();
		~CardPicker();

		int GetLeft();
		int GetWidth();
		int GetTop();
		int GetHeight();

		void init();
		void show();
		void unshow();
		void OnHover(CPoint coords);
		SeedCard* OnClick(CPoint coords);


	private:
		const int LEFT = 75;
		const int TOP = 99;
		const int CARD_LEFT = 17;
		const int CARD_TOP = 48;
		const int CARD_LEFT_PADDING = 52;
		const int CARD_TOP_PADDING = 71;
		const int CARD_PER_ROW = 8;
		const int MAX_SELECTED_CARDS = 9; // TBD

		const string PICKER_BACKGROUND = "Resources/Plants/Cards/BMP/Picker.bmp";

		const map<vector<int>, vector<string>> CARDS_DATA_MAP = {
			// <data, bitmaps>
			// for data:
			//		{type, price, cooldown} Price is by order off and can be found in the consts above
			// for bitmaps
			//		// {...Filepaths name} }
			// {_alive, _unable, cooldown0, cooldown 1, cooldown 2, cooldown 3};

			{	{SEED_CARD_TYPE::PEA_SHOOTER, PeaShooter::price, 10},

				{"Resources/Plants/Cards/BMP/card_peashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_peashooter_unable.bmp", // "94", "148",
					"Resources/Plants/Cards/BMP/card_peashooter_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_peashooter_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_peashooter_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_peashooter_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::SUN_FLOWER, SunFlower::price, 10},

				{"Resources/Plants/Cards/BMP/card_sunflower_alive.bmp", "Resources/Plants/Cards/BMP/card_sunflower_unable.bmp", // "147", "148"
					"Resources/Plants/Cards/BMP/card_sunflower_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_sunflower_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_sunflower_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_sunflower_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::CHERRY_BOMB, CherryBomb::price, 50},
				{"Resources/Plants/Cards/BMP/card_cherrybomb_alive.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_unable.bmp",
					"Resources/Plants/Cards/BMP/card_cherrybomb_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_cherrybomb_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::WALL_NUT, WallNut::price, 30},
				{"Resources/Plants/Cards/BMP/card_wallnut_alive.bmp", "Resources/Plants/Cards/BMP/card_wallnut_unable.bmp",
					"Resources/Plants/Cards/BMP/card_wallnut_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_wallnut_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_wallnut_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_wallnut_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::POTATO_MINE, PotatoMine::price, 30},
				{"Resources/Plants/Cards/BMP/card_potatomine_alive.bmp", "Resources/Plants/Cards/BMP/card_potatomine_unable.bmp",
					"Resources/Plants/Cards/BMP/card_potatomine_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_potatomine_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_potatomine_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_potatomine_cooldown3.bmp"}
			},


			{	{SEED_CARD_TYPE::SNOW_PEA, SnowPea::price, 10},
				{"Resources/Plants/Cards/BMP/card_snowpea_alive.bmp", "Resources/Plants/Cards/BMP/card_snowpea_unable.bmp",
					"Resources/Plants/Cards/BMP/card_snowpea_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_snowpea_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_snowpea_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_snowpea_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::REPEATER_PEA, RepeaterPea::price, 10},
				{"Resources/Plants/Cards/BMP/card_repeaterpea_alive.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_unable.bmp",
					"Resources/Plants/Cards/BMP/card_repeaterpea_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_repeaterpea_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::SQUASH, Squash::price, 30},
				{"Resources/Plants/Cards/BMP/card_squash_alive.bmp", "Resources/Plants/Cards/BMP/card_squash_unable.bmp",
					"Resources/Plants/Cards/BMP/card_squash_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_squash_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_squash_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_squash_cooldown3.bmp"} // squasher
			},

			{	{SEED_CARD_TYPE::PUFF_SHROOM, PuffShroom::price, 10},
				{"Resources/Plants/Cards/BMP/card_puffshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_unable.bmp",
					"Resources/Plants/Cards/BMP/card_puffshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_puffshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_cooldown3.bmp"}
			},

			{	{SEED_CARD_TYPE::SCAREDY_SHROOM, ScaredyShroom::price, 10},
				{"Resources/Plants/Cards/BMP/card_scaredyshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_scaredyshroom_unable.bmp",
					"Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown3.bmp"} // scaredy-shroom
			},

			{	{SEED_CARD_TYPE::ICE_SHROOM, IceShroom::price, 50},
				{"Resources/Plants/Cards/BMP/card_iceshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_iceshroom_unable.bmp",
					"Resources/Plants/Cards/BMP/card_iceshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_iceshroom_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_iceshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_iceshroom_cooldown3.bmp"} // ice-shroom
			},

			{	{SEED_CARD_TYPE::THREE_PEATER, Threepeater::price, 10},
				{"Resources/Plants/Cards/BMP/card_threepeashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_threepeashooter_unable.bmp",
					"Resources/Plants/Cards/BMP/card_threepeashooter_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_threepeashooter_cooldown1.bmp",
					"Resources/Plants/Cards/BMP/card_threepeashooter_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_threepeashooter_cooldown3.bmp"} // Three-peater
			},

			{	{SEED_CARD_TYPE::JALAPENO, Jalapeno::price, 50},
			 	{"Resources/Plants/Cards/BMP/card_jalapeno_alive.bmp", "Resources/Plants/Cards/BMP/card_jalapeno_unable.bmp",
			 		"Resources/Plants/Cards/BMP/card_jalapeno_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_jalapeno_cooldown1.bmp",
			 		"Resources/Plants/Cards/BMP/card_jalapeno_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_jalapeno_cooldown3.bmp"} // Jalapeno
			},

		};

		CMovingBitmap background;
		vector<SeedCard> cards;
	};
}
