all:
	echo $$(resize -s 30 90)
	make exe

exe: main.o surface.o move.o ghost.o
	gcc -o exe main.o surface.o move.o ghost.o -lcurses

main.o: main.c surface.h parameter.h move.h ghost.h
	gcc -c main.c

surface.o: surface.c surface.h parameter.h
	gcc -c surface.c

move.o: move.c move.h parameter.h
	gcc -c move.c

ghost.o: ghost.c ghost.h parameter.h
	gcc -c ghost.c

.PHONY: clean
clean:
	rm *.o exe *~
