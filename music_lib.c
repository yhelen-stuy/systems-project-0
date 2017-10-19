#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "music_lib.h"

void add_song(char *title, char *artist) {
    char l = artist[0];
    char a = 'a';
    struct song_node *songs = lib[l-a];
    insert_sorted(songs, title, artist);
}

/* struct song_node * search_song(char *title) { */

/* } */

/* struct song_node * search_artist(char *artist) { */

/* } */

/* void print_letter(char letter) { */

/* } */

/* void print_artist(char* artist) { */

/* } */

void print_lib() {
    int i = 0;
    char a = 'a';
    for (; i < 26; i++) {
        if (llist_len(lib[i]) > 0) {
            printf("%c songs\n\t", (a + i));
            print_list(lib[i]);
        }
    }
}

/* void shuffle(int num_songs) { */

/* } */

/* void delete_song(char *title) { */

/* } */

/* void clear_lib() { */

/* } */
