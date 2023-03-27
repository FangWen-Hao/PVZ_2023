#pragma once

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
		const vector<vector<vector<string>>> CARDS_BITMAPS_FILEPATH {
			// { {Filepaths name}, {offsetX, offsetY, price} } Price is by order off and can be found in the consts above
			{ {"Resources/Plants/Cards/BMP/card_peashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_peashooter_die.bmp"}, {"100", "10"} }, // "94", "148", 
			{ {"Resources/Plants/Cards/BMP/card_sunflower_alive.bmp", "Resources/Plants/Cards/BMP/card_sunflower_die.bmp"}, {"50", "10"} }, // "147", "148"
			{ {"Resources/Plants/Cards/BMP/card_cherrybomb_alive.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_die.bmp"}, {"150", "50"} },
			{ {"Resources/Plants/Cards/BMP/card_wallnut_alive.bmp", "Resources/Plants/Cards/BMP/card_wallnut_die.bmp"}, {"50", "30"} },
			{ {"Resources/Plants/Cards/BMP/card_potatomine_alive.bmp", "Resources/Plants/Cards/BMP/card_potatomine_die.bmp"}, {"25", "30"} },
			{ {"Resources/Plants/Cards/BMP/card_snowpea_alive.bmp", "Resources/Plants/Cards/BMP/card_snowpea_die.bmp"}, {"175", "10"} },
			{ {"Resources/Plants/Cards/BMP/card_chomper_alive.bmp", "Resources/Plants/Cards/BMP/card_chomper_die.bmp"}, {"150", "10"} },
			{ {"Resources/Plants/Cards/BMP/card_repeaterpea_alive.bmp", "Resources/Plants/Cards/BMP/card_repeaterpea_die.bmp"}, {"200", "10"} },
			{ {"Resources/Plants/Cards/BMP/card_snowpea_alive.bmp", "Resources/Plants/Cards/BMP/card_snowpea_die.bmp"}, {"175", "10"} },
			{ {"Resources/Plants/Cards/BMP/card_puffshroom_alive.bmp", "Resources/Plants/Cards/BMP/card_puffshroom_die.bmp"}, {"0", "10"} },
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"25", "10"} }, // sun_shroom
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"75", "30"} }, // hypno-shroom
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"25", "10"} }, // scaredy-shroom
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"75", "50"} }, // ice-shroom
			{ {"Resources/Plants/Cards/BMP/card_squash_alive.bmp", "Resources/Plants/Cards/BMP/card_squash_die.bmp"}, {"50", "30"} }, // squasher
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"325", "10"} }, // Three-peater
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"125", "50"} }, // Jalapeno
			{ {"Resources/Plants/Cards/BMP/card_place_holder_alive.bmp", "Resources/Plants/Cards/BMP/card_place_holder_die.bmp"}, {"100", "10"} }, // spike_weed
		};

		CMovingBitmap background;
		vector<SeedCard> cards;
	};
}