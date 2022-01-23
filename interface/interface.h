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

//setup function (sets up queue, master playlist)
struct playlist ** setup() {
    printf("Welcome to SPotify!\nPlease type 'man' for list of commands.");
    struct playlist ** master = create_master_list();
    return master;
}

//ask for input from command line and return command
char * get_input() {
    printf("# ");
    char input[STRING_SIZE];
    fgets(input, sizeof(input), stdin);
    return input;
}

//run command
void run_cmd(char * cmd);

//separates cmd line input to readable form
char ** str_sep(char * cmd);

//functions for all the commands

//display man page (all the commands needed)

//writing/reading import functions (will save the list of playlists)

