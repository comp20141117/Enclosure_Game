#ifndef _SHOW_H_
#define _SHOW_H_

#include "text.h"
#include "cube.h"
#include "monster.h"
#include "master.h"

/*the scope of game*/
#define GAMEWIDTH 60
#define GAMEHEIGHT 40
#define SPACE 20

class MShow{
public:
    MShow();
    void MInitShow();
    void MRenderShow();
    void MFillShow();
    
    /*convert x to mgame pox x*/
    int MReturnPoxX(int x);
    /*convert mgame pox x to x*/
    int MReturnX(int x);
    /*convert y  to mgame pox y*/
    int MReturnPoxY(int y);
    /*convert mgame pox y to y*/
    int MReturnY(int y);

    /*Get cube state*/
    enum cube MGetCubeState(int x, int y);
    void MSetCubeState(int x, int y, enum cube temp);
private:
    MCube mgame[GAMEWIDTH][GAMEHEIGHT];
    MText mhealth;
    MText mper;
    MText mscore;
};
#endif
