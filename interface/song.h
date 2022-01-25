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
#define STRING_SIZE 200

struct song {
    char file_name[STRING_SIZE]; //actual name of file, ex. "honey.mp3"
    char name[STRING_SIZE]; //name of song, ex. "Honey"
    char artist[STRING_SIZE]; //artist name, ex. "Johnny Balik"
    char genre[30]; //genre, ex. "pop"
    int pub_year; //year of publication, ex. "2018"
    int size; //size of the file in bytes, ex. "1000000"
    // time_t atime; //time of last access
};

struct song * create_song(char *file_name); //creates a song and adds its name, file_size, and atime

void print_data(struct song *s); //prints out all the data contained within the song struct

void change_name(struct song *s, char * name); 

void change_artist(struct song *s, char * name); 

void change_genre(struct song *s, char * genre); 

void change_pub_year(struct song *s, int yr); 

// void update_atime(struct song *s); //updates when the song was last accessed

