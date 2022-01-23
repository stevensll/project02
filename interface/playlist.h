#define MAX_PLAYLIST_NUM 50
#define MAX_SONG_NUM 100
#include "song.h"

struct playlist {
    char name[STRING_SIZE]; //actual name of playlist, ex. "train vibes"
    struct song ** list; //list of songs
    int num_songs; //number of songs in the playlist
};

//creates master playlist (queue will be list[0], master playlist of songs will be list[1])
struct playlist ** create_master_list();

//create playlist 
struct playlist * create_playlist(char *playlist_name);

//returns number of songs in a playlist
int playlist_size(struct playlist * p);

//add playlist to master list
void register_playlist(struct playlist * list, struct playlist ** master);

//add song to master playlist
void register_song(struct song * s, struct playlist ** master);

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

//display all songs
void disp_all_songs(struct playlist ** master);

//adds song to queue
void queue_song(struct song * s, struct playlist ** master);

//remmoves song from queue
void dequeue_song(struct song * s, struct playlist ** master);

//clears queue and queues playlist
void queue_playlist(struct playlist * p, struct playlist ** master);

//clears queue
void clear_queue(struct playlist ** master);

//get song struct from song name
struct song * get_song(char * name, struct ** playlist master);

//get playlist struct from playlist name
struct playlist * get_playlist(char * name, struct ** playlist master);

//sorting through list[1] to make new playlist based on diff data, ex: last played, file size, artist, song name

