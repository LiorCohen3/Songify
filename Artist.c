#include "Structs.h"
#include "Artist.h"
artist *create_artist (char *name, int firstYear, int lastYear) // Creates and allocates memory for new artist
{
    artist *temp = (artist*)calloc(1,sizeof(artist));
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
    temp->albums = NULL;
    temp->active.firstYear = firstYear;
    temp->active.lastYear = lastYear;
    return temp;
}

songify *add_album (songify *head, artist *dest, album *newAlbum) // Adds album to artist in songify
{
    if (head == NULL || dest == NULL || newAlbum == NULL)
    {
        printf("Null Argument\n");
        return NULL;
    }
    artist *temp = head->artists;
    while (temp != NULL)
    {
        if (temp == dest)
        {
            album *tempAlbum = temp->albums;
            temp->albums = newAlbum;
            temp->albums->next = tempAlbum;
            return head;
        }
        temp = temp->next;
    }
    printf("%s was not found in Songify database!\n",dest->name);
    return NULL;
}

void print_albums(songify *head, artist *toPrint) // prints all albums under artist in songify
{
    if (head == NULL || toPrint == NULL)
    {
        printf("Null Argument\n");
        return;
    }
    artist *temp = head->artists;
    while (temp != NULL)
    {
        if (temp == toPrint)
        {
            album *tempAlbum = toPrint->albums;
            while (tempAlbum != NULL)
            {
                printf("%s\n",tempAlbum->name);
                tempAlbum = tempAlbum->next;
            }
            return;
        }
        temp = temp->next;
    }
    printf("%s was not found in Songify database!\n",toPrint->name);
    return;
}