#include "stdafx.h"
#include "Soundboard.h"
#include "EntitiesUtil.h"
#include "../../Library/audio.h"

using namespace game_framework;

bool SoundBoard::sfxOn;
bool SoundBoard::musicOn;

vector<SoundInfo> SoundBoard::loadedSFX;
vector<SoundInfo> SoundBoard::loadedMusic;


void SoundBoard::initSoundboard()
{
	sfxOn = true;
	musicOn = true;
}

bool SoundBoard::playSfx(soundID id, bool repeat)
{
	// takes a soundID as value and returns true if the sound was played, otherwise return false
	if (SFX_FILES.count(id) == 0)
		return false; // the sound isnt a music, return false

	SoundInfo sfx = SFX_FILES.at(id);

	if (!findObjInVector(loadedSFX, sfx))
	{
		// the file hasnt been loaded yet, therefore load it.
		char *cstr = new char[sfx.getFilePath().length() + 1];
		strcpy(cstr, sfx.getFilePath().c_str());

		CAudio::Instance()->Load(convertEnum(sfx.getId()), cstr);

		delete[] cstr;
		loadedSFX.push_back(sfx);
	}

	// track the sound as playing regardless if the sound is on or off.
	auto it = find(loadedSFX.begin(), loadedSFX.end(), sfx);
	it->play(repeat);

	if (sfxOn)
	{
		CAudio::Instance()->Play(convertEnum(it->getId()), repeat);
	}

	return true;
}

bool SoundBoard::playMusic(soundID id, bool repeat)
{
	// takes a soundID as value and returns true if the sound was played, otherwise return false
	if (MUSIC_FILES.count(id) == 0)
		return false; // the sound isnt a music, return false

	SoundInfo song = MUSIC_FILES.at(id);

	if (!findObjInVector(loadedMusic, song))
	{
		// the file hasnt been loaded yet, therefore load it.
		char *cstr = new char[song.getFilePath().length() + 1];
		strcpy(cstr, song.getFilePath().c_str());

		CAudio::Instance()->Load(convertEnum(song.getId()), cstr);

		delete[] cstr;
		loadedMusic.push_back(song);
	}

	// track the sound as playing regardless if the sound is on or off.
	auto it = find(loadedMusic.begin(), loadedMusic.end(), song);
	it->play(repeat);

	if (musicOn)
	{
		CAudio::Instance()->Play(convertEnum(it->getId()), repeat);
	}
	
	return true;
}


bool SoundBoard::stopSound(soundID id)
{
	if (SFX_FILES.count(id) == 0 && MUSIC_FILES.count(id) == 0)
		return false; 


	SoundInfo sound;

	if (MUSIC_FILES.count(id) == 0)
		sound = SFX_FILES.at(id);
	else
		sound = MUSIC_FILES.at(id);

	if (findObjInVector(loadedSFX, sound) || findObjInVector(loadedMusic, sound))
	{
		auto it = find(loadedMusic.begin(), loadedMusic.end(), sound);

		if (it == loadedMusic.end()) // it isnt in loaded music, search for loadedSFX
			it = find(loadedSFX.begin(), loadedSFX.end(), sound);

		// the id has been loaded, therefore stop the sound
		it->stop(); // untrack the sound
		CAudio::Instance()->Stop(convertEnum(it->getId()));
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
		for (SoundInfo sound : loadedSFX)
		{
			CAudio::Instance()->Stop(convertEnum(sound.getId()));
		}
	}
	else if (sfxOn && !loadedSFX.empty())
	{
		for (SoundInfo sound : loadedSFX)
		{
			// if the sound is still supposed to be playing, then play it
			if (sound.isBeingPlayed()) 
			{
				// if the sound is supposed to be playing, then play it.
				sound.play(sound.getRepeatStatus());
				CAudio::Instance()->Play(convertEnum(sound.getId()), sound.getRepeatStatus());
			}
			
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
		for (SoundInfo sound : loadedMusic)
		{
			CAudio::Instance()->Stop(convertEnum(sound.getId()));
		}
	}
	else if (musicOn && !loadedMusic.empty())
	{
		for (SoundInfo sound : loadedMusic)
		{
			// if the sound is still supposed to be playing, then play it
			if (sound.isBeingPlayed())
			{
				// if the sound is supposed to be playing, then play it.
				sound.play(sound.getRepeatStatus());
				CAudio::Instance()->Play(convertEnum(sound.getId()), sound.getRepeatStatus());
			}

		}
	}

	return musicOn;
}
