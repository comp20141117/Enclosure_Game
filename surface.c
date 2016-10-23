#include "surface.h"
#include "parameter.h"
#include <curses.h>
#include <unistd.h>

extern int point[WIN_COLS][WIN_LINES];
extern int elfpoint_x;
extern int elfpoint_x;
extern int elftemp;
extern int direct;

void InitSurface()
{
    int i,j;
    for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            if(i == 0 || i == WIN_COLS-1 || j == 0 || j == WIN_LINES-1)                point[i][j] = 1; //blue
            else
                point[i][j] = 0; //grey
        }
    elfpoint_x = 0;
    elfpoint_y = 0;
    elftemp = 1;
    direct = 0;
    point[elfpoint_x][elfpoint_y] = 2; //red
}

void ShowSurface()
{
    int i,j;
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(0,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_WHITE,COLOR_RED);
    init_pair(3,COLOR_WHITE,COLOR_YELLOW);
    init_pair(4,COLOR_WHITE,COLOR_CYAN);

     for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            attrset(COLOR_PAIR(point[i][j]));
            mvprintw(j,i," ");
        }
    refresh();
}

void Print(char *str)
{
    WINDOW *new_ptr;
    new_ptr = newwin(9,30,10,29);
    box(new_ptr,'|','-');
    mvwprintw(new_ptr,4,5,str);
    touchwin(new_ptr);
    wrefresh(new_ptr);
    sleep(2);
    delwin(new_ptr);
}
