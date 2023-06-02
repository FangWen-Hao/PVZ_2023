#pragma once 
#include "../../Library/gameutil.h"
#include <vector>

namespace game_framework {
	class Background : public CMovingBitmap {
	public:
		Background();
		void init(string filePath);
		void init(vector<string> filePath);
		void show();

	protected:

	private:
		
	};
}