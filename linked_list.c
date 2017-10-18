#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void print_list(struct song_node *list) {
    printf("[ ");
    while (list) {
        printf("%s by %s , ", list->title, list->artist);
        list = list->next;
    }
    printf("]\n");
}

struct song_node * insert_front(struct song_node *list, char *title, char *artist) {
    struct song_node *p = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(p->title, title);
    strcpy(p->artist, artist);
    p->next = list;
    return p;
}

// TODO - SEGFAULTS
struct song_node * insert_sorted(struct song_node *list, char *title, char *artist) {
    struct song_node *head = list;
    while (list && strcmp(list->artist, artist) <  0) {
        print_list(list);
        list = list->next;
    }
    while (list && (strcmp(list->title, title) < 0) && (strcmp(list->artist, artist) ==  0)) {
        print_list(list);
        list = list->next;
    }
    insert_front(list,title,artist);
    return head;
}

struct song_node * find_song(struct song_node *list, char *title) {
    while (list) {
        if (strcmp(list->title, title) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

struct song_node * find_artist(struct song_node *list, char *artist) {
    while (list) {
        if (strcmp(list->artist, artist) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

// look over
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
