#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "music_lib.h"

int main() {
    printf("===TESTING LINKED LIST===\n");
    printf("***ADDING SONGS***\n");
    struct song_node *head = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(head->artist, "Camilla Cabillo");
    strcpy(head->title, "Havana");
    //head->next = (struct song_node *)malloc(sizeof(struct song_node));
    /* head = insert_front(head, "Galway Girl", "Ed Sheeran"); */
    /* head = insert_front(head, "Shape of You", "Ed Sheeran"); */
    /* head = insert_front(head, "New Rules", "Dua Lipa"); */
    /* head = insert_front(head, "Perfect", "Ed Sheeran"); */
    head = insert_sorted(head, "Side to Side", "Ariana Grande");
    head = insert_sorted(head, "Shape of You", "Ed Sheeran");
    head = insert_sorted(head, "Focus", "Ariana Grande");
    head = insert_sorted(head, "Galway Girl", "Ed Sheeran"); 
    head = insert_sorted(head, "New Rules", "Dua Lipa");
    head = insert_sorted(head, "Perfect", "Ed Sheeran"); 
    head = insert_sorted(head, "Problem", "Ariana Grande");
    printf("\t");
    print_list(head);
    printf("\n");

    printf("***FINDING***\n"); 
    printf("Finding Havana by Camilla Cabillo\n\t"); 
    print_list(find_song(head, "Havana")); 
    printf("\n");
    
    printf("Finding song not in list (\"test\")\n\t"); 
    print_list(find_song(head, "test")); 
    printf("\n");
    
    printf("Finding Camilla Cabillo\n\t"); 
    print_list(find_artist(head, "Camilla Cabillo")); 
    printf("\n");
    
    printf("Finding Ed Sheeran\n\t"); 
    print_list(find_artist(head, "Ed Sheeran")); 
    printf("\n");
    
    printf("***REMOVING***\n"); 
    remove_song(head, find_song(head, "Havana"));

    free_list(head);

    return 0;
}
