#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){
    int result = 0;
    if(SDL_Init(SDL_INIT_AUDIO)){
        printf("SDL could not be initialized");
    }

    if(MIX_INIT_MP3 != (result = MixInit(MIX_INIT_MP3)){
        printf("Could not initialize mixer");
    }
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2,640);
    Mix_Music *music = Mix_LoadMUS("Refelection.mp3");
    Mix_PlayMusic(music, 1);
    while (!SDL_QuitRequested()){
        SDL_Delay(250);
    }
    Mix_FreeMusic (music);
    SDL_Quit();

    return 0;
}