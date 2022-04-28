#include "Structs.h"
#include "Artist.h"
artist *create_artist (char *name, int firstYear, int lastYear)
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

songify *add_album (songify *head, artist *dest, album *newAlbum)
{
    if (head == NULL || dest == NULL || newAlbum == NULL)
    {
        printf("Null Argument\n");
        return NULL;
    }
    artist *temp = head->artists;
    while (temp != dest)
    {
        temp = temp->next;
    }
    album *tempAlbum = temp->albums;
    temp->albums = newAlbum;
    temp->albums->next = tempAlbum;
    return head;
}

void print_albums(songify *head, artist *toPrint)
{
    if (head == NULL || toPrint == NULL)
    {
        printf("Null Argument\n");
        return;
    }
    artist *temp = head->artists;
    while (temp != toPrint)
    {
        temp = temp->next;
    }
    album *tempAlbum = temp->albums;
    while (tempAlbum != NULL)
    {
        printf("%s\n",tempAlbum->name);
        tempAlbum = tempAlbum->next;
    }
    return;
}