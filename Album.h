#ifndef ALBUM_H
#define ALBUM_H
#include "Structs.h"

album *create_album (char *name);


songify *add_song(songify *head, artist *destArtist, album *destAlbum, song *newSong);


int song_count(songify *head, artist *destArtist, album *destAlbum);


int album_duration(songify *head, artist *destArtist, album *destAlbum);

#endif