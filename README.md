# Project02 Proposal 
**Steven Lei & Peter Zhao 
Systems Period 5** 

--- 
## Overview 
We will be creating a terminal-based MP3 player with organizational and music-playing capabilities with the SDL C library. 

--- 
## User Interface 

*Prerequisites*: The program should be launched in a directory containing all MP3s that the user wants to listen to. 

### Main Menu Interface 
Our program will create a main terminal interface that will allow the user to play songs via a queue. Each song can be renamed, or given specific information like artist, genre, or publication date. The UI can also display additional data about each song, such as when it was last played, its byte size, and the playlists it belongs to. Playlists can be created by manually adding individual songs or through filters such as artist, genre, or publication date (up to 50 songs). Songs can also be removed from the playlist in the same manner. Playlists can be named, renamed, deleted, and display the list of songs within it. To play songs, the songs must be added to the queue, either as individual songs or as playlists. When the queue starts playing, the user will be moved to a listening interface.

### Listening Interface 
Within the listening interface, users can play/resume/pause, or skip to a certain time of the song. The song time will be displayed as the music is played. Users can also flat out skip to the next song in queue. Lastly, they can return to the main menu. 

## Technical Information 

### Design
At startup, the program will either read through an existing music library in a file or look through all the MP3 files in its directory, based on user input. It will then allocate memory in structs to hold data such as the name of the file, artist, the size of the file, the last time it was played, its number in queue, and the playlists it is in. We will use `stat` to determine this information about each file, and read from `stdin` to determine the rest. The program will then be able to save this music library for future use by writing to a file.

Playlists and the queue will be represented by arrays of song structs. Sorting functions parsing through songs based on the various struct elements will be available to create custom playlists. Other functions will be able to change data within each song, playlist, or queue through array manipulation.

When the queue starts playing, the program will fork to a child process, which is responsible for audio playback. We will use the functions in the SDL Mixer Library to play, pause, and skip to a certain time within the song. When it is given the input to skip or reaches the end of a given song, the child process will end and return to main interface before repeating the process for the next song in queue. 

### Resources
SDL Mixer is a C library that allows us to manipulate audio playback. MP3s are supported, and we will use this for our listening interface.

## Work Breakdown 
Peter: main menu interface
- data structure of `playlist`, `song`, `queue`  
- writing/reading music library of structs to/from a file
- sorting functions
- queue movement process

Steven: listening interface
- manipulating audio files 
- interaction between main and listening interfaces 

## Timeline
- 1/11-1/14: 
	- create the data framework for songs, queue, and playlists
	- be able to upload/manipulate mp3 files
- 1/15-1/16:
	- be able to write/read music library data 
	- work on sorting and other playlist manipulation functions
	- be able to play/pause/skip within songs
- 1/17-1/18:
	- finish playlist mainpulation functions
	- finish queue movement
	- finish song playback manipulation
- 1/19-1/20: 
	- Combine the two interfaces together
	- Add visuals for user convenience
