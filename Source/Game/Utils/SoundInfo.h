#pragma once
#include <string>
#include "AudioConsts.h"
#include "../Misc/Cooldown.h"

using namespace std;
namespace game_framework {
	class SoundInfo
	{
	public:
		SoundInfo() {};
		SoundInfo(soundID, string, double);
		SoundInfo(const SoundInfo &);

		bool operator==(SoundInfo other) noexcept { return (this->_id == other._id); }

		void play(bool = false);
		void stop() { _isActive = false; }

		void setIsOnRepeat(bool repeat) { _isOnRepeat = repeat; }

		soundID getId() const { return _id; }
		string getFilePath() const { return _filePath; }
		double getLength() const { return _length.getCooldown(); }
		bool isBeingPlayed() { return (_isActive && (_length.isOnCooldown() || _isOnRepeat)); }
		bool getRepeatStatus() { return _isOnRepeat; }
		bool getIsActive() { return _isActive; }
		

	private:
		soundID _id;
		string _filePath;
		Cooldown _length;
		bool _isOnRepeat = false;
		bool _isActive = false;
	};

}