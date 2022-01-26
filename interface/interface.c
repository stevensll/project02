#include "interface.h"
#include "playback.h"
#include "cmd.h"
//setup function (sets up queue, master playlist)
char PATH[200];
struct playlist ** setup() {

    printf("Welcome to SPetify!\n");

    //create master
    struct playlist ** master = create_master_list();

    //ask for folder to pull
    printf("Enter folder to open ('.' for current directory): ");
    scanf("%s", PATH);
    
    //get songs from folder
    get_songs_from_dir(PATH, master);
    strcat(PATH, "/");
    disp_all_songs(master);

    printf("For list of commands, type 'help'. \n");

    return master;
}

//add mp3 files in current directory to master playlist
void get_songs_from_dir(char * PATH, struct playlist ** master) {
    DIR * dir = opendir(PATH);
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

//run command
int run_cmd(char ** cmd, struct playlist ** master) {

    /*#######################
      #### Navigating UI ####
      #######################
    */
    if (!strcmp(cmd[0], "exit")) {
        return 0;
    }
    else if (!strcmp(cmd[0], "help")) {
        disp_help_page();
    }

    /*############################
      #### Manipulating Queue ####
      ############################
    */
    else if (!strcmp(cmd[0], "qshow")) {
        disp_queue(master);
    }
    else if (!strcmp(cmd[0], "qclear")) {
        clear_queue(master);
    }
    else if (!strcmp(cmd[0], "q") && cmd[1]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) queue_song(((master[1])->list)[s], master);
        else printf("Not a valid song!\n\n");
    }
    else if (!strcmp(cmd[0], "dq")&& cmd[1]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) dequeue_song(((master[1])->list)[s], master);
        else printf("Not a valid song!\n\n");
    }
    else if (!strcmp(cmd[0], "qplist") && cmd[1]) {
        //find playlist struct p from cmd[1]
        int p = get_playlist(cmd[1], master);
        if (p != -1) queue_playlist(master[p], master);
    }
    else if (!strcmp(cmd[0], "qplay")) {
        printf("Now playing...\n");
        disp_queue(master);
        printf("\n");
        printf("###########################################\n");
        printf("########## ENTERING MUSIC PLAYER ##########\n");
        printf("###########################################\n\n");
        while(master[0]->list[0]){
            // printf("%s\n", master[0]->list[0]->file_name);
            int k = play_song(PATH,master[0]->list[0]->file_name);
            dequeue_song(master[0]->list[0], master);
            printf("K: %d", k);
            if(k > 0) break;
        }
        printf("##########################################\n");
        printf("########## EXITING MUSIC PLAYER ##########\n");
        printf("##########################################\n\n");
    }

    /*#######################
      #### Song commands ####
      #######################
    */
    else if (!strcmp(cmd[0], "sinfo") && cmd[1]) {
        //find song struct s from song name
        int s = get_song(cmd[1], master);
        if (s != -1) print_data(((master[1])->list)[s]);
    }
    else if (!strcmp(cmd[0], "sname") && cmd[1] && cmd[2]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_name(((master[1])->list)[s], cmd[2]);
        else printf("Invalid song name!\n\n");
    }
    else if (!strcmp(cmd[0], "sartist") && cmd[1] && cmd[2]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_artist(((master[1])->list)[s], cmd[2]);
        else printf("Invalid song name!\n\n");
    }
    else if (!strcmp(cmd[0], "sgenre") && cmd[1] && cmd[2]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_genre(((master[1])->list)[s], cmd[2]);
        else printf("Invalid song name!\n\n");
    }
    else if (!strcmp(cmd[0], "spub") && cmd[1] && cmd[2]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_pub_year(((master[1])->list)[s], atoi(cmd[2]));
        else printf("Invalid song name!\n\n");
    }

    /*##########################
      #### Display commands ####
      ##########################
    */
    else if (!strcmp(cmd[0], "disp_songs")) {
        disp_all_songs(master);
    }
    else if (!strcmp(cmd[0], "disp_playlists")) {
        disp_all_playlists(master);
    }

    else if (!strcmp(cmd[0], "playlist_info") && cmd[1]) {
        //find playlist struct p from name
        int p = get_playlist(cmd[1], master);
        if (p != -1) disp_playlist_data(master[p]);
    }
    else if (!strcmp(cmd[0], "add_song") && cmd[1] && cmd[2]) {
        //find playlist struct p from cmd[2]
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        int p = get_playlist(cmd[2], master);
        if (s != -1 && p != -1) add_song(((master[1])->list)[s], master[p]);
    }
    else if (!strcmp(cmd[0], "delete_song") && cmd[1] && cmd[2]) {
        //find playlist struct p from cmd[2]
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        int p = get_playlist(cmd[2], master);
        if (s != -1 && p != -1) delete_song(((master[1])->list)[s], master[p]);
    }
    else if (!strcmp(cmd[0], "delete_playlist") && cmd[1]) {
        //find playlist struct p from cmd[1]
        int p = get_playlist(cmd[1], master);
        if (p != -1) delete_playlist(master[p], master);
    }
    else if (!strcmp(cmd[0], "create_playlist") && cmd[1]) {
        struct playlist * p = create_playlist(cmd[1]);
        register_playlist(p, master);
    }
    else {
        printf("Invalid command/arguments. Please type 'help' for list of commands. Remember to separate your arguments with a '~'!\n");
    }

    return 1;
}

//display help page (all the commands needed)
void disp_help_page() {
    //read help.txt
    int file = open("help.txt", O_RDONLY);
    if (file == -1) {
        printf("Error opening help file: %s\n", strerror(errno));
    }
    struct stat info;
    stat("help.txt", &info);
    int size = info.st_size;
    char data[size];
    int err= read(file, data, size-5);
    if (err == -1) {
        printf("Error reading help file: %s\n", strerror(errno));
    }
    close(file);
    printf("\n--------------------------------------------------------------------\n\n");
    printf("%s", data);
    printf("\n\n--------------------------------------------------------------------\n\n");
}


//writing/reading import functions (will save the list of playlists)

