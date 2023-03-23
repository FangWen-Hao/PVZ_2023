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
			{ {"Resources/Plants/Cards/BMP/card_peashooter_alive.bmp", "Resources/Plants/Cards/BMP/card_peashooter_die.bmp"}, {"100", "7"} }, // "94", "148", 
			{ {"Resources/Plants/Cards/BMP/card_sunflower_alive.bmp", "Resources/Plants/Cards/BMP/card_sunflower_die.bmp"}, {"50", "7"} }, // "147", "148"
			{ {"Resources/Plants/Cards/BMP/card_cherrybomb_alive.bmp", "Resources/Plants/Cards/BMP/card_cherrybomb_die.bmp"}, {"150", "50"} }, // "94", "148"
		};

		CMovingBitmap background;
		vector<SeedCard> cards;
		int selectedCards = 0;
	};
}