#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>

#define MAX_INPUT_SIZE 500


/*  
    Process the command and get an argument, if given. Returns an arraylist where line[0] = command and line[1] = argument
*/
char ** get_cmd(char * cmd){
    //get rid of the newline
    char *temp;
    if ((temp=strchr(cmd, '\n')) !=NULL) *temp ='\0';

    char ** line = calloc(sizeof(cmd)/sizeof(char), sizeof(char *));
    char * curr = cmd;
    int i = 0;
    while(curr && i < 2){
        line[i] = strsep(&curr, " ");
        i++;
    }
    line[i] = NULL;
    return line;
}

void print_string_arr(char ** arr){
    int i = 0;
    while(arr[i]){
        printf("arr[%d] = %s\n", i, arr[i]);
        i++;
    }
    printf("\n");
}
int main(int argc, char* argv[]){

    // print_string_arr(cmd);
    // printf("%s", cmd[0]);
    int running = 1;

    while(1){
        char input[MAX_INPUT_SIZE];
        fgets(input, sizeof(input), stdin);
        char ** cmd = get_cmd(input);
        int i = 0;
        char ** in = cmd[i];
        while(in){
            if (!strcmp(in, "pause")){
                printf("Got pause!\n");
            }
            // else if (!strcmp(cmd[0], "resume")){
            //     printf("Got resume!\n");
                
            // }
            // else if (!strcmp(cmd[0], "fwd")){
            //     printf("Got fwd!\n");

            // }
            // else if (!strcmp(cmd[0], "rwd")){
            //     printf("Got rwd!\n");

            // }
            // else if (!strcmp(cmd[0], "skip")){
            //     printf("Got skip!\n");
            // }

            // else if (!strcmp(cmd[0], "help")){
            //     printf("Got help!\n");

            // } else {
            //     printf("Please enter a valid command.\n");
            // }
            i++;
            cmd = cmd[i];
        }
        free(cmd);
    }
}