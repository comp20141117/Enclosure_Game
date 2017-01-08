#include "master.h"
#include "show.h"
#include "global.h"

MMaster::MMaster()
{
    mmaster.x = show.MReturnPoxX(0);
    mmaster.y = show.MReturnPoxY(0);
    mmaster.w = CUBE;
    mmaster.h = CUBE;
}

void MMaster::MRenderMaster()
{
    if(texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    LoadTexture("./image/master.png");
    SDL_RenderCopy(renderer, texture, NULL, &mmaster);
}

void MMaster::MControlMaster(SDL_Event *e)
{
    if(e->type == SDL_KEYDOWN){
        enum cube temp[2];
        int x = show.MReturnX(mmaster.x);
        int y = show.MReturnY(mmaster.y);
        temp[0] = show.MGetCubeState(x, y);

        switch(e->key.keysym.sym){
        case SDLK_UP:
            temp[1] = MoveUp(x, y);
            break;
        case SDLK_DOWN:
            temp[1] = MoveDown(x, y);
            break;
        case SDLK_LEFT:
            temp[1] = MoveLeft(x, y);
            break;
        case SDLK_RIGHT:
            temp[1] = MoveRight(x, y);
            break;
        default:
            break;
        }
        if(temp[0] == OCCUPY)
            ;
        else if(temp[0] == TRACE){
            show.MSetCubeState(x, y, OCCUPY);
        }
        else{
            if(temp[1] == EMPTY)
                show.MSetCubeState(x, y, TRACE);
            else if(temp[1] == TRACE)
                show.MSetCubeState(x, y, OCCUPY);
            else{
                show.MSetCubeState(x, y, TRACE);
                show.MFillShow();
                printf("fill\n");
            }
        }
    }
}

enum cube MMaster::MoveUp(int x, int y)
{
    if(y > 0){
        mmaster.y -= CUBE;
        return show.MGetCubeState(x, y - 1);
    }
}

enum cube MMaster::MoveDown(int x, int y)
{
    if(y < GAMEHEIGHT - 1){
        mmaster.y += CUBE;
        return show.MGetCubeState(x, y + 1);
    }
}

enum cube MMaster::MoveLeft(int x, int y)
{
    if(x > 0){
        mmaster.x -= CUBE;
        return show.MGetCubeState(x - 1, y);
    }
}

enum cube MMaster::MoveRight(int x, int y)
{
    if(x < GAMEWIDTH - 1){
        mmaster.x += CUBE;
        return show.MGetCubeState(x + 1, y);
    }
}
