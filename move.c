#include "move.h"
#include "parameter.h"
#include "surface.h"
#include <curses.h>

extern int point[WIN_COLS][WIN_LINES];
extern int elfpoint_x;
extern int elfpoint_y;
extern int elftemp;

void MoveRight(){
    if(elfpoint_x < WIN_COLS-1){
        point[elfpoint_x][elfpoint_y] = elftemp;
        elfpoint_x++;
        elftemp = point[elfpoint_x][elfpoint_y];
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
}

void MoveLeft(){
    if(elfpoint_x > 0){
        point[elfpoint_x][elfpoint_y] = elftemp;
        elfpoint_x--;
        elftemp = point[elfpoint_x][elfpoint_y];
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
}

void MoveDown(){
    if(elfpoint_y < WIN_LINES-1){
        point[elfpoint_x][elfpoint_y] = elftemp;
        elfpoint_y++;
        elftemp = point[elfpoint_x][elfpoint_y];
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
}

void MoveUp(){
     if(elfpoint_y > 0){
        point[elfpoint_x][elfpoint_y] = elftemp;
        elfpoint_y--;
        elftemp = point[elfpoint_x][elfpoint_y];
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
     }
}
