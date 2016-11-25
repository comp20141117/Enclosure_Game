#include "move.h"
#include "parameter.h"
#include "surface.h"
#include <curses.h>
#include <unistd.h>

extern int point[WIN_COLS][WIN_LINES];
extern int elfpoint_x;
extern int elfpoint_y;
extern int elftemp;
extern int direct;

// p(= path ?) is the path list
// [0] => X coordinate
// [1] => Y coordinate
// p_x: the index of new item
//
extern int p[L][2];
extern int p_x;

int fill[L][2];
int f = 0;
int temp = -1;

void Fill(int i, int j);

// clear the path
// called when the path is broken by enemies
void Resetp()
{
    int i;
    for(i = 0 ; i != L; i++)
        p[i][0] = p[i][1] = 0;
    p_x = 0;
}

void Resetfill()
{
    int i;
    for(i = 0; i < L; i++)
        fill[i][0] = fill[i][1] = 0;
    f = 0;
}

int isfill(int i, int j)
{
    int k;
    if(f == 0)
        return 0;
    for(k = 0; k < f; k++){
        if(fill[k][0] == i && fill[k][1] == j)
            return 1;
    }
    return 0;
}

void Searchp()
{
    int x,y;
    int i,j;
    int length = p_x;
    int num = 0;
    Resetfill();
    for(i = 0; i < WIN_COLS; i++)
        for(j = 0; j < LINES; j++)
            if(point[i][j] == 0)
                num++;
        
    for(i = 0; i < WIN_COLS; i++)
        for(j = 0; j < LINES; j++)
            if(point[i][j] == 0)
                x = i, y = j;

    Fill(x,y);
    if(f == num)
        Resetfill();
    else if(f > num/2){
        for(i = 0; i < WIN_COLS; i++)
            for(j = 0; j < WIN_LINES; j++)
                if(point[i][j] == 0 && !isfill(i,j))
                    x = i,y = j;
        Resetfill();
        Fill(x,y);
    }

    for(i = 0; i < f; i++){
        point[fill[i][0]][fill[i][1]] = 1;
        }

    
    for(i = 0; i < length; i++)
        point[p[i][0]][p[i][1]] = 1;
    Resetp();
}

void Fill(int i, int j)
{
    if(point[i][j] == 0 && !isfill(i,j)){
        fill[f][0] = i;
        fill[f][1] = j;
        f++;
        Fill(i,j+1);
        Fill(i+1,j);
        Fill(i-1,j);
        Fill(i,j+1);
        Fill(i+1,j+1);
        Fill(i+1,j-1);
        Fill(i-1,j+1);
        Fill(i-1,j-1);
    }
}

void MoveRight()
{
    if(elfpoint_x < WIN_COLS-1){
        // point=4 cyan
        // point=1 blue
        
        // try to move in reversed direction(why this cause the path reset?)
        // or
        // 
        if(direct == 3 || elftemp == 4){
            point[elfpoint_x][elfpoint_y] = 1;
            Resetp();
        }
        else if(elftemp == 1)
            // last is blue
            // (why don't use 1 ?)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else{
            // draw line, then add the new point to path list
            point[elfpoint_x][elfpoint_y] = 4;
            p[p_x][0] = elfpoint_x;
            p[p_x][1] = elfpoint_y;
            p_x++;
        }
        // temp: the block in old location
        // elftemp: the block in new location
        temp = point[elfpoint_x][elfpoint_y];
        elfpoint_x++;
        elftemp = point[elfpoint_x][elfpoint_y];
        // if the new point is blue or ?cyan and
        //    the old point is cyan
        // try fill the region
        if((elftemp == 1 || elftemp == 4) && temp == 4){
            Searchp();
        }
        point[elfpoint_x][elfpoint_y] = 2;

        // FIXME: shouldn't update screen here
        ShowSurface();
    }
    direct = 4;
}

void MoveLeft()
{
    if(elfpoint_x > 0){
        if(direct == 4 || elftemp == 4){
            point[elfpoint_x][elfpoint_y] = 1;
            Resetp();
        }
        else if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else{
            point[elfpoint_x][elfpoint_y] = 4;
            p[p_x][0] = elfpoint_x;
            p[p_x][1] = elfpoint_y;
            p_x++;
        }
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
        if(direct == 1 || elftemp == 4){
            point[elfpoint_x][elfpoint_y] = 1;
            Resetp();
        }
        else  if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else{
            point[elfpoint_x][elfpoint_y] = 4;
            p[p_x][0] = elfpoint_x;
            p[p_x][1] = elfpoint_y;
            p_x++;
        }
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
        if(direct == 2 || elftemp == 4){
            point[elfpoint_x][elfpoint_y] = 1;
            Resetp();
        }
        else if(elftemp == 1)
            point[elfpoint_x][elfpoint_y] = elftemp;
        else{
            point[elfpoint_x][elfpoint_y] = 4;
            p[p_x][0] = elfpoint_x;
            p[p_x][1] = elfpoint_y;
            p_x++;
        }
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

