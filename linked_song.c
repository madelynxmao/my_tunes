#include "linked_song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//to create a new song_node
struct song_node *new_song(char *n, char *a){
  struct song_node *ns;
  ns = malloc(sizeof(struct song_node));
  strncpy(ns->name, n, sizeof(ns->name) - 1);
  strncpy(ns->artist, a, sizeof(ns->artist) - 1);

  return ns;
}

//insert nodes at the front
struct song_node * insert_front(struct song_node *p, char *name, char *artist){
  struct song_node *to_add = new_song(name, artist);
  to_add->next = p;
  return to_add;
}

//compare songs
int songcmp (char * n1, char * a1, char *n2, char *a2){
  if (strcmp(a1,a2)<0) return -1;
  else if (strcmp(a1,a2)>0) return 1;
  else {
    if (strcmp(n1,n2)<0) return -1;
    else if (strcmp(n1,n2)>0) return 1;
  }
  return 0;


}
//insert nodes in order alphabetical by Artist then by Song
struct song_node * insert_order(struct song_node *p, char *n, char*a){

  if (strcmp(a,p->artist)<0 || !p){
    return insert_front(p, n, a);
  }
  if ((!strcmp(a,p->artist)) && strcmp(n,p->name)<0) return insert_front(p, n, a);

  struct song_node *ns = new_song(n,a);

  struct song_node *current = p->next;
  struct song_node *previous = p;

  if (current == 0){
    ns->next = NULL;
    previous->next = ns;
    return p;
  }
  else{
    struct song_node *old = previous;
    struct song_node *temp = old->next;
    old->next = ns;
    ns->next= temp;
  }

  return p;

}



//print the entire list
void print_node(struct song_node *p){
  if (!p) printf("no song");
  else printf("%s: %s", p->artist, p->name);
}

void print_list(struct song_node *p){
  if (!p) printf("no songs");
  while (p){
    print_node(p);
    printf(" | ");
    p = p->next;
  }
}

//find and return a pointer to a node based on artist and song name
struct song_node * find_node(struct song_node *p, char *n, char *a){
  while (p){
    if (!strcmp(p->name, n) && !strcmp(p->artist,a)){return p;}
    p = p->next;
  }
  return NULL;
}
//find and return a pointer to the first song of an artist based on artist name
struct song_node *find_artist (struct song_node *p, char *a){
  while (p){
    if (!strcmp(p->artist,a)) return p;
    p = p->next;
  }
  return NULL;
}
//Return a pointer to random element in the list.

struct song_node *random_node (struct song_node *p){
  int num_of_songs = 0;
  struct song_node* list = p;
  while(list){
    num_of_songs++;
    list = list ->next;
  }

  int random_num = rand() % num_of_songs;
  int i;
  for (i = 0; i < random_num; i++){
    p = p->next;
  }
  return p;
}

//remove a single specified node from the list
struct song_node *remove_node (struct song_node *p, char *n, char*a){
  if (!strcmp(p->name,n) && !strcmp(p->artist,a)) return p->next;

  struct song_node *current = p->next;
  struct song_node *previous = p;

  while (current){
    if (!strcmp(current->name,n) && !strcmp(current->artist,a)){
        previous->next = current->next;
        break;
    }
    previous = current;
    current = current->next;
  }

  return p;
}
//free the entire list
struct song_node* free_list(struct song_node *p){
	while(p) {
		struct song_node *next_song = p->next;
    printf("Freeing node: %s - %s\n", p->artist,p->name);
		free(p);
		p = next_song;
	}
  return NULL;
}