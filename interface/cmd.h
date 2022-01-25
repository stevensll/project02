#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
Takes in a given input and returns a 2D array of strings separated by a delimitter.
The first entry is always the command and any entries following are the arguments.
*/
char ** process_cmd(char * input);
