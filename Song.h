#ifndef SONG_H
#define SONG_H
#include "Structs.h"

song *create_song(char *name, int length);


void play_song(songify *head, artist *destArtist, album *destAlbum, song *destSong);


void like_song(songify *head, artist *destArtist, album *destAlbum, song *destSong);

#endif