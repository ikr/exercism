#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>

namespace beer_song {
std::string verse(const int count);
std::string sing(const int from_count, const int to_count = 0);
} // namespace beer_song

#endif // BEER_SONG_H
