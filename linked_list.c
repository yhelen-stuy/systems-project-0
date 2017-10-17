#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void print_list(struct song_node *list) {
    printf("[ ");
    while (list->next) {
        printf("%d,", list->x);
        list = head->next;
    }
    printf("%d ]\n", list->x);
}

struct song_node * insert_front(struct song_node *list, int a) {
    struct song_node *p = (struct song_node *)malloc(sizeof(struct song_node));
    p->x = a;
    p->next = list;
    return p;
}

struct song_node * insert_sorted(struct song_node *list, char *title, char *artist) {

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

struct song_node * find_artist(struct song_node *list, char *title) {
    while (list) {
        if (strcmp(list->artist, artist) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

// look over
struct song_node * remove(struct song_node *list, struct song_node *song) {
    while (list && list->next != song) {
        list = list->next;
    }
    if (list) {
        list->next = song->next;
        free(song);
    }
}

struct song_node * free_list(struct song_node *list) {
    struct song_node *start = list;
    struct song_node *temp;
    while (temp) {
        temp = start->next;
        free(start);
        start = temp;
    }
    return NULL;
}
