#include "move.h"
#include "parameter.h"
#include "surface.h"
#include <curses.h>

#define L (WIN_COLS * WIN_LINES)

extern int point[WIN_COLS][WIN_LINES];
extern int elfpoint_x;
extern int elfpoint_y;
extern int elftemp;
extern int direct;

int temp = -1;
int p[L][2] = {0};

void Resetp()
{
    int i;
    for(i = 0 ; i != L; i++)
        p[i][0] = p[i][1] = 0;
}

void Searchp(){
    int length;
    int i = 0;
    int x,y;
    int a,b;  //random point
    Resetp();
    //search new path
    for(x = 0 ; x != WIN_COLS; x++)
        for(y = 0; y != WIN_LINES; y++){
            if(point[x][y] == 4){
                p[i][0] = x;
                p[i][1] = y;
                i++;
            }
        }
    length = i;
/*    //search a random point
    for(i = 0; ;i++){
        x = p[i][0];
        y = p[i][1];
        if(point[++x][y] == 0){
            a = x;
            b = y;
            break;
        }else if(point[--x][++y] == 0){
            a = x;
            b = y;
            break;
        }else if(point[--x][--y] == 0){
            a = x;
            b = y;
            break;
        }else if(point[++x][--y] == 0){ 
            a = x;
            b = y;
            break;
        }else
            continue;
            }*/

    //cover path
    for(i = 0; i != length; i++){
        point[(p[i][0])][(p[i][1])] = 1;
    }
    point[(p[i][0])][(p[i][1])] = 1;
}

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
        if((elftemp == 1 || elftemp == 4) && temp == 4){
            Searchp();
        }
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
        if((elftemp == 1 || elftemp == 4) && temp == 4){
            Searchp();
        }
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
        if((elftemp == 1 || elftemp == 4) && temp == 4){
            Searchp();
        }
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
        if((elftemp == 1 || elftemp == 4) && temp == 4){
            Searchp();
        }
        point[elfpoint_x][elfpoint_y] = 2;
        ShowSurface();
    }
    direct = 1;
}
