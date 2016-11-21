#ifndef _PARAMETER_H_
#define _PARAMETER_H_

#define WIN_LINES 30
#define WIN_COLS 90
#define L (WIN_COLS * WIN_LINES)

int point[WIN_COLS][WIN_LINES];  //screen point
int p[L][2]; //point path
int p_x; //path
int x_1;
int y_1;
int x_2;
int y_2;
int elfpoint_x;  //elf point x
int elfpoint_y;  //elf point y
int elftemp;  //under elf color
int direct;  //move direction
int d_1; // x_1,y_1 ghost move direction
int temp_1;
int d_2; //x_2,y_2 ghost move direction
int temp_2;
int life;

#endif
