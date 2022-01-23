#include "playlist.h"
#include "song.h"

//creates master playlist (queue will be list[0], master playlist of songs will be list[1])
struct playlist ** create_master_list() {
    struct playlist ** master_list = calloc(MAX_PLAYLIST_NUM + 2, sizeof(struct playlist *));
    master_list[0] = create_playlist("queue");
    master_list[1] = create_playlist("master");
}

//create playlist
struct playlist * create_playlist(char *playlist_name) {
    struct playlist * p = malloc(sizeof(struct playlist));
    strncpy(p->name, playlist_name, STRING_SIZE);
    p->list = calloc(MAX_SONG_NUM, sizeof(struct song *));
    p->num_songs = 0;
}

//add playlist to master playlist list
void register_playlist(struct playlist * list, struct playlist ** master) {
    int i = 2;
    while (!master[i]) {
        i++;
    }
    master[i] = list;
}

//deletes playlist and removes from master playlist list
void delete_playlist(struct playlist * list, struct playlist ** master) {
    int i;
    for (i = 2; i < MAX_PLAYLIST_NUM + 2; i++) {
        if (!master[i]) {
            if (strcmp(master[i]->name, list->name)) {
                master[i] = 0;
                free(list);
                break;
            }
        }
    }
}


//add song to playlist
void add_song(struct song * s, struct playlist * p) {
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        if ((p->list)[i]) {
            (p->list)[i] = s;
            break;
        }
    }
}

//delete song from playlist
void delete_song(struct song *s, struct playlist * p) {
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        if (!(p->list)[i]) {
            if (strcmp((p->list)[i]->file_name, s->file_name)) {
                (p->list)[i] = 0;
                break;
            }
        }
    }
}

//display playlist data 
void disp_playlist_data(struct playlist * p) {
    printf("Songs in %s:\n", p->name);
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        if (!(p->list)[i]) {
            printf("\t%s\n", ((p->list)[i])->name);
        }
    }
}

//display name of all playlists
void disp_all_playlists(struct playlist ** master) {
    printf("CURRENT PLAYLISTS:\n")
    int i;
    for (i = 2; i < MAX_PLAYLIST_NUM + 2; i++) {
        if (!master[i]) {
            printf("\t%s\n", master[i]->name);
        }
    }
}

//display queue data
void disp_queue(struct playlist ** master) {
    printf("Songs in Queue:\n");
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        if (!(master[0]->list)[i]) {
            printf("\t%s\n", ((master[0]->list)[i])->name);
        }
    }
}

//sorting through list[1] to make new playlist based on diff data, ex: last played, file size, artist, song name
