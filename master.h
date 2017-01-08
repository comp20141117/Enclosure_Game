#ifndef _MASTER_H_
#define _MASTER_H_

#include <SDL2/SDL.h>
#include "cube.h"

class MMaster{
public:
    MMaster();
    void MRenderMaster();
    void MControlMaster(SDL_Event *e);
    enum cube MoveUp(int x, int y);
    enum cube MoveDown(int x, int y);
    enum cube MoveLeft(int x, int y);
    enum cube MoveRight(int x, int y);
private:
    SDL_Rect mmaster;
};
#endif
