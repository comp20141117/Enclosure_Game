#include "surface.h"
#include "parameter.h"
#include <curses.h>
#include <unistd.h>

extern int point[WIN_COLS][WIN_LINES];
extern int elfpoint_x;
extern int elfpoint_x;
extern int elftemp;
extern int direct;
extern int x_1;
extern int y_1;
extern int x_2;
extern int y_2;
extern int d_1;
extern int d_2;
extern int life;

void InitSurface()
{
    int i,j;
    for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            if(i == 0 || i == WIN_COLS-1 || j == 0 || j == WIN_LINES-1)                point[i][j] = 1; //blue
            else
                point[i][j] = 0; //black
        }
    elfpoint_x = 0;
    elfpoint_y = 0;
    elftemp = 1;
    direct = 0;
    point[elfpoint_x][elfpoint_y] = 2; //red
    x_1 = 30;
    y_1 = 10;
    x_2 = 60;
    y_2 = 20;
    point[x_1][y_1] = 3;
    point[x_2][y_2] = 3;
    d_1 = 4;
    d_2 = 2;
    temp_1 = 0;
    temp_2 = 0;
    life = 3;
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

int WinSurface()
{
    int count = 0;
    int i,j;
    for(i = 0; i < WIN_LINES; i++)
        for(j = 0; j < WIN_COLS; j++)
            if(point[i][j] == 1)
                count++;
    if(count > (L * 0.8))
        return 1;
    else
        return 0;
}
