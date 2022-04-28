#include"Songify.h"
#include"Song.h"
#include"Artist.h"
#include"Album.h"
int main(){
    songify *app;
    app = (songify*)calloc(1,sizeof(songify));
    if(app == NULL)
    {
        printf("Out of memory\n");
        return -1;
    }
    artist *lior = create_artist("Lior",1999,0);
    artist *tomer = create_artist("Tomer",1996,0);
    add_artist(app,lior);
    add_artist(app,tomer);
    album *nirv = create_album("Nevermind");
    album *tuna = create_album("Wild East");
    song *one = create_song("Smells Like Teen Spirit", 300);
    song *two = create_song("Come As You Are", 218);
    song *three = create_song("Polly", 180);
    song *four = create_song("Lithium", 256);
    song *five = create_song("Hey Babe", 185);
    song *six = create_song("Shimi", 184);
    song *seven = create_song("Knows to spin", 192);
    song *eight = create_song("Sahara", 244);
    add_album(app,lior,nirv);
    add_album(app,tomer,tuna);
    printf("%d\n",song_count(app,lior,nirv));
    add_song(app,lior,nirv,one);
    add_song(app,lior,nirv,two);
    add_song(app,lior,nirv,three);
    add_song(app,lior,nirv,four);
    add_song(app,tomer,tuna,five);
    add_song(app,tomer,tuna,six);
    add_song(app,tomer,tuna,seven);
    add_song(app,tomer,tuna,eight);
    printf("%d\n",song_count(app,lior,nirv));
    printf("%d\n",song_count(app,tomer,tuna));
    printf("The album duration is %d Seconds\n",album_duration(app,lior,nirv));
    print_albums(app,lior);
    print_albums(app,tomer);
    printf("times played:%d\n",one->timePlayed);
    play_song(app,lior,nirv,one);
    printf("times played:%d\n",one->timePlayed);
    like_song(app,lior,nirv,one);
    play_song(app,lior,nirv,one);
    printf("times played:%d\n",one->timePlayed);
}