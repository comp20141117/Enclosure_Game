#include "surface.h"
#include <curses.h>
extern int point[WIN_COLS][WIN_LINES];

void InitSurface()
{
    int i,j;
    for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            if(i == 0 || i == WIN_COLS-1 || j == 0 || j == WIN_LINES-1)
                point[i][j] = 1; //blue
            else
                point[i][j] = 0; //grey
        }
}

void ShowSurface()
{
    int i,j;
    int grey;
    init_color(grey,119,136,153);
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(0,COLOR_WHITE,grey);
    for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            attrset(COLOR_PAIR(point[i][j]));
            mvprintw(j,i," ");
            refresh();
        }
}
