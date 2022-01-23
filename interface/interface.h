#include "playlist.h"
#include <dirent.h>

//setup function (sets up queue, master playlist)
struct playlist ** setup();

//add mp3 miles in current directory to master playlist
void get_songs_from_dir(char * path, struct playlist ** master);

//ask for input from command line and return command
// char * get_input();

//run command
// void run_cmd(char * cmd);

//separates cmd line input to readable form
// char ** str_sep(char * cmd);

//functions for all the commands

//display man page (all the commands needed)

//writing/reading import functions (will save the list of playlists)

