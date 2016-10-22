#include "move.h"
#include "parameter.h"
#include "surface.h"
#include <curses.h>

extern int point[WIN_COLS][WIN_LINES];
extern int elfpoint_x;
extern int elfpoint_y;
extern int elftemp;
extern int direct;

int temp = -1;

void MoveRight()
{
    if(elfpoint_x < WIN_COLS-1){
        if(direct == 3 || elftemp == 4)
            point[elfpoint_x][elfpoint_y] = 1;
        else if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else
            point[elfpoint_x][elfpoint_y] = 4;
        temp = point[elfpoint_x][elfpoint_y];
        elfpoint_x++;
        elftemp = point[elfpoint_x][elfpoint_y];
        if((elftemp == 1 || elftemp == 4) && temp == 4)
            Print("Yes");
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
    direct = 4;
}

void MoveLeft()
{
    if(elfpoint_x > 0){
        if(direct == 4 || elftemp == 4)
            point[elfpoint_x][elfpoint_y] = 1;
        else if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else
            point[elfpoint_x][elfpoint_y] = 4;
        temp = point[elfpoint_x][elfpoint_y];
        elfpoint_x--;
        elftemp = point[elfpoint_x][elfpoint_y];
        if((elftemp == 1 || elftemp == 4) && temp == 4)
            Print("Yes");
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
    direct = 3;
}

void MoveDown(){
    if(elfpoint_y < WIN_LINES-1){
        if(direct == 1 || elftemp == 4)
            point[elfpoint_x][elfpoint_y] = 1;
        else  if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else
            point[elfpoint_x][elfpoint_y] = 4;
        temp = point[elfpoint_x][elfpoint_y];
        elfpoint_y++;
        elftemp = point[elfpoint_x][elfpoint_y];
        if((elftemp == 1 || elftemp == 4) && temp == 4)
            Print("Yes");
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
    direct = 2;
}

void MoveUp()
{
    if(elfpoint_y > 0)
    {
        if(direct == 2 || elftemp == 4)
            point[elfpoint_x][elfpoint_y] = 1;
        else if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else
            point[elfpoint_x][elfpoint_y] = 4;
        temp = point[elfpoint_x][elfpoint_y];
        elfpoint_y--;
        elftemp = point[elfpoint_x][elfpoint_y];
        if((elftemp == 1 || elftemp == 4) && temp == 4)
            Print("Yes");
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
    direct = 1;
}
