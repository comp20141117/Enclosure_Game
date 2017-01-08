#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <SDL2/SDL.h>
#include "cube.h"

/*the way of monster's move*/
enum move{DIAG, HORI, VERT};
enum direct{UP, DOWN, LEFT, RIGHT, LEFT_UP, LEFT_DOWN, RIGHT_UP, RIGHT_DOWN, PAUSE};
    
class MMonster{
public:
    MMonster();
    void MSetMonsterPox(int x, int y);
    void MSetMonsterWay(enum move temp);
    void MSetMonsterFlag(enum direct temp);
    
    int MGetMonsterPoxX();
    int MGetMonsterPoxY();
    enum move MGetMonsterWay();
    
    void MRenderMonster();
    
    void MonsterInit();

    void MovePause();
    void MoveUp(int x, int y);
    void MoveDown(int x, int y);
    void MoveLeft(int x, int y);
    void MoveRight(int x, int y);
    void MoveLeft_Up(int x, int y);
    void MoveLeft_Down(int x, int y);
    void MoveRight_Up(int x, int y);
    void MoveRight_Down(int x, int y);
    void Move();
private:
    SDL_Rect mmonster;
    enum move way;
    enum direct flag;
};
#endif
