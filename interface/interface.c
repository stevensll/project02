#include "interface.h"

//interface commands


//setup function (sets up queue, master playlist)
struct playlist ** setup() {

    printf("Welcome to SPotify!\n");

    //create master
    struct playlist ** master = create_master_list();

    //ask for folder to pull
    char path[200];
    printf("Enter folder to open ('.' for current directory): ");
    scanf("%s", path);

    //get songs from folder
    get_songs_from_dir(path, master);
    disp_all_songs(master);

    printf("For list of commands, type 'man'. \n");

    return master;
}

//add mp3 miles in current directory to master playlist
void get_songs_from_dir(char * path, struct playlist ** master) {
    DIR * dir = opendir(path);
    if (!dir) {
        printf("Error: %s\n", strerror(errno));
    } 
    struct dirent *file = readdir(dir);
    struct stat info;
    while (file) {
        stat(file->d_name, &info);
        if ((file->d_type == DT_REG) && (strstr(file->d_name, ".mp3"))) {
            struct song * new_song = create_song(file->d_name);
            register_song(new_song, master);
        }
        file = readdir(dir);
    }
    closedir(dir);
}

//ask for input from command line and return command
// char * get_input() {
//     printf("# ");
//     char input[STRING_SIZE];
//     fgets(input, sizeof(input), stdin);
//     inputp
//     return input;
// }

//run command
// void run_cmd(char * cmd);

//separates cmd line input to readable form
// char ** str_sep(char * cmd);

//functions for all the commands

//display man page (all the commands needed)

//writing/reading import functions (will save the list of playlists)

