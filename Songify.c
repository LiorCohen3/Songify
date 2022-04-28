#include "Structs.h"
#include "Songify.h"
songify *add_artist(songify *head,artist *newArtist)
{
    if (head == NULL || newArtist == NULL)
    {
        printf("Null Argument\n");
        return NULL;
    }
    if (head->artists == NULL)
    {
        head->artists = newArtist;
    }
    else
    {
        artist *temp = head->artists;
        head->artists = newArtist;
        head->artists->next = temp;
    }
    return head;
}