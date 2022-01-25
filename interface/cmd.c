#include "cmd.h"
#define DELIM "`"
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
        line[i] = strsep(&curr, DELIM);
        i++;
    }
    line[i] = '\0';
    return line;
}
