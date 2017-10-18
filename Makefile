all:
	gcc -o music_lib main.c linked_list.c

run: all
	./music_lib

clean:
	rm music_lib
