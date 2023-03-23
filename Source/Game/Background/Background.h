#pragma once 
#include "../../Library/gameutil.h"

namespace game_framework {
	class Background : public CMovingBitmap {
	public:
		Background();
		void init(string filePath);
		void show();

	protected:

	private:
		
	};
}