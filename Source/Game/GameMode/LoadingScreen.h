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
		void OnHover(CPoint coords);
		int OnClick(CPoint coords);

		bool getIsDone();

	private:
		bool isDone;
	};
}