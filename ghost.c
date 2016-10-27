#include "ghost.h"
#include "parameter.h"
#include "surface.h"

extern int point[WIN_COLS][WIN_LINES];
extern int x_1;
extern int y_1;
extern int x_2;
extern int y_2;
extern int d_1;
extern int d_2;
extern int temp_1;
extern int temp_2;
extern int life;

void Cutlife();

void Moveghost()
{
    point[x_1][y_1] = temp_1;
    point[x_2][y_2] = temp_2;
    
    if(d_1 == 1){
        if(point[x_1+1][y_1+1] != 1){
            x_1++;
            y_1++;
            if(point[x_1][y_1] == 4)
                Cutlife();
        }else{
            if((point[x_1+1][y_1] == 1 && point[x_1][y_1+1] == 1) ||
               (point[x_1+1][y_1] == 0 && point[x_1][y_1+1] == 0)){
                d_1 = 3;
            }else if(point[x_1+1][y_1] == 1 && point[x_1][y_1+1] == 0)
                d_1 = 2;
            else
                d_1 = 4;
        }
    }else if(d_1 == 2){
        if(point[x_1-1][y_1+1] != 1){
            x_1--;
            y_1++;
            if(point[x_1][y_1] == 4)
                Cutlife();
        }else{
            if((point[x_1-1][y_1] == 1 && point[x_1][y_1+1] == 1) ||
               (point[x_1-1][y_1] == 0 && point[x_1][y_1+1] == 0)){
                d_1 = 4;
            }else if(point[x_1-1][y_1] == 1 && point[x_1][y_1+1] == 0)
                d_1 = 1;
            else
                d_1 = 3;
        }
    }else if(d_1 == 3){
        if(point[x_1-1][y_1-1] != 1){
            x_1--;
            y_1--;
            if(point[x_1][y_1] == 4)
                Cutlife();
        }else{
            if((point[x_1-1][y_1] == 1 && point[x_1][y_1-1] == 1) ||
               (point[x_1-1][y_1] == 0 && point[x_1][y_1-1] == 0)){
                d_1 = 1;
            }else if(point[x_1-1][y_1] == 1 && point[x_1][y_1-1] == 0)
                d_1 = 4;
            else
                d_1 = 2;   
        }
    }else{
        if(point[x_1+1][y_1-1] != 1){
            x_1++;
            y_1--;
            if(point[x_1][y_1] == 4)
                Cutlife();
        }else{
            if((point[x_1+1][y_1] == 1 && point[x_1][y_1-1] == 1) ||
               (point[x_1+1][y_1] == 0 && point[x_1][y_1-1] == 0)){
                d_1 = 2;
            }else if(point[x_1+1][y_1] == 1 && point[x_1][y_1-1] == 0)
                d_1 = 3;
            else
                d_1 = 1;  
        }
    }

    if(d_2 == 1){
        if(point[x_2+1][y_2+1] != 1){
            x_2++;
            y_2++;
            if(point[x_2][y_2] == 4)
                Cutlife();
        }else{
            if((point[x_2+1][y_2] == 1 && point[x_2][y_2+1] == 1) ||
               (point[x_2+1][y_2] == 0 && point[x_2][y_2+1] == 0)){
                d_2 = 3;
            }else if(point[x_2+1][y_2] == 1 && point[x_2][y_2+1] == 0)
                d_2 = 2;
            else
                d_2 = 4;
        }
    }else if(d_2 == 2){
        if(point[x_2-1][y_2+1] != 1){
            x_2--;
            y_2++;
            if(point[x_2][y_2] == 4)
                Cutlife();
        }else{
            if((point[x_2-1][y_2] == 1 && point[x_2][y_2+1] == 1) ||
               (point[x_2-1][y_2] == 0 && point[x_2][y_2+1] == 0)){
                d_2 = 4;
            }else if(point[x_2-1][y_2] == 1 && point[x_2][y_2+1] == 0)
                d_2 = 1;
            else
                d_2 = 3;
        }
    }else if(d_2 == 3){
        if(point[x_2-1][y_2-1] != 1){
            x_2--;
            y_2--;
            if(point[x_2][y_2] == 4)
                Cutlife();
        }else{
            if((point[x_2-1][y_2] == 1 && point[x_2][y_2-1] == 1) ||
               (point[x_2-1][y_2] == 0 && point[x_2][y_2-1] == 0)){
                d_2 = 1;
            }else if(point[x_2-1][y_2] == 1 && point[x_2][y_2-1] == 0)
                d_2 = 4;
            else
                d_2 = 2;   
        }
    }else{
        if(point[x_2+1][y_2-1] != 1){
            x_2++;
            y_2--;
            if(point[x_2][y_2] == 4)
                Cutlife();
        }else{
            if((point[x_2+1][y_2] == 1 && point[x_2][y_2-1] == 1) ||
               (point[x_2+1][y_2] == 0 && point[x_2][y_2-1] == 0)){
                d_2 = 2;
            }else if(point[x_2+1][y_2] == 1 && point[x_2][y_2-1] == 0)
                d_2 = 3;
            else
                d_2 = 1;  
        }
    }

    temp_1 = point[x_1][y_1];
    temp_2 = point[x_2][y_2];
    point[x_1][y_1] = 3;
    point[x_2][y_2] = 3;
    ShowSurface();
}

void Cutlife()
{
    int i,j;    
    for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            if(point[i][j] == 4)
                point[i][j] = 0;
        }
    point[elfpoint_x][elfpoint_y] = elftemp;
    elftemp = 1;
    elfpoint_x = elfpoint_y = 0;
    point[elfpoint_x][elfpoint_y] = 2;
    life--;
    if(life == 2)
        Print("You has 2 life");
    if(life == 1)
        Print("You has 1 life");
    if(life == 0)
    Print("Your Shame");
    Resetp();
    ShowSurface();
}
