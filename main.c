#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "surface.h"

int point[WIN_COLS][WIN_LINES];

int InitColor();

int main()
{
    int i,j;

    initscr();
    if(InitColor() != 0){
        endwin();
        exit(1);
    }

    InitSurface();
    ShowSurface();
    refresh();
    sleep(5);
    endwin();
    exit(0);
}

int InitColor()
{
    if(!has_colors()){
        fprintf(stderr,"Error - no color");
        return 1;
    }
    if(start_color() != OK){
        fprintf(stderr,"Error - initialize color fail");
        return 1;
    }
    return 0;
}
