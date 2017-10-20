#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "linked_list.h"
#include "music_lib.h"

// Add a song to the lib by the artist name
// in sorted order for the linked list
void add_song(char *title, char *artist) {
    char l = tolower(artist[0]);
    char a = 'a';
    struct song_node *songs = lib[l-a];
    lib[l-a] = insert_sorted(songs, title, artist);
}

// Look through the song for a specific title
struct song_node * search_song(char *title) {
    int i = 0;
    for(; i < ('z' - 'a') ; i++) {
        struct song_node *song = find_song(lib[i], title);
        if (song) {
            return song;
        }
    }
    return 0;
}

//ignore the ugly mess
/*struct song_node * search_artist(char *artist) {
  unsigned char l_artist[strlen(artist)];
  lower(strcpy(l_artist, artist));
  char l = l_artist[0];
  char a = 'a';
  struct song_node *art = find_artist(lib[l-a], l_artist);
  struct song_node *head = 

  struct song_node *head = art;
  struct song_node *prev = art;
//printf("ONE");
while(art && art->next && (strcmp(art->next->artist, l_artist) == 0)) {
printf("RAN\n");
prev = art;
art = art -> next;
}
if(art)
art -> next = NULL;
return head;
}*/

// Find the pointer to the artist in the appropriate index of the lib
struct song_node * search_artist(char *artist) {
    unsigned char l_artist[strlen(artist)];
    lower(strcpy(l_artist, artist));
    char l = l_artist[0];
    char a = 'a';
    struct song_node *art = find_artist(lib[l-a], l_artist);
    if (art) {
        return art;
    }
    return 0;
}

// Print the linked list of the letter specified
void print_letter(char letter) {
    printf("Printing the letter %c\n",letter);
    char l = tolower(letter);
    char a = 'a';
    struct song_node * let = lib[l-a];
    while(let){
        print_song(let);
        let = let -> next;
    }
}

// Given an artist, print their songs
void print_artist(char* artist) {
    printf("Printing %s\n",artist);
    struct song_node * art = search_artist(artist);
    unsigned char l_artist[strlen(artist)];
    lower(strcpy(l_artist, artist));
    while (art && strcmp(art->artist, l_artist) == 0) {
        print_song(art);
        art = art -> next;
    }
}

// Print the entire library
void print_lib() {
    int i = 0;
    char a = 'a';
    for (; i < 'z'-'a'; i++) {
        if (llist_len(lib[i]) > 0) {
            printf("%c songs\n\t", (a + i));
            print_list(lib[i]);
        }
    }
}

//the helper functions I tried to write but it wouldn't work
/*
   int count(){
   int count = 0;
   int i;
   for(i = 0; i < 'z' - 'a'; i++){
   if (llist_len(lib[i]) > 0)
   count++;
   }
   return count;
   }

   struct song_node* available(int size){
   struct song_node* letters[size];
   int i;
   for(i = 0; i < 'z'-'a'; i++){
   int count = 0;
   if (llist_len(lib[i]) > 0){
   letters[count] = lib[i];
   count++;
   }
   }
   return *letters;
   }*/

// Generate a specified number of songs, shuffled
// and print them
void shuffle(int num_songs) {
    printf("Generating %d random songs...\n",num_songs);
    srand(time(NULL));

    //count the number of letters in the lib that have songs
    int numlets = 0;
    int i;
    for(i = 0; i < 'z'-'a'; i++){
        if (llist_len(lib[i]) > 0)
            numlets++;
    }

    //make an array of all the letters in the lib that have songs
    struct song_node *availletters[numlets];
    int count = 0;
    for(i = 0; i < 'z'-'a'; i++){
        if (llist_len(lib[i]) > 0){
            availletters[count] = lib[i];
            count++;
        }
    }

    //pick random songs
    for(i = 0; i < num_songs; i++){
        //pick a random position for availletters
        int randpos = rand() % numlets;
        struct song_node *availsongs = availletters[randpos];
        //pick a random song from the list
        int randsongpos = rand() % llist_len(availsongs);
        int j;
        for(j = 0; j < randsongpos; j++){
            availsongs = availsongs -> next;
        }
        print_song(availsongs);
    }

}

// Delete a song from the library
void delete_song(char *title) {
    struct song_node *song = search_song(title);
    char *artist = song -> artist;
    remove_song(search_artist(artist),search_song(title));
}

// Clear the entire library
void clear_lib() {
    printf("Clearing library...\n");
    int i = 0;
    char a = 'a';
    for (; i < 'z'-'a'; i++) {
        if (llist_len(lib[i]) > 0) {
            free_list(lib[i]);
        }
    }
} 
