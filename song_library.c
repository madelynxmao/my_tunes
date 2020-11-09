#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_song.h"

void add_to_lib (struct song_node ** lib, char * n, char *a){
    int letter = a[0]-97;
    if (!lib[letter]) lib[letter] = insert_front(lib[letter], n, a);
    else lib[letter] = insert_order(lib[letter], n, a);
}

void print_library (struct song_node ** lib){
  int i;
  for (i = 0; i < 27; i++){
    if (lib[i]){
      printf("%c list\n ", i+97);
      print_list(lib[i]);
      printf("\n");
    }
  }
}

void print_letter (struct song_node **lib, char a){
  int letter = a - 97;
  if (!lib[letter]) printf("there is no %c list", a);
  else{
    printf("%c list\n ", a);
    print_list(lib[letter]);
    printf("\n");
  }
}

void find (struct song_node **lib, char * n, char * a){
  printf("looking for [%s: %s]\n ",a,n);
  struct song_node *list = lib[a[0]-97];
  list = find_node(list, n, a);
  if(!list) printf("song not found\n");
  else {
    printf("song found! ");
    print_list(list);
    printf("\n");
  }
}

void find_artist_lib(struct song_node** lib, char * a){
  printf("looking for [%s]\n ", a);
  struct song_node * list = lib[a[0] - 97];
  list = find_artist(list,a);
  if(!list) printf("artist not found\n");
  else {
    printf("artist found! ");
    print_list(list);
    printf("\n");
  }
}

void remove_song(struct song_node** lib, char * n, char * a){
  printf("removing: [%s: %s]\n", a, n);
  int letter = a[0] - 97;
  lib[letter] = remove_node(lib[letter], n, a);
}

void clear_library(struct song_node **lib){
  int i;
  for (i = 0; i<27; i++){
    if (lib[i]){
      lib[i] = free_list(lib[i]);
    }
  }
}

void print_artist(struct song_node** lib, char * a){
  printf("printing [%s]\n", a);
  struct song_node* list = lib[a[0] -97];
  while (list){
    if (!strcmp(a, list->artist)){
      printf("[");
      print_node(list);
      printf("]\n");
    }
    list = list -> next;
  }
  printf("\n");
}

void shuffle(struct song_node** lib){
  int i, num_of_songs;
  num_of_songs = 0;
  for (int i = 0; i < 27; i++){
    if (lib[i]) {
      num_of_songs++;
      struct song_node* list = lib[i] -> next;
      while (list){
        num_of_songs++;
        list = list -> next;
      }
    }
  }

  int random_num = rand() % num_of_songs;
  int current = 0;
  int letter = 0;

  while (!lib[letter]){
    letter++;
  }
  struct song_node * list = lib[letter];

  while (current < random_num && letter < 28){
      list = list -> next;
      while (!list){
        letter++;
        list = lib[letter];
      }
      current++;
  }
  print_node(list);
  printf("\n");

}
