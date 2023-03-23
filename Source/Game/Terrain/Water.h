#pragma once

using namespace std;
namespace game_framework {
	class Water : public Tile
	{
	public:
		Water();
		~Water();

		void init(int posInLane, int lane);
		void show();

		Plant* getPlant();
		void setPlant(Plant *plant);

	private:
		const vector<string> WATER_BITMAP_FILEPATHS {
		"", "" //TODO bitmap 0 is the normal image, bitmap 1 is the highlighted version.
		};
		CMovingBitmap _bitmap;
		WaterPlant *_plant = nullptr;
	};

}