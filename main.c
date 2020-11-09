#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_song.h"
#include "song_library.h"

int main() {
  srand(time(NULL));
  struct song_node *playlist;
  struct song_node *song;
  playlist = NULL;
  playlist = insert_front(playlist,"positions","ariana grande");
  playlist = insert_order(playlist,"34+35","ariana grande");
  playlist = insert_order(playlist, "dynamite", "bts");
  playlist = insert_order(playlist, "blinding lights", "the weeknd");
  playlist = insert_order(playlist, "watermelon sugar", "harry styles");
  playlist = insert_order(playlist, "golden", "harry styles");
  playlist = insert_order(playlist, "before you go", "lewis capaldi");
  playlist = insert_order(playlist, "reel it in", "amine");
  printf("LINKED LIST TESTS\n====================================\n");
  printf("\nTesting print list:\n ");
  print_list(playlist);
  printf("\n====================================\n");
  printf("\nTesting print_node:\n ");
  print_node(playlist);
  printf("\n====================================\n");
  printf("\nTesting find_node:\nlooking for [the weeknd: blinding lights]\n");
  struct song_node *temp = find_node(playlist,"blinding lights", "the weeknd");
  if (!temp)
    printf(" node not found\n");
  else {
    printf(" node found! ");
    print_node(temp);
  }
  printf("\nlooking for [the weeknd: starboy]\n");
  temp = find_node(playlist,"starboy", "the weeknd");
  if (!temp)
    printf(" node not found\n");
  else {
    printf(" node found! ");
    print_node(temp);
  }
  printf("====================================\n");

  printf("\nTesting songcmp (helper function):\n");
  printf("Comparing [the weeknd: blinding lights] to [lewis capaldi: before you go]\n ");
  printf("%d\n", songcmp("blinding lights", "the weeknd", "before you go","lewis capaldi"));

  printf("Comparing [ariana grande: 34+35] to [ariana grande: positions]\n ");
  printf("%d\n", songcmp("34+35", "ariana grande", "positions","ariana grande"));

  printf("Comparing [bts: dynamite] to [bts: dynamite]\n ");
  printf("%d\n", songcmp("dynamite", "bts", "dynamite","bts"));

  printf("Comparing [bts: dynamite] to [harry stles: watermelon sugar]\n ");
  printf("%d\n", songcmp("dynamite", "bts", "watermelon sugar","harry styles"));

  printf("\nTesting find_artist:\nlooking for [lewis capaldi]\n");
  temp = find_artist(playlist, "lewis capaldi");
  if (!temp) printf(" artist not found\n");
  else {
    printf(" artist found! ");
    print_list(temp);
  }
  printf("\nlooking for [bts]\n");
  temp = find_artist(playlist, "bts");
  if (!temp) printf(" artist not found\n");
  else {
    printf(" artist found! ");
    print_list(temp);
  }
  printf("\nlooking for [justin bieber]\n");
  temp = find_artist(playlist, "justin bieber");
  if (!temp) printf(" artist not found\n");
  else {
    printf(" artist found!\n");
    print_list(temp);
  }
  printf("====================================\n");
  printf("\nTesting random:\n");
  print_node(random_node(playlist));
  printf("\n");
  print_node(random_node(playlist));
  printf("\n");
  print_node(random_node(playlist));
  printf("\n");
  print_node(random_node(playlist));
  printf("\n====================================\n\nTesting remove_node:\nRemoving [ariana grande: 34+35]\n ");
  playlist = remove_node(playlist, "34+35", "ariana grande");
  print_list(playlist);
  printf("\nRemoving [harry styles: golden]\n ");
  playlist = remove_node(playlist, "golden", "harry styles");
  print_list(playlist);
  printf("\nRemoving [pink floyd: alive]\n ");
  if (!find_node(playlist,"alive", "pink floyd")) printf("pink floyd: alive not found\n");
  else{
    playlist = remove_node(playlist, "alive", "pink floyd");
  }
  print_list(playlist);
  printf("\n====================================\n\nTesting free_list\n");
  playlist = free_list(playlist);
  printf("\nlist after free_list\n");
  print_list(playlist);
  printf("\n\n====================================\n");
  printf("\nMUSIC LIBRARY TESTS\n\n====================================\n\n");

  struct song_node *library[27];
  int i;
  for (i = 0; i<27; i++){
    library[i] = NULL;
  }

  printf("Testing add_to_lib and print_library\n");
  add_to_lib(library,"positions","ariana grande");
  add_to_lib(library,"34+35","ariana grande");
  add_to_lib(library,"dynamite", "bts");
  add_to_lib(library,"blinding lights", "the weeknd");
  add_to_lib(library,"watermelon sugar", "harry styles");
  add_to_lib(library,"golden", "harry styles");
  add_to_lib(library,"before you go", "lewis capaldi");
  add_to_lib(library, "reel it in", "amine");

  print_library(library);
  printf("====================================\n");

  printf("\nTesting print_letter\n");
  print_letter(library, 'h');
  print_letter(library, 'a');
  printf("\n====================================\n\n");
  printf("Testing find:\n");
  find(library, "dynamite", "bts");
  find(library, "dna", "bts");
  printf("====================================\n");
  printf("\nTesting find_artist_lib:\n");
  find_artist_lib(library, "harry styles");
  find_artist_lib(library, "amine");
  printf("====================================\n");
  printf("\nTesting remove_song:\n");
  remove_song(library, "34+35", "ariana grande");
  print_library(library);

  printf("\n");
  remove_song(library, "golden", "harry styles");
  print_library(library);
  printf("\n====================================\n\nTesting clear_library:\n");
  clear_library(library);
  printf("\nLibrary after clear:\n");
  print_library(library);
  printf("====================================\n\nAdding songs to empty library\n");
  add_to_lib(library,"positions","ariana grande");
  add_to_lib(library,"34+35","ariana grande");
  add_to_lib(library, "reel it in", "amine");
  add_to_lib(library,"blinding lights", "the weeknd");
  add_to_lib(library, "caroline", "amine");
  print_library(library);
  printf("====================================\n\nTesting print_artist:\n");
  print_artist(library, "amine");
  print_artist(library, "the weeknd");
  printf("====================================\n\nTesting shuffle:\n");
  shuffle(library);
  shuffle(library);
  shuffle(library);
  shuffle(library);
  printf("====================================");

  //'a' == 97
  return 0;
}