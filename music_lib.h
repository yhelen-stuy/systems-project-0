#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct song_node* lib[26];
// Add songs.
void add_song(char *, char *);

// Search for a song.
struct song_node * search_song(char *);

// Search for an artist.
struct song_node * search_artist(char *);

// Print out all the entries under a certain letter.
void print_letter(char);

// Print out all the songs of a certain artist
void print_artist(char *);

// Print out the entire library.
void print_lib();

// Shuffle - print out a series of randomly chosen songs.
void shuffle(int);

// Delete a song
void delete_song(char *);

// Delete all the nodes.
void clear_lib();
