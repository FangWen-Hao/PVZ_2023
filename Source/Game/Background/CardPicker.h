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
			{"Resources/Plants/Cards/BMP/card_peashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_peashooter_die.bmp"}, // "94", "148", 
			{"Resources/Plants/Cards/BMP/card_sunflower_alive.bmp", "Resources/Plants/Cards/BMP/card_sunflower_die.bmp"}, // "147", "148"
			{"Resources/Plants/Cards/BMP/card_cherrybomb_alive.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_wallnut_alive.bmp", "Resources/Plants/Cards/BMP/card_wallnut_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_potatomine_alive.bmp", "Resources/Plants/Cards/BMP/card_potatomine_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_snowpea_alive.bmp", "Resources/Plants/Cards/BMP/card_snowpea_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_chomper_alive.bmp", "Resources/Plants/Cards/BMP/card_chomper_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_repeaterpea_alive.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_snowpea_alive.bmp", "Resources/Plants/Cards/BMP/card_snowpea_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_puffshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_die.bmp"},
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // sun_shroom
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // hypno-shroom
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // scaredy-shroom
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // ice-shroom
			{"Resources/Plants/Cards/BMP/card_squash_alive.bmp", "Resources/Plants/Cards/BMP/card_squash_die.bmp"}, // squasher
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // Three-peater
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // Jalapeno
			{"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, // spike_weed
		};
		const vector<vector<int>> CARDS_DATA {
		//  {price, cooldown, type} Price is by order off and can be found in the consts above
			{100, 10, SEED_CARD::PEA_SHOOTER},
			{50, 10, SEED_CARD::SUN_FLOWER},
			{150, 50, SEED_CARD::CHERRY_BOMB},
			{50, 30, SEED_CARD::WALL_NUT},
			{25, 30, SEED_CARD::POTATO_MINE},
			{175, 10, SEED_CARD::SNOW_PEA},
			{150, 10, SEED_CARD::CHOMPER},
			{200, 10, SEED_CARD::REPEATER_PEA},
			{175, 10, SEED_CARD::SNOW_PEA},
			{0, 10, SEED_CARD::PUFF_SHROOM},
			{25, 10, SEED_CARD::HYPNO_SHROOM},
			{75, 30, SEED_CARD::HYPNO_SHROOM},
			{25, 10, SEED_CARD::SCAREDY_SHROOM},
			{75, 50, SEED_CARD::ICE_SHROOM},
			{50, 30, SEED_CARD::SQUASH},
			{325, 10, SEED_CARD::THREE_PEATER},
			{125, 50, SEED_CARD::JALAPENO},
			{100, 10, SEED_CARD::SPIKE_WEED},
		};


		CMovingBitmap background;
		vector<SeedCard> cards;
	};
}