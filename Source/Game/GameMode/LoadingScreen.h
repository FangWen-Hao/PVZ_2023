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
		void OnHover(CPoint coords);
		int OnLClick(CPoint coords);
		int OnRClick(CPoint coords);

		bool getIsDone();

	private:
		bool isDone;
	};
}