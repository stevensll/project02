
# IGNORE THIS, THESE ARE JUST NOTES

### Instructions
1) Clean install SDL and mingw
2) Install SDL_mixer
3) Configure SDL and mingw in path
4) Compile
https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_frame.html



# SDL Mixer Usage

```c
//Sets up SDL API

if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)==-1) {

 printf("SDL_Init: %s\n", SDL_GetError());

 return -1;

}

// Mix_OpenAudio(freq, format,channels,chunksize) > Sets up Mixer API.

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)==-1) {

 printf("Mix_OpenAudio: %s\n", Mix_GetError());

 return -1;

 }

// Mix_Music > pointer data type for music. `Mix_Chunk` > for very short audio clips.

Mix_Music * music = NULL;

// Mix_LoadMUS > loads files in WAVE, MOD, MIDI, OGG, MP3, FLAC

music = Mix_LoadMUS("DMZ.mp3");

if (music == NULL){

 printf("Mix_LoadUMS: %s\n", Mix_GetError());

 return -1;

}

//Plays music, x times, where -1 is infinite repeat

Mix_PlayMusic(music, -1);

//Volume from 0 to MIX_MAX_VOLUME(128)
Mix_VolumeMusic();

Mix_PauseMusic();
Mix_ResumeMusic();
Mix_RewindMusic();

//DANGER! Only supports MOD, OGG, and MP3
//FOR MOD: JUST DONT USE IT
//FOR OGG: JUMPS TO POSITION SECONDS FROM BEGINNING
//FOR MP3: JUMPS TO POSITION SECONDS FROM THE CURRENT. USE Mix_RewindMusic()
Mix_SetMusicPosition();

Mix_HaltMusic();

//State stuff

Mix_PlayingMusic();
Mix_PausedMusic();
  
```