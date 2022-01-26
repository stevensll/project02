#include "interface.h"
#include "cmd.h"
int main() {

    //setup
    struct playlist ** master = setup();
    int running = 1;
    int start = 1;

    while (running) {
        
        //get input and run command
        char input[STRING_SIZE];
        fgets(input, sizeof(input), stdin);
        char ** cmds = process_cmd(input);
        if (!start) running = run_cmd(cmds, master);
        start = 0;
    }
    
    

    return 0;
}