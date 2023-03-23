#pragma once 

using namespace std;
namespace game_framework {
	class Button : public CMovingBitmap {
	public:
		Button();
		void init(vector<string> filePath, string offsetX, string offsetY);
		void init(vector<string> filePath, int offsetX, int offsetY);
		void show();
		void clicked();

	protected:

	private:

	};
}