#include "interface.h"
#include "playback.h"
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
    //printf("args[0]: %s| args[1]: %s| args[2]: %s|\n", cmd[0], cmd[1], cmd[2]);
    if (!strcmp(cmd[0], "exit")) {
        return 0;
    }
    else if (!strcmp(cmd[0], "help")) {
        disp_help_page();
    }
    else if (!strcmp(cmd[0], "disp_songs")) {
        disp_all_songs(master);
    }
    else if (!strcmp(cmd[0], "disp_playlists")) {
        disp_all_playlists(master);
    }
    else if (!strcmp(cmd[0], "song_info")) {
        //find song struct s from song name
        int s = get_song(cmd[1], master);
        if (s != -1) print_data(((master[1])->list)[s]);
    }
    else if (!strcmp(cmd[0], "playlist_info")) {
        //find playlist struct p from name
        int p = get_playlist(cmd[1], master);
        if (p != -1) disp_playlist_data(master[p]);
    }
    else if (!strcmp(cmd[0], "add_song")) {
        //find playlist struct p from cmd[2]
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        int p = get_playlist(cmd[2], master);
        if (s != -1 && p != -1) add_song(((master[1])->list)[s], master[p]);
    }
    else if (!strcmp(cmd[0], "delete_song")) {
        //find playlist struct p from cmd[2]
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        int p = get_playlist(cmd[2], master);
        if (s != -1 && p != -1) delete_song(((master[1])->list)[s], master[p]);
    }
    else if (!strcmp(cmd[0], "delete_playlist")) {
        //find playlist struct p from cmd[1]
        int p = get_playlist(cmd[1], master);
        if (p != -1) delete_playlist(master[p], master);
    }
    else if (!strcmp(cmd[0], "create_playlist")) {
        struct playlist * p = create_playlist(cmd[1]);
        register_playlist(p, master);
    }
    else if (!strcmp(cmd[0], "song_name")) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_name(((master[1])->list)[s], cmd[2]);
    }
    else if (!strcmp(cmd[0], "song_artist")) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_artist(((master[1])->list)[s], cmd[2]);
    }
    else if (!strcmp(cmd[0], "song_genre")) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_genre(((master[1])->list)[s], cmd[2]);
    }
    else if (!strcmp(cmd[0], "song_pub_year")) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) change_pub_year(((master[1])->list)[s], cmd[2]);
    }
    else if (!strcmp(cmd[0], "qlist")) {
        //find playlist struct p from cmd[1]
        int p = get_playlist(cmd[1], master);
        if (p != -1) queue_playlist(master[p], master);
    }
    else if (!strcmp(cmd[0], "q") && cmd[1]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) queue_song(((master[1])->list)[s], master);
    }
    else if (!strcmp(cmd[0], "dq")&& cmd[1]) {
        //find song struct s from cmd[1]
        int s = get_song(cmd[1], master);
        if (s != -1) dequeue_song(((master[1])->list)[s], master);
    }
    else if (!strcmp(cmd[0], "qshow")) {
        disp_queue(master);
    }
    else if (!strcmp(cmd[0], "qclear")) {
        clear_queue(master);
    }
    else if (!strcmp(cmd[0], "qplay")) {
        printf("Now playing...\n");
        disp_queue(master);
        printf("\n");
        printf("###########################################\n");
        printf("########## ENTERING MUSIC PLAYER ##########\n");
        printf("###########################################\n");
        while(master[0]->list[0]){
            printf("%s\n", master[0]->list[0]->file_name);
            play_song(strcat(PATH,"/"),master[0]->list[0]->file_name);
            dequeue_song(master[0]->list[0], master);
        }
        printf("##########################################\n");
        printf("########## EXITING MUSIC PLAYER ##########\n");
        printf("##########################################\n");
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
    int err= read(file, data, size-2);
    if (err == -1) {
        printf("Error reading help file: %s\n", strerror(errno));
    }
    close(file);
    printf("\n--------------------------------------------------------------------\n\n");
    printf("%s", data);
    printf("\n\n--------------------------------------------------------------------\n\n");
}

char ** process_cmd(char * input){
    //removes any newlines
    char *temp;
    if ((temp=strchr(input, '\n'))!=0) {
        *temp ='\0';
    }

    char ** line = calloc(sizeof(input)/sizeof(char), sizeof(char *));
    char * curr = input;
    int i = 0;
    while(curr){
        line[i] = strsep(&curr, "~");
        i++;
    }
    line[i] = '\0';
    return line;
}


//writing/reading import functions (will save the list of playlists)

