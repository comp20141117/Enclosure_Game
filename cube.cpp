#include "cube.h"
#include "global.h"

MCube::MCube()
{
    mcube.x = 0;
    mcube.y = 0;
    mcube.w = CUBE;
    mcube.h = CUBE;
    mstate = EMPTY;
}

void MCube::MSetCubePox(int x, int y)
{
    mcube.x = x;
    mcube.y = y;
}

int MCube::MGetCubePoxX()
{
    return mcube.x;
}

int MCube::MGetCubePoxY()
{
    return mcube.y;
}

void MCube::MSetCubeState(enum cube temp)
{
    mstate = temp;
}

void MCube::MRenderCube()
{
    switch(mstate){
    case EMPTY:
        LoadTexture("./image/empty.png");
        break;
    case OCCUPY:
        LoadTexture("./image/occupy.png");
        break;
    case TRACE:
        LoadTexture("./image/trace.png");
        break;
    default:
        printf("mstate error!\n");
        break;
    }
    SDL_RenderCopy(renderer, texture, NULL, &mcube);
}

enum cube MCube::MGetCubeState()
{
    return mstate;
}
