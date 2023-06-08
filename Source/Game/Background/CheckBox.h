#pragma once
#include "../../Library/gameutil.h"
#include <string>
#include <functional>

using namespace std;
namespace game_framework {

	class CheckBox : CMovingBitmap
	{ 
	public:
		CheckBox() {};
		~CheckBox() {}; // note that it is not responsibel for the boolean value that was given to the checkbox for it to change: this responsability falls on the master class.

		void init(string unchecked, string checked, bool boolVariable, function<bool(void)> toggleFunc, int coordsX, int coordsY);
		void show();
		bool onClick(CPoint coords);
		bool isChked();

	private:
		bool boolVariableCopy;
		function<bool(void)> toggle;
	};
}