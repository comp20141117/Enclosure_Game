#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "surface.h"
#include "parameter.h"
#include "move.h"

int InitColor();

int main()
{
    int i,j;
    int key;
    initscr();
    if(InitColor() != 0){
        endwin();
        exit(1);
    }
    keypad(stdscr,TRUE);
    noecho();
    leaveok(stdscr,FALSE);

    InitSurface();
    ShowSurface();
    Print("press 'q' to quit");

    touchwin(stdscr);
    key = getch();
    while(key != ERR && key != 'q'){
        switch(key){
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_LEFT:
            MoveLeft();
            break;
        case KEY_UP:
            MoveUp();
            break;
        case KEY_DOWN:
            MoveDown();
            break;
        default:
            break;
        }
        key = getch();
    }
    
    refresh();
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
