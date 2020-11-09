#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

struct song_node * add_to_lib (struct song_node ** lib, char * n, char *a);

void print_library (struct song_node ** lib);

void print_letter (struct song_node **lib, char a);

void find (struct song_node **lib, char * n, char * a);

void find_artist_lib(struct song_node** lib, char * a);

void remove_song(struct song_node** lib, char * n, char * a);

void remove_song(struct song_node** lib, char * n, char * a);

void clear_library(struct song_node **lib);

void print_artist(struct song_node** lib, char * a);

void shuffle(struct song_node** lib);

#endif