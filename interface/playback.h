

char ** foo_cmd(char * input);

/*
Initializes SDL and SDL-mixer API
*/
int mixer_setup();

/*
Plays the song by the specified filename. First forks a child process to let SDL handle
playback
*/
int play_song(char* PATH, char * filename);