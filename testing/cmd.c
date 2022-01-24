#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#include "cmd.h"

char ** process_cmd(char * input){
    //removes any newlines
    char *temp;
    if ((temp=strchr(input, '\n'))!=NULL) {
        *temp ='\0';
    }

    char ** args = calloc(sizeof(input)/sizeof(char), sizeof(char *));
    char * curr = input;
    int i = 0;
    while (curr){
        // the first arg will be the cmd
        args[i] = strsep(&curr, "--");
        i++;
    }
    args[i] = NULL;
    return args;
}


