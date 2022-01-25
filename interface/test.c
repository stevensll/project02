#include "interface.h"

int main() {

    /*
    //song function tests
    struct song * reflection = create_song("Reflection.mp3");  
    print_data(reflection);
    change_name(reflection, "mulan song");
    change_artist(reflection, "idk");
    change_genre(reflection, "Children's Music");
    change_pub_year(reflection, 1998);
    print_data(reflection);
    struct song * DMZ = create_song("DMZ.mp3");  
    print_data(DMZ);

    //playlist function tests
    struct playlist * disney = create_playlist("disney");
    disp_playlist_data(disney);
    add_song(reflection, disney);
    disp_playlist_data(disney);
    delete_song(reflection, disney);
    disp_playlist_data(disney);

    //playlists in master list tests
    struct playlist ** master = create_master_list();
    register_song(reflection, master);
    register_song(DMZ, master);
    disp_all_songs(master);
    delete_song(reflection, master[1]);
    disp_all_songs(master);
    register_song(reflection, master);
    disp_all_songs(master);
    disp_all_playlists(master);
    add_song(reflection, disney);
    register_playlist(disney, master);
    disp_playlist_data(master[2]);
    disp_all_playlists(master);
    //delete_playlist(disney, master);
    //disp_all_playlists(master);

    //queue function tests
    disp_queue(master);
    queue_song(reflection, master);
    disp_queue(master);
    queue_song(DMZ, master);
    disp_queue(master);
    dequeue_song(reflection, master);
    disp_queue(master);
    queue_playlist(disney, master);
    disp_queue(master);
    clear_queue(master);
    disp_queue(master);
    */

    //setup
    struct playlist ** master = setup();
    //disp_help_page();

    //get song and get playlist tests
    // disp_all_songs(master);
    // struct playlist * test = create_playlist("test");
    // register_playlist(test, master);
    // int i = get_playlist("test", master);
    // printf("%d", i);
    // disp_playlist_data(master[i]);



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