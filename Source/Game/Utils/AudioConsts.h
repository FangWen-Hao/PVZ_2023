#pragma once

namespace game_framework {
	const enum class soundID : unsigned {
		// soundIDs are here, every file has 1 sound ID, and all IDs are unsigned (>= 0)
		EMPTY,
		TITLE_SCREEN,
		MAIN_MENU,
		CHOOSE_YOUR_SEEDS,
		DAY_MAP,
		NIGHT_MAP,
		ON_NOTE_UI,
		LOSE_MUSIC,

		SFX_CHERRYBOMB,
		SFX_CHOMP_1,
		SFX_CHOMP_2,
		SFX_JALAPENO,
		SFX_LAWNMOWER,
		SFX_NEWSPAPER_DIE,
		SFX_PLANTED_PLANT,
		SFX_POTATO_MINE,
		SFX_SHOVEL,
		SFX_SPLAT_1,
		SFX_SPLAT_2,
		SFX_SPLAT_3,
		SFX_SUN_PICKED,
		VOICE_NEWSPAPER_1,
		VOICE_NEWSPAPER_2,
	};
}