#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_list(struct node *head) {
    printf("[ ");
    while(head->next) {
        printf("%d,", head->x);
        head = head->next;
    }
    printf("%d ]\n", head->x);
}

struct node * insert_front(struct node *head, int a) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->x = a;
    p->next = head;
    return p;
}

struct node * free_list(struct node *head) {
    struct node *start = head;
    struct node *temp;
    while(temp) {
        temp = start->next;
        free(start);
        start = temp;
    }
    return NULL;
}
