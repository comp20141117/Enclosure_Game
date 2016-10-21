all:
	echo $$(resize -s 30 90)
	make exe

exe: main.o surface.o move.o
	gcc -o exe main.o surface.o move.o -lcurses

main.o: main.c surface.h parameter.h
	gcc -c main.c

surface.o: surface.c surface.h parameter.h
	gcc -c surface.c

move.o: move.c move.h parameter.h
	gcc -c move.c

.PHONY: clean
clean:
	rm *.o exe *~
