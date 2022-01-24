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


//Retrieves an argument from a command input
char ** get_cmd_args(char * cmd){
    //deletes newline at the end of the input
    char *pos;
    if ((pos=strchr(cmd, '\n')) != NULL) *pos = '\0';
    
    char ** args = calloc(sizeof(cmd)/sizeof(char), sizeof(char *));
    char * curr = cmd;
    int i = 0;
    while (curr){
        // the first arg will be the cmd
        args[i] = strsep(&curr, " ");
        i++;
        if(i > 1){
            break;
        }
    }
    args[i] = NULL;
    return args;
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
        char ** cmd = get_cmd_args(input);
        while(cmd[0]){
            if (!strcmp(cmd[0], "pause")){
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
        }
        free(cmd);
    }
}