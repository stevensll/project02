#include "interface.h"

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

    printf("For list of commands, type 'help'. \n");

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
int run_cmd(char ** cmd, struct, playlist ** master) {
    if (!strcmp(cmd[0], "exit")) {
        return 0;
    }
    else if (!strcmp(cmd[0], "disp_songs")) {
        disp_all_songs(master);
    }
    else if (!strcmp(cmd[0], "disp_playlists")) {
        disp_all_playlists(master);
    }
    else if (!strcmp(cmd[0], "song_info")) {
        //find song struct s from song name
        struct song * s = get_song(cmd[1]);
        print_data(s);
    }
    else if (!strcmp(cmd[0], "playlist_info")) {
        //find playlist struct p from name
        struct playlist * p = get_playlist(cmd[1]);
        disp_playlist_data(p);
    }
    else if (!strcmp(cmd[0], "add_song")) {
        //find playlist struct p from cmd[2]
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        struct playlist * p = get_playlist(cmd[2]);
        add_song(s, p);
    }
    else if (!strcmp(cmd[0], "delete_song")) {
        //find playlist struct p from cmd[2]
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        struct playlist * p = get_playlist(cmd[2]);
        delete_song(s, p);
    }
    else if (!strcmp(cmd[0], "delete_playlist")) {
        //find playlist struct p from cmd[1]
        struct playlist * p = get_playlist(cmd[1]);
        delete_playlist(p, master);
    }
    else if (!strcmp(cmd[0], "create_playlist")) {
        struct * playlist p = create_playlist(cmd[1]);
        register_playlist(p, master);
    }
    else if (!strcmp(cmd[0], "song_name")) {
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        change_name(s, cmd[2]);
    }
    else if (!strcmp(cmd[0], "song_artist")) {
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        change_artist(s, cmd[2]);
    }
    else if (!strcmp(cmd[0], "song_genre")) {
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        change_genre(s, cmd[2]);
    }
    else if (!strcmp(cmd[0], "queue_list")) {
        //find playlist struct p from cmd[1]
        struct playlist * p = get_playlist(cmd[1]);
        queue_playlist(p, master);
    }
    else if (!strcmp(cmd[0], "queue_song")) {
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        queue_song(s, master);
    }
    else if (!strcmp(cmd[0], "dequeue_song")) {
        //find song struct s from cmd[1]
        struct song * s = get_song(cmd[1]);
        dequeue_song(s, master);
    }
    else if (!strcmp(cmd[0], "queue")) {
        disp_queue(master);
    }
    else if (!strcmp(cmd[0], "clear_queue")) {
        clear_queue(master);
    }
    else if (!strcmp(cmd[0], "play_queue")) {
        //steven sdl magick
    }

    return 1;
}

//display help page (all the commands needed)
void disp_help_page() {
    //read help.txt
    printf("Welcome to the Help page!\nHere are some relevant commands:\n\t- disp_songs\n\t- disp_playlists\n\t- song_info song_name\n\t- playlist_info playlist_name\n\t- create_playlist playlist_name\n\t- add_song song_name playlist_name\n\t- delete_song song_name playlist_name\n\t- delete_playlist playlist_name\n\t- song_artist song_name artist\n\t- song_genre song_name genre\n\t- song_pub_year song_name pub_year\n\t- queue_list playlist_name\n\t- queue song_name\n\t- dequeue song_name\n\t- play_queue\n\t- clear_queue\n\t- exit\n\t- queue\n");
}


//writing/reading import functions (will save the list of playlists)

