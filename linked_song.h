#ifndef LINKED_SONG_H
#define LINKED_SONG_H

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node *new_song(char *name, char *artist);

struct song_node * insert_front(struct song_node *p, char *name, char *artist);

int songcmp (char * n1, char * a1, char *n2, char *a2);

struct song_node * insert_order(struct song_node *p, char *n, char*a);

void print_node(struct song_node *p);

void print_list(struct song_node *p);

struct song_node * find_node(struct song_node *p, char *n, char *a);

struct song_node *find_artist (struct song_node *p, char *a);

struct song_node *random_node (struct song_node *p);

struct song_node *remove_node (struct song_node *p, char *n, char*a);

struct song_node* free_list(struct song_node *p);

#endif
