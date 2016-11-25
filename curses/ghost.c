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

// Variables:
//   x_1, y_1, x_2, y_2: coordinates (why don't use struct?)
//   d_1, d_2: directions (why don't use enum?)
//                        (why not specify enemy speed using a vector?)
//     
//    3   4
//     \ /
//      +
//     / \
//    2   1
//    
//

// move the enemy...oh my god
// the algorithm to do collision detection is good,
// but not the same with the repeation.
void Moveghost()
{
    // load last here is
    // to erase the block in old location
    point[x_1][y_1] = temp_1;
    point[x_2][y_2] = temp_2;
    
    if(d_1 == 1){
        if(point[x_1+1][y_1+1] != 1){
            x_1++;
            y_1++;
            if(point[x_1][y_1] == 4)
                Cutlife();
        }else{
            if((point[x_1+1][y_1] == 1 && point[x_1][y_1+1] == 1) || // hit the lower-right corner?
               (point[x_1+1][y_1] == 0 && point[x_1][y_1+1] == 0)){  // or hit something like
                d_1 = 3;                                             //   x
                                                                     //    +---
                                                                     //    |
                                                                     //    |
            }else if(point[x_1+1][y_1] == 1 && point[x_1][y_1+1] == 0) // hit right wall?
                d_1 = 2;
            else                                                       // hit down wall?
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

    // save last point here(the new location) is
    temp_1 = point[x_1][y_1];
    temp_2 = point[x_2][y_2];
    point[x_1][y_1] = 3;
    point[x_2][y_2] = 3;
    ShowSurface();
}

void Cutlife()
{
    int i,j; 
    // erase the lines   
    for(i = 0; i != WIN_COLS; i++)
        for(j = 0; j != WIN_LINES; j++){
            if(point[i][j] == 4)
                point[i][j] = 0;
        }

    // erase the block where player last is
    point[elfpoint_x][elfpoint_y] = elftemp;
    // reset player
    elftemp = 1;
    elfpoint_x = elfpoint_y = 0;
    point[elfpoint_x][elfpoint_y] = 2;
    // decrement life and prompt
    life--;
    if(life == 2)
        Print("You has 2 life");
    if(life == 1)
        Print("You has 1 life");
    if(life == 0)
    Print("Your Shame");
    // reset path
    Resetp();
    ShowSurface();
}
