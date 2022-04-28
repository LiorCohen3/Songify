#include "Structs.h"
#include "Song.h"
song *create_song(char *name, int length) // Creates and allocates memory for a new song
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

int verify_song(songify *head, artist *destArtist, album *destAlbum, song *destSong) //Check if the given song is under the given album under the given artist in songify
{
    if (head == NULL || destArtist == NULL || destAlbum == NULL || destSong == NULL)
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
                    song *tempSong = destAlbum->songs;
                    while (tempSong != NULL)
                    {
                        if (tempSong == destSong)
                        {
                            return 1;
                        }
                        tempSong = tempSong->next;
                    }
                    printf("The song \"%s\" is not part of the album \"%s\"!\n",destSong->name,destAlbum->name);
                    return -1;
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


void play_song(songify *head, artist *destArtist, album *destAlbum, song *destSong) // plays song and prints if its liked
{
    int check = verify_song(head,destArtist,destAlbum,destSong);
    if (check == 1)
    {
        destSong->timePlayed++;
        if (destSong->liked == TRUE)
        {
            printf("Now playing: \"%s\". In favorites.\n",destSong->name);
        }
        else
        {
            printf("Now playing: \"%s\". Not in favorites\n",destSong->name);
        }
    }
    return;
}

void like_song(songify *head, artist *destArtist, album *destAlbum, song *destSong) // likes given song
{
    int check = verify_song(head,destArtist,destAlbum,destSong);
    if (check == 1)
    {
        destSong->liked = TRUE;
    }
    return;
}