#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct song_node {
    char title[256];
    char artist[256];
    struct song_node *next;
};

unsigned char * lower(char *str);

//print the entire list
void print_list(struct song_node *);

void print_song(struct song_node *);

//insert nodes at the front
struct song_node * insert_front(struct song_node *, char *, char *);

//insert nodes in order
struct song_node * insert_sorted(struct song_node *, char *, char *);

//find and return a pointer to a node based on artist and song name
struct song_node * find_song(struct song_node *, char *);

//find and return a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node *, char *);

//Return a pointer to random element in the list
struct song_node * random_element(struct song_node *);

//remove a single specified node from the list
void remove_song(struct song_node *, struct song_node *);

//free the entire list
struct song_node * free_list(struct song_node *);

unsigned long llist_len(struct song_node *);
