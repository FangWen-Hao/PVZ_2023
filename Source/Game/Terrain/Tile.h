#pragma once

namespace game_framework {
	class Tile
	{
	public:
		Tile() {};
		~Tile() {};

		virtual void init(int x, int y) = 0;
		virtual void show() = 0;

		virtual Plant* getPlant() = 0;
		virtual void setPlant(Plant* plant) = 0;

	private:
	};
}