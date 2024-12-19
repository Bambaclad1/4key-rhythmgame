#include "Song.h"

Song::Song()
{
}

Song::~Song()
{
}

void Song::AddSong(std::map<float, ArrowDirection> songFrames)
{
    for (auto const& [key, val] : songFrames)
    {
        Arrow* newArrow = new Arrow(val);
        track.insert({ key, newArrow });
    }
}

std::map<float, Arrow*> Song::GetTrack()
{
    return track;
}
