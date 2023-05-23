#include "stdafx.h"
#include "Soundboard.h"
#include "EntitiesUtil.h"
#include "../../Library/audio.h"

using namespace game_framework;

bool SoundBoard::sfxOn;
bool SoundBoard::musicOn;

vector<soundID> SoundBoard::loadedSFX;
vector<soundID> SoundBoard::loadedMusic;


void SoundBoard::initSoundboard()
{
	sfxOn = true;
	musicOn = true;
}

bool SoundBoard::playSfx(soundID id, bool repeat)
{
	// takes a soundID as value and returns true if the sound was played, otherwise return false
	if (SFX_FILES.count(id) == 0)
		return false; // the sound isnt an SFX, return false

	if (!findObjInVector(loadedSFX, id))
	{
		// the file hasnt been loaded yet, therefore load it.
		char *cstr = new char[SFX_FILES.at(id).length() + 1];
		strcpy(cstr, SFX_FILES.at(id).c_str());

		CAudio::Instance()->Load((unsigned)id, cstr);

		delete[] cstr;
		loadedSFX.push_back(id);
	}

	if (sfxOn)
		CAudio::Instance()->Play((unsigned)id, repeat);

	return true;
}

bool SoundBoard::playMusic(soundID id, bool repeat)
{
	// takes a soundID as value and returns true if the sound was played, otherwise return false
	if (MUSIC_FILES.count(id) == 0)
		return false; // the sound isnt a music, return false

	if (!findObjInVector(loadedMusic, id))
	{
		// the file hasnt been loaded yet, therefore load it.
		char *cstr = new char[MUSIC_FILES.at(id).length() + 1];
		strcpy(cstr, MUSIC_FILES.at(id).c_str());

		CAudio::Instance()->Load((unsigned)id, cstr);

		delete[] cstr;
		loadedMusic.push_back(id);
	}

	if (musicOn)
		CAudio::Instance()->Play((unsigned)id, repeat);
	
	return true;
}


bool SoundBoard::stopSound(soundID id)
{
	if (findObjInVector(loadedSFX, id) || findObjInVector(loadedMusic, id))
	{
		// the id has been loaded, therefore stop the sound
		CAudio::Instance()->Stop((unsigned)id);
		return true;
	}
	
	// the id wasn't loaded, meaning it either doesn't exist or smply wasn't loaded, return false.
	return false;
}

bool SoundBoard::toggleSFX()
{
	sfxOn = !sfxOn; // toggle the value

	if (!sfxOn && !loadedSFX.empty())
	{
		// if it is false, then stop all sfx sounds
		for (soundID id : loadedSFX)
		{
			CAudio::Instance()->Stop((unsigned)id);
		}
	}

	return sfxOn;
}

bool SoundBoard::toggleMusic()
{
	musicOn = !musicOn;


	if (!musicOn && !loadedMusic.empty())
	{
		// if it is false, then stop all sfx sounds
		for (soundID id : loadedMusic)
		{
			CAudio::Instance()->Stop((unsigned)id);
		}
	}

	return musicOn;
}
