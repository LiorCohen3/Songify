#include "Structs.h"
#include "Album.h"
album *create_album (char *name) // Creates and allocates memory for new album
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


int check_album(songify *head, artist *destArtist, album *destAlbum) // checks if the given album is under the given artist in songify
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL)
    {
        printf("Null Argument\n");
        return -1;
    }
    artist *tempArtist = head->artists;
    while (tempArtist != NULL)
    {
        if (tempArtist == destArtist)
        {
            album *tempAlbum = destArtist->albums;
            while (tempAlbum != NULL)
            {
                if (tempAlbum == destAlbum)
                {
                    return 1;
                }
                tempAlbum = tempAlbum->next;
            }
            printf("The album \"%s\" was not found under %s!\n",destAlbum->name,destArtist->name);
            return -1;
        }
        tempArtist = tempArtist->next;
    }
    printf("%s was not found in Songify database!\n",destArtist->name);
    return -1;
}


songify *add_song(songify *head, artist *destArtist, album *destAlbum, song *newSong) // adds song to given album 
{
    int check = check_album(head,destArtist,destAlbum);
    if (check == 1)
    {
        song *tempSong = destAlbum->songs;
        newSong->ID = song_count(head,destArtist,destAlbum);
        destAlbum->songs = newSong;
        destAlbum->songs->next = tempSong;
        return head;
    }
    return NULL;
}


int song_count(songify *head, artist *destArtist, album *destAlbum) // returns song count in given album
{
    int check = check_album(head,destArtist,destAlbum);
    if (check == 1)
    {
        song *tempSong = destAlbum->songs;
        int count = 0;
        while (tempSong != NULL)
        {
            count++;
            tempSong = tempSong->next;
        } 
        return count;
    }
    return -1;
}


int album_duration(songify *head, artist *destArtist, album *destAlbum) // returns a sum of songs duration in album in seconds
{
    int check = check_album(head,destArtist,destAlbum);
    if (check == 1)
    {
        song *tempSong = destAlbum->songs;
        int count = 0;
        while (tempSong != NULL)
        {
            count += tempSong->length;
            tempSong= tempSong->next;
        }
        return count;
    }
    return -1;
}