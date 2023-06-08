#include "stdafx.h"
#include "SoundInfo.h"

using namespace game_framework;

SoundInfo::SoundInfo(soundID id, string filePath, double length)
{
	_id = id;
	_filePath = filePath;
	_length.initCooldown(length);
}

SoundInfo::SoundInfo(const SoundInfo &other)
{
	_id = other.getId();
	_filePath = other.getFilePath();
	_length.initCooldown(other.getLength());
}

void SoundInfo::play(bool repeat)
{
	_isOnRepeat = repeat;
	_isActive = true;
	_length.startCooldown();
}
