#include "Structs.h"
#include "Album.h"
album *create_album (char *name)
{
    album *temp = (album*)calloc(1,sizeof(album));
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
    temp->next = NULL;
    temp->songs = NULL;
    return temp;
}


songify *add_song(songify *head, artist *destArtist, album *destAlbum, song *newSong)
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL || newSong == NULL)
    {
        printf("Null Argument\n");
        return NULL;
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
    // int ID = song_count(head,tempArtist,tempAlbum);
    // tempSong->ID = ID;
    tempAlbum->songs = newSong;
    tempAlbum->songs->next = tempSong;
    return head;
}


int song_count(songify *head, artist *destArtist, album *destAlbum)
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL)
    {
        printf("Null Argument\n");
        return -1;
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
    song *tempSong = destAlbum->songs;
    int count = 0;
    while (tempSong != NULL)
    {
        count++;
        tempSong= tempSong->next;
    }
    return count;
}


int album_duration(songify *head, artist *destArtist, album *destAlbum)
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL)
    {
        printf("Null Argument\n");
        return -1;
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
    song *tempSong = destAlbum->songs;
    int count = 0;
    while (tempSong != NULL)
    {
        count += tempSong->length;
        tempSong= tempSong->next;
    }
    return count;
}