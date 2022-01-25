#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include "playback.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


#define MAX_INPUT_SIZE 500

char ** foo_cmd(char * input){
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
int mixer_setup(){
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)==-1) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return -1;
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)==-1) {
        printf("Mix_OpenAudio error: %s\n", Mix_GetError());
        return -1;
    }
}

int play_song(char * PATH, char * song){
    int status, w;
    if(fork()==0){
        printf("Playing %s\nPlease press enter when the current song is finished to advance to next song.\n\n", song);
        int setup = mixer_setup();
        Mix_Music * music = NULL;
            music = Mix_LoadMUS(strcat(PATH,song));
            if (music == NULL){
                printf("Error loading MP3: %s\n", Mix_GetError());
                return -1;
            }
        int i = Mix_PlayMusic(music, 1);
        int running = 1;
        /*We will use an additional pause variable to keep track of the song's true pause state, 
        since Mix_PlayingMusic() can either imply it is paused or not playing anymore.
        */
        int pause = 0;
        char input[500];
        while(running){
            fgets(input, sizeof(input), stdin);
            char ** cmds = foo_cmd(input);
            //SKIP the song
            if(!strcmp(cmds[0], "skip")){
                printf("Skipping song\n\n");
                running = 0;
            }
            //PAUSE the song
            else if (!strcmp(cmds[0], "pause")){
                pause = 1;
                printf("Pausing song\n\n");
                Mix_PauseMusic();
            }
            //RESUME the song
            else if(!strcmp(cmds[0], "resume")){
                pause = 0;
                printf("Resuming song\n\n");
                Mix_ResumeMusic(); 
            //SET THE VOLUME of the song. In range of 0.0-1.0
            } else if(!strcmp(cmds[0], "setv")&& cmds[1]){
                double v;
                char * temp;
                v = strtod(cmds[1], &temp);
                printf("Setting volume to %f\n\n", v);
                Mix_VolumeMusic(v * MIX_MAX_VOLUME);
            //DISPLAY THE Playbackhelp page
            } else if(!strcmp(cmds[0], "pbhelp")){
                int file = open("pbhelp.txt", O_RDONLY);
                if (file == -1) {
                    printf("Error opening pbhelp file: %s\n", strerror(errno));
                }
                struct stat info;
                stat("pbhelp.txt", &info);
                int size = info.st_size;
                char data[size];
                int err= read(file, data, size-2);
                if (err == -1) {
                    printf("Error reading pbhelp file: %s\n", strerror(errno));
                }
                close(file);
                printf("\n--------------------------------------------------------------------\n\n");
                printf("%s", data);
                printf("\n\n--------------------------------------------------------------------\n\n");
            }
            else {
                printf("Please enter a proper command/arguments! Use pbhelp for a list of commands.\n\n");
            }
            if(!Mix_PlayingMusic() && !pause){
                running = 0;
            }
        }
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = NULL;
        Mix_Quit();
        SDL_Quit();
        exit(0);
    } else {
        w = wait(&status);
        // printf("Finished playing song\n");
        return 1;
    }      
}
