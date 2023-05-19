#pragma once
#include "../../Library/audio.h"
#include <vector>

using namespace std;
namespace game_framework {
	class Sfx
	{
	public:
		Sfx() { audio = CAudio::Instance(); }
		~Sfx() { audio->Close(); } // the audio self destructs so no need to delete the ptr;

		void init(string filePath);
		void init(vector<string> filePaths);

		// Play the class
		bool Open();
		void Pause();
		void Resume();

		// play a specific sound of the class.
		void PlaySound(unsigned, bool = false);
		void StopSound(unsigned);

		int getAudioLoaded() { return audiosLoaded; }

	private:
		int audiosLoaded = 0; // doesnt need setter.
		CAudio *audio;
	};

}