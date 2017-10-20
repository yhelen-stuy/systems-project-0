#include "linked_list.h"

// Take a mutable string and standardize it to lowercase
unsigned char * lower(char *str) {
    unsigned char *my_str = (unsigned char *) str;
    int i = 0;
    for (; my_str[i]; i++) {
        my_str[i] = tolower(my_str[i]);
    }
    return my_str;
}

void print_list(struct song_node *list) {
    printf("[ ");
    while (list) {
        printf("%s by %s , ", list->title, list->artist);
        list = list->next;
    }
    printf("]\n");
}

// Print a singular song if not null
void print_song(struct song_node *song){
  if (song) {
        printf("%s by %s\n", song->title, song->artist);
    }
}

// Insert a song at the front of the linked list
struct song_node * insert_front(struct song_node *list, char *title, char *artist) {
    struct song_node *p = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(p->title, title);
    strcpy(p->artist, artist);
    // Standardize the title and artists to be lower case
    lower(p->title);
    lower(p->artist);
    p->next = list;
    return p;
}

// Insert the song in order, primarily sorted by artist, secondarily by title
struct song_node * insert_sorted(struct song_node *list, char *title, char *artist) {
    unsigned char l_title[strlen(title)];
    lower(strcpy(l_title, title));
    unsigned char l_artist[strlen(artist)];
    lower(strcpy(l_artist, artist));
    //printf("%s, %s",ltitle,lartist);

    struct song_node *head = list;
    int nex = 1;
    struct song_node *prev = list;

    while (list && strcmp(list->artist, l_artist) <  0) {
        //print_list(list);
        prev = list;
        list = list->next;
        nex = 0;
    }

    while (list && (strcmp(list->title, l_title) < 0) && (strcmp(list->artist, l_artist) ==  0)) {
        //print_list(list);
        prev = list;
        list = list->next;
        nex = 0;
    }

    //if the new node is the new head, use insert_Front
    if(nex) {
        return insert_front(list,l_title,l_artist);
    }

    struct song_node *newnode = insert_front(list,l_title,l_artist);
    prev -> next = newnode;
    return head;
}

// Standardize title input
// and search through the linked list for the song
struct song_node * find_song(struct song_node *list, char *title) {
    unsigned char l_title[strlen(title)];
    lower(strcpy(l_title, title));
    while (list) {
        if (strcmp(list->title, l_title) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

// Same as above but the first instance of an artist
struct song_node * find_artist(struct song_node *list, char *artist) {
    unsigned char l_artist[strlen(artist)];
    lower(strcpy(l_artist, artist));
    while (list) {
       if (strcmp(list->artist, l_artist) == 0) {
           return list;
       }
       list = list->next;
    }
    return NULL;
}

// Return a random element of the list
struct song_node * random_element(struct song_node *list){
     int len = llist_len(list);
     int i;
     int randsongpos = rand() % len;
     for(i = 0; i < randsongpos; i++){
       list = list -> next;
     }
     return list;
}

// Go through the list and remove a song,
// freeing it in the process.
void remove_song(struct song_node *list, struct song_node *song) {
    while (list && list->next != song) {
        list = list->next;
    }
    if (list) {
        list->next = song->next;
        printf("..Removing %s by %s..\n", song->title, song->artist);
        free(song);
    }
}

// Free an entire list of songs
struct song_node * free_list(struct song_node *list) {
    struct song_node *start = list;
    struct song_node *temp;
    while (start) {
        temp = start->next;
        // Diagnostic print
        printf("...Freeing %s by %s...\n", start->title, start->artist);
        free(start);
        start = temp;
    }
    return NULL;
}

// A function to returned a size_t of the length of the list
// AKA an unsigned long
size_t llist_len(struct song_node *list) {
    size_t len = 0;
    while (list) {
        len++;
        list = list->next;
    }
    return len;
}
