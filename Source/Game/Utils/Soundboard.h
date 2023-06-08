#pragma once
#include "AudioConsts.h"
#include <map>
#include <vector>
#include "SoundInfo.h"

using namespace std;
namespace game_framework {

	const string SOUND_DIR = "Resources/Music/";

	const map<soundID, SoundInfo> SFX_FILES = {
		// all files for SFX sounds are here, 
		// {id, SoundInfo(id, "${filePath}", length [in SECONDS])};
		{soundID::SFX_CHERRYBOMB, SoundInfo(soundID::SFX_CHERRYBOMB,		SOUND_DIR + "SFX_cherrybomb.wav",			3)},
		{soundID::SFX_CHOMP_1, SoundInfo(soundID::SFX_CHOMP_1,				SOUND_DIR + "SFX_chomp.wav",				2)},
		{soundID::SFX_CHOMP_2, SoundInfo(soundID::SFX_CHOMP_2,				SOUND_DIR + "SFX_chomp2.wav",				2)},
		{soundID::SFX_JALAPENO, SoundInfo(soundID::SFX_JALAPENO,			SOUND_DIR + "SFX_jalapeno.wav",				2)},
		{soundID::SFX_LAWNMOWER, SoundInfo(soundID::SFX_LAWNMOWER,			SOUND_DIR + "SFX_lawnmower.wav",			3)},
		{soundID::SFX_NEWSPAPER_DIE, SoundInfo(soundID::SFX_NEWSPAPER_DIE, 	SOUND_DIR + "SFX_newspaper_rip.wav",		1)},
		{soundID::SFX_PLANTED_PLANT, SoundInfo(soundID::SFX_PLANTED_PLANT, 	SOUND_DIR + "SFX_plant.wav",				1)},
		{soundID::SFX_POTATO_MINE, SoundInfo(soundID::SFX_POTATO_MINE,		SOUND_DIR + "SFX-potato-mine.wav",			2)},
		{soundID::SFX_SHOVEL, SoundInfo(soundID::SFX_SHOVEL,				SOUND_DIR + "SFX-shovel.wav",				1)},
		{soundID::SFX_SPLAT_1, SoundInfo(soundID::SFX_SPLAT_1,				SOUND_DIR + "SFX-splat.wav",				1)},
		{soundID::SFX_SPLAT_2, SoundInfo(soundID::SFX_SPLAT_2,				SOUND_DIR + "SFX-splat2.wav", 				1)},
		{soundID::SFX_SPLAT_3, SoundInfo(soundID::SFX_SPLAT_3,				SOUND_DIR + "SFX-splat3.wav", 				1)},
		{soundID::SFX_SUN_PICKED, SoundInfo(soundID::SFX_SUN_PICKED,		SOUND_DIR + "SFX-Sun-Picked.wav",			2)},
		{soundID::VOICE_NEWSPAPER_1, SoundInfo(soundID::VOICE_NEWSPAPER_1, 	SOUND_DIR + "Voices_newspaper_rarrgh2.wav",	2)},
		{soundID::VOICE_NEWSPAPER_2, SoundInfo(soundID::VOICE_NEWSPAPER_2, 	SOUND_DIR + "Voices-newspaper-rarrgh.wav",	2)},



	};

	const map<soundID, SoundInfo> MUSIC_FILES = {
		// all files for music sounds are here, 
		// {id, SoundInfo(id, "${filePath}", length)};
		{soundID::TITLE_SCREEN, SoundInfo(soundID::TITLE_SCREEN,			SOUND_DIR + "01_Title_Screen.wav",		22)},
		{soundID::MAIN_MENU, SoundInfo(soundID::MAIN_MENU,					SOUND_DIR + "02_Main_Menu.wav",			88)},
		{soundID::CHOOSE_YOUR_SEEDS, SoundInfo(soundID::CHOOSE_YOUR_SEEDS,	SOUND_DIR + "03_Choose_Your_Seeds.wav",	19)},
		{soundID::DAY_MAP, SoundInfo(soundID::DAY_MAP,						SOUND_DIR + "04_Day_Map.wav",			149)},
		{soundID::NIGHT_MAP, SoundInfo(soundID::NIGHT_MAP,					SOUND_DIR + "06_Night_Map.wav",			146)},
		{soundID::ON_NOTE_UI, SoundInfo(soundID::ON_NOTE_UI,				SOUND_DIR + "07_On_Note_UI.wav",		61)},
		{soundID::LOSE_MUSIC, SoundInfo(soundID::LOSE_MUSIC,				SOUND_DIR + "08_losemusic.wav",			5)},
	};


	/*static*/ class SoundBoard
	{
	public:
		static void initSoundboard();
		static bool playSfx(soundID, bool = false); // bool is for repeatition, by default off
		static bool playMusic(soundID, bool = false); // bool is for repeatition, by default off
		static bool isSoundBeingPlayed(soundID id);
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

		static vector<SoundInfo> loadedSFX;
		static vector<SoundInfo> loadedMusic;
		static soundID currentMusic;
		
		// private constructor because we want this to be a fully static class
		// idk if we should either private them or just straight out ` = delete;`
		SoundBoard() {}; 
		SoundBoard(const SoundBoard&) {};
		SoundBoard& operator=(const SoundBoard&) {};
	};
}