#pragma once
#include <map>
#include "Arrow.h"
class Song
{
public:
	Song();
	~Song();
	void AddSong(std::map<float, ArrowDirection> songFrames);
	std::map<float, Arrow*> GetTrack();
private:
	std::map<float, Arrow*> track;
};

