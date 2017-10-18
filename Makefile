all:
	gcc -o music_lib -g main.c linked_list.c

run: all
	./music_lib

test: all
	valgrind --leak-check=yes ./music_lib

clean:
	rm music_lib
