#pragma once
#include <map>

using namespace std;
namespace game_framework {
	const enum class soundID : unsigned {
		// soundIDs are here, every file has 1 sound ID, and all IDs are unsigned (>= 0)

	};

	const map<soundID, string> SFX_FILES = {
		// all files for SFX sounds are here, 
		// {id [see above], "${filePath}"};

	};

	const map<soundID, string> MUSIC_FILES = {
		// all files for music sounds are here, 
		// {id [see above], "${filePath}"};
	};

}