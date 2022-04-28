#include "Structs.h"
#include "Songify.h"
songify *add_artist(songify *head,artist *newArtist) // Adds artist to songify
{
    if (head == NULL || newArtist == NULL)
    {
        printf("Null Argument\n");
        return NULL;
    }
    artist *temp = head->artists;
    head->artists = newArtist;
    head->artists->next = temp;
    return head;
}