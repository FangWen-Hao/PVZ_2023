#pragma once
#include "AudioConsts.h"
#include <vector>

using namespace std;
namespace game_framework {
	/*static*/ class SoundBoard
	{
	public:
		static void initSoundboard();
		static bool playSfx(soundID, bool = false); // bool is for repeatition, by default off
		static bool playMusic(soundID, bool = false); // bool is for repeatition, by default off
		static bool stopSound(soundID);

		static bool toggleSFX();
		static bool toggleMusic();

		static bool isSfxOn() { return sfxOn; }
		static bool isMusicOn() { return musicOn; }

		static void setSfxOn(bool val) { sfxOn = val; }
		static void setMusicOn(bool val) { musicOn = val; }

	private:
		static bool sfxOn;
		static bool musicOn;

		static vector<soundID> loadedSFX;
		static vector<soundID> loadedMusic;
		
		// private constructor because we want this to be a fully static class
		// idk if we should either private them or just straight out ` = delete;`
		SoundBoard() {}; 
		SoundBoard(const SoundBoard&) {};
		SoundBoard& operator=(const SoundBoard&) {};
	};
}