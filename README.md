# Systems Final Project: SPetify 
**Steven Lei & Peter Zhao 
Systems Period 5**

---
# Overview
SPetify is a terminal based MP3 music player. It contains song and playlist organization features as well as basic music playback such as skip, pause, and resume. [Proposal](https://github.com/stevensll/project02/blob/main/PROPOSAL.md)


## IMPORTANT 
Our program is designed to be directly tested on a linux machine. Based on our testing, SSH'ing into a linux machine will not grant audio permissions. Please makes sure the following libraries are installed on linux before compiling. Use `sudo apt-get install libsdl2-dev` and `sudo apt-get install libsdl2-mixer-dev`.

## Usage
You will need a directory containing MP3 files. Please make sure they do not contain the `|` character in their name.

Compile the program using `make` and run it using `make run`. When you first run the program, you will be prompted to provide a `PATH` to the directory containing the MP3 files (in this case a sample `music` directory has been provided). Please provide a valid `PATH` or the program will terminate.

Once provided the proper `PATH`, the program will prompt you to the **main interface**, where you can edit `song` information, create or remove `playlists`, and edit the `queue`. For a full list of commands and their functionalities, please type `help`. Note that a command and its arguments are separated by the `|` character. To terminate the program use `exit`.

After song(s) have been added to the queue, use `qplay` to play the songs. This will send you to the **music player interface**, where you can use basic playback controls like `skip`, `pause`, and `resume`. Please note that after a song is done playing, you will need to feed the terminal an input to move onto the next song (pressing enter will work). For a full list of commands use `pbhelp`. To return to the main interface and stop playing the queue, use `exit`.


