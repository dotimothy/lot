# lot.c Makefile
# Author: Timothy Do

all: lot lotMore

lot: lot.c
	gcc lot.c -o lot -Wall -ansi -std=c99

lotMore: lot.c
	gcc lot.c -o lotMore -Wall -ansi -std=c99 -Dmore

clean:
	rm -rf lot lotMore
