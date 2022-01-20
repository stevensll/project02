#include "song.h"

//for declaring the structs, and functions that modify the structs

//creates a song and adds its name, file_size, and atime
struct song * create_song(char * file_name) {
    struct song * s = malloc(sizeof(struct song));
    strncpy(s->file_name, file_name, STRING_SIZE);
    char * name = file_name_to_name(file_name);
    strncpy(s->name, name, STRING_SIZE);
    struct stat info;
    stat(s->file_name, &info);
    s->atime = info.st_atime;
    s->size = info.st_size;

}

//prints out all the data contained within the song struct
void print_data(struct song *s) {
    printf("Info for %s: \n", s->name);
    printf("\tFile name: %s\n", s->file_name);
    if (!s->artist) printf("\tArtist: %s\n", s->artist);
    if (!s->genre) printf("\tGenre: %s\n", s->genre);
    if (s->pub_year) printf("\tPublication Year: %d\n", s->pub_year);
    printf("\tFile size: %d\n", s->size);
    printf("\tTime of last access: %s\n", ctime(&s->atime));
}

//converts file name to song name by cutting off the ".mp3"
char * file_name_to_name(char * file_name) {
    char name[STRING_SIZE];
    strncpy(name, file_name, strlen(file_name) - 4);
    char * namep = name;
    return namep;
}

void change_name(struct song *s, char * name) {
    strncpy(s->name, name, sizeof(name));
}

void change_artist(struct song *s, char * artist) {
    strncpy(s->artist, artist, sizeof(artist));
}

void change_genre(struct song *s, char * genre) {
    strncpy(s->genre, genre, sizeof(genre));
}

void change_pub_year(struct song *s, int yr) {
    s->pub_year = yr;
}

//updates when the song was last accessed
void update_atime(struct song *s) {
    struct stat info;
    stat(s->file_name, &info);
    s->atime = info.st_atime;
}
