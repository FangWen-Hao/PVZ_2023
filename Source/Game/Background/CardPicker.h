#pragma once

#include "SeedCard.h"

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
		const vector<vector<string>> CARDS_BITMAPS_FILEPATH {
			// {...Filepaths name} }
			// {_alive, _unable, cooldown0, cooldown 1, cooldown 2, cooldown 3};
			{"Resources/Plants/Cards/BMP/card_peashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_peashooter_unable.bmp",
			"Resources/Plants/Cards/BMP/card_peashooter_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_peashooter_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_peashooter_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_peashooter_cooldown3.bmp"}, // "94", "148",

			{"Resources/Plants/Cards/BMP/card_sunflower_alive.bmp", "Resources/Plants/Cards/BMP/card_sunflower_unable.bmp",
			"Resources/Plants/Cards/BMP/card_sunflower_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_sunflower_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_sunflower_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_sunflower_cooldown3.bmp"}, // "147", "148"

			{"Resources/Plants/Cards/BMP/card_cherrybomb_alive.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_unable.bmp",
			"Resources/Plants/Cards/BMP/card_cherrybomb_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_cherrybomb_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_wallnut_alive.bmp", "Resources/Plants/Cards/BMP/card_wallnut_unable.bmp",
			"Resources/Plants/Cards/BMP/card_wallnut_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_wallnut_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_wallnut_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_wallnut_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_potatomine_alive.bmp", "Resources/Plants/Cards/BMP/card_potatomine_unable.bmp",
			"Resources/Plants/Cards/BMP/card_potatomine_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_potatomine_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_potatomine_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_potatomine_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_snowpea_alive.bmp", "Resources/Plants/Cards/BMP/card_snowpea_unable.bmp",
			"Resources/Plants/Cards/BMP/card_snowpea_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_snowpea_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_snowpea_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_snowpea_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_chomper_alive.bmp", "Resources/Plants/Cards/BMP/card_chomper_unable.bmp",
			"Resources/Plants/Cards/BMP/card_chomper_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_chomper_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_chomper_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_chomper_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_repeaterpea_alive.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_unable.bmp",
			"Resources/Plants/Cards/BMP/card_repeaterpea_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_repeaterpea_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_puffshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_unable.bmp",
			"Resources/Plants/Cards/BMP/card_puffshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_puffshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_cooldown3.bmp"},

			{"Resources/Plants/Cards/BMP/card_sunshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_sunshroom_unable.bmp",
			"Resources/Plants/Cards/BMP/card_sunshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_sunshroom_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_sunshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_sunshroom_cooldown3.bmp"}, // sun_shroom

			{"Resources/Plants/Cards/BMP/card_hypnoshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_hypnoshroom_unable.bmp",
			"Resources/Plants/Cards/BMP/card_hypnoshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_hypnoshroom_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_hypnoshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_hypnoshroom_cooldown3.bmp"}, // hypno-shroom

			{"Resources/Plants/Cards/BMP/card_scaredyshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_scaredyshroom_unable.bmp",
			"Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_scaredyshroom_cooldown3.bmp"}, // scaredy-shroom

			{"Resources/Plants/Cards/BMP/card_iceshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_iceshroom_unable.bmp",
			"Resources/Plants/Cards/BMP/card_iceshroom_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_iceshroom_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_iceshroom_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_iceshroom_cooldown3.bmp"}, // ice-shroom

			{"Resources/Plants/Cards/BMP/card_squash_alive.bmp", "Resources/Plants/Cards/BMP/card_squash_unable.bmp",
			"Resources/Plants/Cards/BMP/card_squash_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_squash_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_squash_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_squash_cooldown3.bmp"}, // squasher

			{"Resources/Plants/Cards/BMP/card_threepeashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_threepeashooter_unable.bmp",
			"Resources/Plants/Cards/BMP/card_threepeashooter_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_threepeashooter_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_threepeashooter_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_threepeashooter_cooldown3.bmp"}, // Three-peater

			{"Resources/Plants/Cards/BMP/card_jalapeno_alive.bmp", "Resources/Plants/Cards/BMP/card_jalapeno_unable.bmp",
			"Resources/Plants/Cards/BMP/card_jalapeno_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_jalapeno_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_jalapeno_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_jalapeno_cooldown3.bmp"}, // Jalapeno

			{"Resources/Plants/Cards/BMP/card_spikeweed_alive.bmp", "Resources/Plants/Cards/BMP/card_spikeweed_unable.bmp",
			"Resources/Plants/Cards/BMP/card_spikeweed_cooldown0.bmp", "Resources/Plants/Cards/BMP/card_spikeweed_cooldown1.bmp",
			"Resources/Plants/Cards/BMP/card_spikeweed_cooldown2.bmp", "Resources/Plants/Cards/BMP/card_spikeweed_cooldown3.bmp"}, // spike_weed

		};
		const vector<vector<int>> CARDS_DATA {
		//  {price, cooldown, type} Price is by order off and can be found in the consts above
			{100, 10, SEED_CARD_TYPE::PEA_SHOOTER},
			{50, 10, SEED_CARD_TYPE::SUN_FLOWER},
			{150, 50, SEED_CARD_TYPE::CHERRY_BOMB},
			{50, 30, SEED_CARD_TYPE::WALL_NUT},
			{25, 30, SEED_CARD_TYPE::POTATO_MINE},
			{175, 10, SEED_CARD_TYPE::SNOW_PEA},
			{150, 10, SEED_CARD_TYPE::CHOMPER},
			{200, 10, SEED_CARD_TYPE::REPEATER_PEA},
			{0, 10, SEED_CARD_TYPE::PUFF_SHROOM},
			{25, 10, SEED_CARD_TYPE::HYPNO_SHROOM},
			{75, 30, SEED_CARD_TYPE::HYPNO_SHROOM},
			{25, 10, SEED_CARD_TYPE::SCAREDY_SHROOM},
			{75, 50, SEED_CARD_TYPE::ICE_SHROOM},
			{50, 30, SEED_CARD_TYPE::SQUASH},
			{325, 10, SEED_CARD_TYPE::THREE_PEATER},
			{125, 50, SEED_CARD_TYPE::JALAPENO},
			{100, 10, SEED_CARD_TYPE::SPIKE_WEED},
		};


		CMovingBitmap background;
		vector<SeedCard> cards;
	};
}