

/*
Initializes SDL and SDL-mixer API
*/
int mixer_setup();

/*
Plays the song by the specified filename. First forks a child process to let SDL handle
playback.

Returns 1 if player finished playing all songs in the queue.
Returns -1 if player was exited.
*/
int play_song(char* PATH, char * filename);