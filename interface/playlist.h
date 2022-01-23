#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_PLAYLIST_NUM 50
#define MAX_SONG_NUM 100

struct playlist {
    char name[STRING_SIZE]; //actual name of playlist, ex. "train vibes"
    struct song ** list; //list of songs
    int num_songs; //number of songs in the playlist
};

//creates master playlist (queue will be list[0], master playlist of songs will be list[1])
struct playlist ** create_master_list();

//create playlist 
struct playlist * create_playlist(char *playlist_name);

//add playlist to master list
void register_playlist(struct playlist * list, struct playlist ** master);

//deletes playlist and removes from master playlist list
void delete_playlist(struct playlist * list, struct playlist ** master);

//add songs to playlist
void add_song(struct song * s, struct playlist * p);

//delete songs from playlist
void delete_song(struct song *s, struct playlist * p);

//display playlist data 
void disp_playlist_data(struct playlist * p);

//display name of all playlists
void disp_all_playlists(struct playlist ** master); 

//display queue data
void disp_queue(struct playlist ** master);

//sorting through list[1] to make new playlist based on diff data, ex: last played, file size, artist, song name

