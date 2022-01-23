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

    struct playlist ** master = setup();
    
    while (1) {
        //get input
        //run command
    }

    return 0;
}