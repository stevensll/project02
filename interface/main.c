//for putting everything together

#include "main.h"
#include "interface.h"
#include "playlist.h"
#include "song.h"

int main() {

    struct playlist ** master = setup();

    while (1) {

        char * cmd = get_input();

        //if cmd is exit, break
        
        run_cmd(cmd);


    }
    
    return 0;
}