all: main.o linked_song.o linked_song.h song_library.o song_library.h
	gcc -o program main.o linked_song.o song_library.o linked_song.h  song_library.h

main.o: main.c
	gcc -c main.c

linked_song.o: linked_song.c
	gcc -c linked_song.c

song_library.o: song_library.c
	gcc -c song_library.c

run:
	./program

clean:
	rm *.o