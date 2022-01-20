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
#include "song.h"
#include "playlist.h"

int main() {
    struct song * reflection = create_song("Reflection.mp3");
    print_data(reflection);
    struct song * playlist[50];
    playlist[0] = reflection;
    print_data(playlist[0]);
    change_pub_year(playlist[0], 1998);
    print_data(playlist[0]);
    change_pub_year(reflection, 29);
    print_data(playlist[0]);
    return 0;
}