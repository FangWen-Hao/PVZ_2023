#pragma once
#include "SeedCard.h"
#include "CardPicker.h"
#include "Button.h"

using namespace std;
namespace game_framework
{

	class GameBar
	{
	public:
		GameBar();
		~GameBar();

		void GameBar::init(int initialSuns);
		void show();
		void move();
		void onHover(CPoint coords);
		SEED_CARD_TYPE onClick(CPoint coords);
		void setSeedCardCooldown(SEED_CARD_TYPE cardType);
		
		void addSuns(int suns);
		void setSuns(int suns);
		int getSuns(void);
		bool hasGameStarted(void);
		high_resolution_clock::time_point getGameStartedTime();

	private:
		void drawSun();
		void setSelectedCards();
		bool checkIfCardIsAlreadySelected(SeedCard *card);
		void addCard(SeedCard *card);
		void removeCard(SeedCard *card);
		void updateCardsFrames();

		const int _maxNumberOfCards = 8;

		const string BACKGROUND_BMP_FILEPATH = "Resources/Misc/Plant Slot/BMP/ChooserBackground.bmp";
		const vector<string> START_GAME_BMP_FILEPATH = {"Resources/Misc/Plant Slot/BMP/startDark.bmp", "Resources/Misc/Plant Slot/BMP/startLight.bmp", "Resources/Misc/Plant Slot/BMP/startUnableToStart.bmp" };
		const vector<string> SHOVEL_BUTTON_FILEPATH = { "Resources/Misc/Shovel/BMP/Shovel.bmp", "Resources/Misc/Shovel/BMP/shovelEmpty.bmp" };

		int _suns;
		int _selectedCards = 0;
		bool gameStarted = false;
		high_resolution_clock::time_point gameStartedTime;

		CMovingBitmap background;
		vector<SeedCard> cards;
		CardPicker picker;
		Button startGameButton;
		Button shovelButton;

	};
}