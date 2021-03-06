#include "playlist.h"
#include <dirent.h>

//setup function (sets up queue, master playlist)
struct playlist ** setup();

//add mp3 miles in current directory to master playlist. Returns 1 if path found -1 otherwise.
int get_songs_from_dir(char * path, struct playlist ** master);

//run command
int run_cmd(char ** cmd, struct playlist ** master);

//display man page (all the commands needed)
void disp_help_page();

//writing/reading import functions (will save the list of playlists)

