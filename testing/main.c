#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720
#define INPUT_SIZE 500
int main(int argc, char* argv[]){

    Mix_Music * music = NULL;
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)==-1) {
        printf("SDL_Init: %s\n", SDL_GetError());
        return -1;
    }
    // open 44.1KHz, signed 16bit, system byte order,
    //      stereo audio, using 1024 byte chunks
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)==-1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        return -1;
    }

    music = Mix_LoadMUS("DMZ.mp3");
    if (music == NULL){
        printf("Mix_LoadUMS: %s\n", Mix_GetError());
        return -1;
    }
    
    int i = Mix_PlayMusic(music, 1);
    Mix_VolumeMusic(0.5 * MIX_MAX_VOLUME);
    // Mix_SetMusicPosition(100);
    

    

    int running = 1;
    while(running){
        if(!Mix_PlayingMusic()) return 1;
    }
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}