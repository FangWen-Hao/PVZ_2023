#pragma once
#include "GameMode.h"

namespace game_framework {
	const string loadingBackgroundFilePath = "Resources/Background/Loading/Loading.bmp";

	class LoadingScreen : public GameMode
	{
	public:
		LoadingScreen();
		~LoadingScreen();

		void init();
		void show();
		void OnMove();
		void OnKeyUp(UINT);
		void OnHover(CPoint);
		int OnLClick(CPoint);
		int OnRClick(CPoint);

		bool getIsDone();

	private:
		bool isDone;
	};
}