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
    if ((temp=strchr(input, '\n'))!=0) {
        *temp ='\0';
    }

    char ** line = calloc(sizeof(input)/sizeof(char), sizeof(char *));
    char * curr = input;
    int i = 0;
    while(curr){
        line[i] = strsep(&curr, "--");
        i++;
    }
    line[i] = '\0';
    return line;
}


