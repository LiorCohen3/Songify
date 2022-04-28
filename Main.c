#include"Songify.h"
#include"Song.h"
#include"Artist.h"
#include"Album.h"
int main(){
    songify *app;
    app = (songify*)calloc(1,sizeof(songify*));
    artist *lior = create_artist("Lior",1999,0);
    artist *tomer = create_artist("Tomer",1996,0);
    add_artist(app,lior);
    add_artist(app,tomer);
    album *nirv = create_album("Nevermind");
    album *tuna = create_album("Wild West");
    song *one = create_song("Smells Like Teen Spirit", 300);
    song *two = create_song("Come As You Are", 218);
    song *three = create_song("Polly", 180);
    song *four = create_song("Lithium", 256);
    // song *five = 
    // song *six = 
    // song *seven = 
    // song *eight = 
    add_album(app,lior,nirv);
    add_album(app,tomer,tuna);
    printf("%d\n",song_count(app,lior,nirv));
    add_song(app,lior,nirv,one);
    add_song(app,lior,nirv,two);
    add_song(app,lior,nirv,three);
    add_song(app,lior,nirv,four);
    printf("%d\n",song_count(app,lior,nirv));
    printf("The album duration is %d Seconds\n",album_duration(app,lior,nirv));
    print_albums(app,lior);
    printf("times played:%d\n",one->timePlayed);
    play_song(app,lior,nirv,one);
    printf("times played:%d\n",one->timePlayed);
    like_song(app,lior,nirv,one);
    play_song(app,lior,nirv,one);
    printf("times played:%d\n",one->timePlayed);
    // printf("%d\n",song_count(app,lior,nirv));
}