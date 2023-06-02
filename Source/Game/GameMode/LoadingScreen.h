#pragma once
#include "GameMode.h"
#include "../Misc/Cooldown.h"

namespace game_framework {
	const vector<string> loadingBackgroundFilePath = { "Resources/Background/Loading/Loading0.bmp", "Resources/Background/Loading/Loading1.bmp" };

	const double LOADING_TIME = 1.0;

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

	private:
		int getIsDone();

		Cooldown loadingTime;
	};
}