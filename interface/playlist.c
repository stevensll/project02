#include "playlist.h"

//creates master playlist (queue will be list[0], master playlist of songs will be list[1])
struct playlist ** create_master_list() {
    struct playlist ** master_list = calloc(MAX_PLAYLIST_NUM + 2, sizeof(struct playlist *));
    char queue[STRING_SIZE] = "Queue";
    char master[STRING_SIZE] = "Master List";
    char * queuep = queue;
    char * masterp = master;
    master_list[0] = create_playlist(queuep);
    master_list[1] = create_playlist(masterp);
    return master_list;
}

//create playlist
struct playlist * create_playlist(char *playlist_name) {
    struct playlist * p = malloc(sizeof(struct playlist));
    strncpy(p->name, playlist_name, STRING_SIZE);
    p->list = calloc(MAX_SONG_NUM, sizeof(struct song *));
    p->num_songs = 0;
}

int playlist_size(struct playlist * p) {
    int size = 0;
    for (int i = 0; i < MAX_SONG_NUM; i++) {
        if ((p->list)[i]) size++;
        else break;
    }
    return size;
}

//add playlist to master playlist list
void register_playlist(struct playlist * list, struct playlist ** master) {
    int i;
    for (i = 2; i < MAX_PLAYLIST_NUM + 2; i++) {
        if (!master[i]) {
            master[i] = list;
            break;
        }
    }
}

//add song to master playlist
void register_song(struct song * s, struct playlist ** master) {
    add_song(s, master[1]);
}

//deletes playlist and removes from master playlist list
void delete_playlist(struct playlist * list, struct playlist ** master) {
    int i;
    for (i = 2; i < MAX_PLAYLIST_NUM + 2; i++) {
        if (master[i]) {
            if (!strcmp(master[i]->name, list->name)) {
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
        if (!(p->list)[i]) {
            (p->list)[i] = s;
            //printf("added %s to %s sub %d\n", s->name, p->name, i);
            break;
        }
    }
}

//delete song from playlist
void delete_song(struct song *s, struct playlist * p) {
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        if ((p->list)[i]) {
            if (!strcmp((p->list)[i]->file_name, s->file_name)) {
                (p->list)[i] = 0;
                //shift everything down
                int j;
                for (j = i + 1; MAX_SONG_NUM; j++) {
                    if (!p->list[j]) {
                        p->list[j-1] = 0;
                        break;
                    }
                    else {
                        p->list[j-1] = p->list[j];
                    }
                }
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
        if ((p->list)[i]) {
            printf("\t%s\n", ((p->list)[i])->name);
        }
    }
}

//display name of all playlists
void disp_all_playlists(struct playlist ** master) {
    printf("CURRENT PLAYLISTS:\n");
    int i;
    for (i = 2; i < MAX_PLAYLIST_NUM + 2; i++) {
        if (master[i]) {
            printf("\t%s\n", master[i]->name);
        }
    }
}

//display queue data
void disp_queue(struct playlist ** master) {
    disp_playlist_data(master[0]);
    // printf("Songs in Queue:\n");
    //if (master[0]) printf("queue exists");
    // int i;
    // for (i = 0; i < MAX_SONG_NUM; i++) {
    //     if ((master[0]->list)[i]) {
    //         printf("\t%s\n", ((master[0]->list)[i])->name);
    //     }
    // }
}

void disp_all_songs(struct playlist ** master) {
    disp_playlist_data(master[1]);
}

//adds song to queue
void queue_song(struct song * s, struct playlist ** master) {
    add_song(s, master[0]);
}

void dequeue_song(struct song * s, struct playlist ** master) {
    delete_song(s, master[0]);
}

void queue_playlist(struct playlist * p, struct playlist ** master) {
    clear_queue(master);
    int size = playlist_size(p);
    int i;
    for (i = 0; i < size; i++) {
        ((master[0])->list)[i] = (p->list)[i];
    }
}

void clear_queue(struct playlist ** master) {
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        ((master[0])->list)[i] = 0;
    }
}

//get song struct from song name
int get_song(char * name, struct playlist ** master) {
    struct song * s;
    int i;
    for (i = 0; i < MAX_SONG_NUM; i++) {
        if (((master[1])->list)[i]) {
            if (!strcmp(((master[1])->list)[i]->name, name)) {
                return i;
            }
        }
    }
    return -1;
}

//get playlist struct from playlist name
int get_playlist(char * name, struct playlist ** master) {
    struct playlist * p;
    int i;
    for (i = 2; i < MAX_PLAYLIST_NUM + 2; i++) {
        if (master[i]) {
            if (!strcmp(master[i]->name, name)) {
                return i;
            }
        }
    }
    return -1;
}

//sorting through list[1] to make new playlist based on diff data, ex: last played, file size, artist, song name
