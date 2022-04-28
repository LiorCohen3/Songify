#ifndef ARTIST_H
#define ARTIST_H
#include "Structs.h"

artist *create_artist (char *name, int firstYear, int lastYear);


songify *add_album (songify *head, artist *dest, album *newAlbum);


void print_albums(songify *head, artist *toPrint);


#endif