all:
	echo $$(resize -s 30 90)
	make exe

exe: main.o surface.o
	gcc -o exe main.o surface.o -lcurses

main.o: main.c surface.h
	gcc -c main.c

surface.o: surface.c surface.h
	gcc -c surface.c

.PHONY: clean
clean:
	rm *.o exe
