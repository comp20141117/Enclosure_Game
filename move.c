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
extern int p[L][2];
extern int p_x;

int temp = -1;

void Resetp()
{
    int i;
    for(i = 0 ; i != L; i++)
        p[i][0] = p[i][1] = 0;
    p_x = 0;
}

void Searchp()
{
    int length = p_x;
    int i = 0;
    int a,b;
    int x = p[0][0];
    int y = p[0][1];
    int m = p[length-1][0];
    int n = p[length-1][1];
    
    for(i = 0; i < length; i++){
         a = p[i][0];
         b = p[i][1];
         if(y == n){
             if(y < WIN_LINES/2){
                 while(b > 0){
                     point[a][b] = 1;
                     b--;
                 }
             }else{
                 while(b < WIN_LINES){
                     point[a][b] = 1;
                     b++;
                 }
             }
         }else if(x == m){
             if(x < WIN_COLS/2){
                 while(a > 0){
                     point[a][b] = 1;
                     a--;
                 }
             }else{
                 while(a < WIN_COLS){
                     point[a][b] = 1;
                     a++;
                 }
             }
         }else{
             if(y + n < WIN_LINES){
                 while(b > 0){
                     point[a][b] = 1;
                     b--;
                 }
             }else if(y + n > WIN_LINES){
                 while(b < WIN_LINES){
                     point[a][b] = 1;
                     b++;
                 }
             }else{
                 if(x + m < WIN_COLS){
                     while(a > 0){
                         point[a][b] = 1;
                         a--;
                     }
                 }else{
                     while(a < WIN_COLS){
                         point[a][b] = 1;
                         a++;
                     }
                 }
             }
         }
    }
    
    Resetp();
}

void MoveRight()
{
    if(elfpoint_x < WIN_COLS-1){
        if(direct == 3 || elftemp == 4){
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
