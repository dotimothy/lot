all: lot

lot: lot.c
	gcc lot.c -o lot -Wall -ansi -std=c99

clean:
	rm -rf lot
