#include "song.h"
//for declaring the structs, and functions that modify the structs

//creates a song and adds its name, file_size, and atime
struct song * create_song(char * file_name, char * PATH) {
    struct song * s = malloc(sizeof(struct song));
    strncpy(s->file_name, file_name, STRING_SIZE);
    strncpy(s->name, file_name, strlen(file_name) - 4);
    (s->name)[strlen(file_name) - 4] = '\0';
    struct stat info;

    char path_copy[500];
    strcpy(path_copy, PATH);
    strcat(path_copy, "/");
    char file_name_copy[500];
    strcpy(file_name_copy, s->file_name);
    char * cat = strcat(path_copy,file_name_copy);
    
    stat(cat, &info);
    // s->atime = info.st_atime;
    s->size = info.st_size;
    change_genre(s, "Unknown");
    change_artist(s, "Unknown");
    change_pub_year(s, 0);
    return s;
}

//prints out all the data contained within the song struct
void print_data(struct song *s) {
    printf("Info for %s: \n", s->name);
    printf("\tFile name: %s\n", s->file_name);
    if (s->artist) printf("\tArtist: %s\n", s->artist);
    if (s->genre) printf("\tGenre: %s\n", s->genre);
    if (s->pub_year) printf("\tPublication Year: %d\n", s->pub_year);
    printf("\tFile size: %d\n", s->size);
    // update_atime(s);
    // printf("\tTime of last access: %s\n", ctime(&s->atime));
}

void change_name(struct song *s, char * name) {
    strncpy(s->name, name, STRING_SIZE);
}

void change_artist(struct song *s, char * artist) {
    strncpy(s->artist, artist, STRING_SIZE);
}

void change_genre(struct song *s, char * genre) {
    strncpy(s->genre, genre, 30);
}

void change_pub_year(struct song *s, int yr) {
    s->pub_year = yr;
}

//updates when the song was last accessed
// void update_atime(struct song *s) {
//     struct stat info;
//     stat(s->file_name, &info);
//     s->atime = info.st_atime;
// }
