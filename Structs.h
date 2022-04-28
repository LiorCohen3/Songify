#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum booli
{
    FALSE,
    TRUE
} booli;

typedef struct song
{
    int ID;
    char* name;
    int length; //The length of the song in seconds
    int timePlayed; //How many times the song have been played
    enum booli liked; //The user liked the song
    struct song* next;
} song;

typedef struct album
{
    char* name;
    song* songs; //A LinkedList of songs
    struct album* next;
} album;

typedef struct activeYears
{
    int firstYear;
    int lastYear; // 0 == still active
} activeYears;

typedef struct artist
{
    char* name; //A LinkedList of
    struct activeYears active;
    album* albums; //A LinkedList of albums
    struct artist* next;
} artist;

typedef struct songify
{
    artist* artists;
} songify;

#endif