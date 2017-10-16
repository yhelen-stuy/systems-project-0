all:
	gcc -o music_lib main.c

run: all
	./music_lib

clean:
	rm music_lib
