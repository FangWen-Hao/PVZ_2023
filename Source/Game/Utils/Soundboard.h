#pragma once
#include "AudioEnums.h"
#include <map>
#include <vector>
#include <string>

using namespace std;
namespace game_framework {

	const map<soundID, string> SFX_FILES = {

	};

	const map<soundID, string> MUSIC_FILES = {

	};

	class SoundBoard
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
	};
}