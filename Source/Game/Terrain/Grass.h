#pragma once

using namespace std;
namespace game_framework {
	class Grass : public Tile
	{
	public:
		Grass();
		~Grass();

		void init(int posInLane, int lane);
		void show();

		Plant* getPlant();
		void setPlant(Plant *plant);

	private:
		const vector<string> GRASS_BITMAP_FILEPATH {
		"", "" //TODO bitmap 0 is the normal image, bitmap 1 is the highlighted version.
		};
		CMovingBitmap _bitmap;
		GrassPlant *_plant = nullptr;
	};

}