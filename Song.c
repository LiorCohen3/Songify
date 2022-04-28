#include "Structs.h"
#include "Song.h"
song *create_song(char *name, int length)
{
    song *temp = (song*)calloc(1,sizeof(song));
    if (temp == NULL)
    {
        printf("Out of memory\n");
        return NULL;
    }
    temp->name = (char*)calloc(strlen(name)+1,sizeof(char));
    if (temp->name == NULL)
    {
        printf("Out of memory\n");
        free(temp);
        return NULL;
    }
    strcpy(temp->name,name);
    temp->length = length;
    temp->liked = FALSE;
    temp->next = NULL;
    temp->timePlayed = 0;
    return temp;
}

void play_song(songify *head, artist *destArtist, album *destAlbum, song *destSong)
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL || destSong == NULL)
    {
        printf("Null Argument\n");
        return;
    }
    artist *tempArtist = head->artists;
    while (tempArtist != destArtist)
    {
        tempArtist = tempArtist->next;
    }
    album *tempAlbum = tempArtist->albums;
    while (tempAlbum != destAlbum)
    {
        tempAlbum = tempAlbum->next;
    }
    song *tempSong = tempAlbum->songs;
    while (tempSong != destSong)
    {
        tempSong = tempSong->next;
    }
    tempSong->timePlayed++;
    if (tempSong->liked == TRUE)
    {
        printf("Now playing: %s. In favorites.\n",tempSong->name);
    }
    else
    {
        printf("Now playing: %s. Not in favorites\n",tempSong->name);
    }
    return;
}

void like_song(songify *head, artist *destArtist, album *destAlbum, song *destSong)
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL || destSong == NULL)
    {
        printf("Null Argument\n");
        return;
    }
    // artist *tempArtist = head->artists;
    // while (tempArtist != destArtist)
    // {
    //     tempArtist = tempArtist->next;
    // }
    // album *tempAlbum = tempArtist->albums;
    // while (tempAlbum != destAlbum)
    // {
    //     tempAlbum = tempAlbum->next;
    // }
    // song *tempSong = tempAlbum->songs;
    // while (tempSong != destSong)
    // {
    //     tempSong = tempSong->next;
    // }
    destSong->liked = TRUE;
    return;
}