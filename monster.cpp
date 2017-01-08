#include "monster.h"
#include "show.h"
#include "global.h"

MMonster::MMonster()
{
    mmonster.x = 0;
    mmonster.y = 0;
    mmonster.w = CUBE;
    mmonster.h = CUBE;
    way = VERT;
    flag = PAUSE;
}

void MMonster::MSetMonsterPox(int x, int y)
{
    mmonster.x = show.MReturnPoxX(x);
    mmonster.y = show.MReturnPoxY(y);
}

int MMonster::MGetMonsterPoxX()
{
    return mmonster.x;
}

int MMonster::MGetMonsterPoxY()
{
    return mmonster.y;
}

void MMonster::MRenderMonster()
{
    if(texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    LoadTexture("./image/monster.png");
    SDL_RenderCopy(renderer, texture, NULL, &mmonster);
}

void MMonster::MSetMonsterWay(enum move temp)
{
    way = temp;
}

void MMonster::MSetMonsterFlag(enum direct temp)
{
    flag = temp;
}

enum move MMonster::MGetMonsterWay()
{
    return way;
}

void MMonster::MonsterInit()
{
    switch(way){
    case DIAG:
        flag = LEFT_UP;
        break;
    case HORI:
        flag = RIGHT;
        break;
    case VERT:
        flag = UP;
        break;
    default:
        printf("monster move way is error!\n");
        break;
    }
}

void MMonster::MoveUp(int x, int y)
{
    enum cube temp;
    temp = show.MGetCubeState(x, y - 1);
    if(temp == OCCUPY)
        flag = DOWN;
    else if(temp == EMPTY)
        mmonster.y -= CUBE;
    else
        flag = PAUSE;
}

void MMonster::MoveDown(int x, int y)
{
    enum cube temp;
    temp = show.MGetCubeState(x, y + 1);
    if(temp == OCCUPY)
        flag = UP;
    else if(temp == EMPTY)
        mmonster.y += CUBE;
    else
        flag = PAUSE;
}

void MMonster::MoveLeft(int x, int y)
{
    enum cube temp;
    temp = show.MGetCubeState(x - 1, y);
    if(temp == OCCUPY)
        flag = RIGHT;
    else if(temp  == EMPTY)
        mmonster.x -= CUBE;
    else
        flag = PAUSE;
}

void MMonster::MoveRight(int x, int y)
{
    enum cube temp;
    temp = show.MGetCubeState(x + 1, y);
    if(temp == OCCUPY)
        flag = LEFT;
    else if(temp == EMPTY)
        mmonster.x += CUBE;
    else
        flag = PAUSE;
}

void MMonster::MovePause()
{
    flag = PAUSE;
}

void MMonster::MoveLeft_Up(int x, int y)
{
    int i;
    enum cube temp[4];
    temp[0] = show.MGetCubeState(x - 1, y - 1);
    temp[1] = show.MGetCubeState(x + 1, y - 1);
    temp[2] = show.MGetCubeState(x - 1, y + 1);
    temp[3] = show.MGetCubeState(x + 1, y + 1);
    for(i = 0; i < 4; i++){
        if(temp[i] == EMPTY){
            if(i == 0){
                mmonster.x -= CUBE;
                mmonster.y -= CUBE;
            }else if(i == 1)
                flag = RIGHT_UP;
            else if(i == 2)
                flag = LEFT_DOWN;
            else
                flag = RIGHT_DOWN;
            break;
        }
    }
    if(i == 4)
        flag = PAUSE;
}

void MMonster::MoveLeft_Down(int x, int y)
{
    int i;
    enum cube temp[4];
    temp[0] = show.MGetCubeState(x - 1, y + 1);
    temp[1] = show.MGetCubeState(x + 1, y + 1);
    temp[2] = show.MGetCubeState(x - 1, y - 1);
    temp[3] = show.MGetCubeState(x + 1, y - 1);
    for(i = 0; i < 4; i++){
        if(temp[i] == EMPTY){
            if(i == 0){
                mmonster.x -= CUBE;
                mmonster.y += CUBE;
            }else if(i == 1)
                flag = RIGHT_DOWN;
            else if(i == 2)
                flag = LEFT_UP;
            else
                flag = RIGHT_UP;
            break;
        }
    }
    if(i == 4)
        flag = PAUSE;
}
 
void MMonster::MoveRight_Up(int x, int y)
{
    int i;
    enum cube temp[4];
    temp[0] = show.MGetCubeState(x + 1, y - 1);
    temp[1] = show.MGetCubeState(x + 1, y + 1);
    temp[2] = show.MGetCubeState(x - 1, y - 1);
    temp[3] = show.MGetCubeState(x - 1, y + 1);
    for(i = 0; i < 4; i++){
        if(temp[i] == EMPTY){
            if(i == 0){
                mmonster.x += CUBE;
                mmonster.y -= CUBE;
            }else if(i == 1)
                flag = RIGHT_DOWN;
            else if(i == 2)
                flag = LEFT_UP;
            else
                flag = LEFT_DOWN;
            break;
        }
    }
    if(i == 4)
        flag = PAUSE;
}

void MMonster::MoveRight_Down(int x, int y)
{
    int i;
    enum cube temp[4];
    temp[0] = show.MGetCubeState(x + 1, y + 1);
    temp[1] = show.MGetCubeState(x + 1, y - 1);
    temp[2] = show.MGetCubeState(x - 1, y + 1);
    temp[3] = show.MGetCubeState(x - 1, y - 1);
    for(i = 0; i < 4; i++){
        if(temp[i] == EMPTY){
            if(i == 0){
                mmonster.x += CUBE;
                mmonster.y += CUBE;
            }else if(i == 1)
                flag = RIGHT_UP;
            else if(i == 2)
                flag = LEFT_DOWN;
            else
                flag = LEFT_UP;
            break;
        }
    }
    if(i == 4)
        flag = PAUSE;
}

void MMonster::Move()
{
    int x = show.MReturnX(mmonster.x);
    int y = show.MReturnY(mmonster.y);
    switch(flag){
    case UP:
        MoveUp(x, y);
        break;
    case DOWN:
        MoveDown(x, y);
        break;
    case LEFT:
        MoveLeft(x, y);
        break;
    case RIGHT:
        MoveRight(x, y);
        break;
    case LEFT_UP:
        MoveLeft_Up(x, y);
        break;
    case LEFT_DOWN:
        MoveLeft_Down(x, y);
        break;
    case RIGHT_UP:
        MoveRight_Up(x, y);
        break;
    case RIGHT_DOWN:
        MoveRight_Down(x, y);
        break;
    case PAUSE:
        MovePause();
        break;
    default:
        printf("monster flag is error!\n");
        break;
    }
}
