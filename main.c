#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "music_lib.h"

int main() {
    srand(time(NULL));

    printf("\n====================================\n");
    printf("\n        TESTING LINKED LIST         \n");
    printf("\n====================================\n");
  
    printf("\nTesting insert_sorted\n");
    struct song_node *head = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(head->artist, "camilla cabillo");
    strcpy(head->title, "havana");
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

    printf("\n====================================\n");
    printf("\nTesting find_song\n");
    printf("Finding Havana by Camilla Cabillo\n\t");
    print_list(find_song(head, "Havana"));
    printf("\n");

    printf("Finding song not in list (\"test\")\n\t");
    print_list(find_song(head, "test"));
    printf("\n");

    printf("\n====================================\n");
    printf("\nTesting find_artist\n");
    printf("Finding Camilla Cabillo\n\t");
    print_list(find_artist(head, "Camilla Cabillo"));
    printf("\n");

    printf("Finding Ed Sheeran\n\t");
    print_list(find_artist(head, "Ed Sheeran"));
    printf("\n");

    printf("Finding artist not in list (\"test\")\n\t");
    print_list(find_artist(head, "test"));
    printf("\n");


    printf("\n====================================\n");
    printf("\nTesting random_element\n");
    print_song(random_element(head));
    print_song(random_element(head));
    print_song(random_element(head));
    printf("\n");

    printf("\n====================================\n");
    printf("\nTesting remove_song\n");
    remove_song(head, find_song(head, "Havana"));
    printf("After removal: \n\t");
    print_list(head);
    printf("\n");

    printf("\n====================================\n");
    printf("\nTesting free_list\n");
    free_list(head);
    

    printf("\n====================================\n");
    printf("\n       TESTING MUSIC LIBRARY        \n");
    printf("\n====================================\n");
    add_song("Symphony No. 5", "Beethoven");
    add_song("Focus", "Ariana Grande");
    add_song("Side to Side", "Ariana Grande");
    add_song("Shape of You", "Ed Sheeran");
    add_song("Galway Girl", "Ed Sheeran");
    add_song("New Rules", "Dua Lipa");
    add_song("Perfect", "Ed Sheeran");
    add_song("Problem", "Ariana Grande");
    add_song("Scars To Your Beautiful", "Alessia Cara");
    add_song("Heart Attack", "Demi Lovato");
    add_song("Set Fire to the Rain", "Adele");
    add_song("Wild Things","Alessia Cara");

    printf("\nTesting print_lib\n");
    print_lib();

    printf("\n====================================\n");
    printf("\nTesting find_song\n");

    char song[] = "Symphony No. 5";
    printf("Searching for %s\n",song);
    print_song(search_song(song));

    printf("\n====================================\n");
    printf("\nTesting find_artist\n");

    char artist[] = "Alessia Cara";
    printf("Searching for %s\n",artist);
    print_list(search_artist(artist));
    printf("\n");

    char artis[] = "Ariana Grande";
    printf("Searching for %s\n",artis);
    print_list(search_artist(artis));
    printf("\n");

    char arti[] = "test";
    printf("Searching for artist not in library %s\n",arti);
    print_list(search_artist(arti));

    printf("\n====================================\n");
    printf("\nTesting print_letter\n");
    print_letter('E');
    print_letter('B');

    printf("\n====================================\n");
    printf("\nTesting print_artist\n");
    print_artist("Ariana Grande");
    printf("\n");
    print_artist("Ed Sheeran");
    printf("\n");
    print_artist("Alessia Cara");
    printf("\n");
    print_artist("test");
    

    printf("\n====================================\n");
    printf("\nTesting delete_song\n");
    printf("Deleting Focus\n");
    delete_song("Focus");
    print_lib();
    printf("\n");
    delete_song("Perfect");
    print_lib();

    printf("\n====================================\n");
    printf("\nTesting shuffle\n");
    shuffle(3);
    printf("\n====================================\n");
    printf("\n");
    clear_lib();


    return 0;
}
