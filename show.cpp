#include "show.h"
#include "global.h"
#include <sstream>
#include <stdlib.h>

static std::stringstream string;
static int temp;
static int ReturnTemp()
{
    int i, j;
    temp = 0;
    for(i = 1; i < GAMEWIDTH - 1; i++)
        for(j = 1; j < GAMEHEIGHT - 1; j++)
            if(show.MGetCubeState(i, j) == OCCUPY)
                temp++;
    return temp;
}

MShow::MShow()
{
    /*initialize mgame's pos*/
    int i, j;
    int x, y;
    for(i = 0; i < GAMEWIDTH; i++)
        for(j = 0; j < GAMEHEIGHT; j++){
            x = i * CUBE + SPACE;
            y = (SCREEN_HEIGHT - SPACE - GAMEHEIGHT * CUBE) + j * CUBE;
            mgame[i][j].MSetCubePox(x, y);
        }
}

void MShow::MInitShow()
{
    int i, j;
    /*initialize mgame state*/
    for(i = 0; i < GAMEWIDTH; i++)
        for(j = 0; j < GAMEHEIGHT; j++){
            if(j == 0 || j == GAMEHEIGHT - 1)
                mgame[i][j].MSetCubeState(OCCUPY);
            else if(i == 0 || i == GAMEWIDTH - 1)
                mgame[i][j].MSetCubeState(OCCUPY);
        }

    /*initialize monster*/
    monsters[0].MSetMonsterWay(DIAG);
    monsters[1].MSetMonsterWay(VERT);
    monsters[2].MSetMonsterWay(HORI);
    srand(time(0));
    for(i = 0; i < MONSTER; i++){
        int temp1,temp2;
        temp1 = rand() % (GAMEWIDTH - 1);
        temp2 = rand() % (GAMEHEIGHT - 1);
        monsters[i].MSetMonsterPox(temp1, temp2);
        monsters[i].MonsterInit();
    }
}

void MShow::MRenderShow()
{
    int i, j;
    int temp;

    /*handle per and score*/
    score = ReturnTemp() * 5;
    per = ReturnTemp() * 100 / ((GAMEWIDTH - 1) * (GAMEHEIGHT - 1));
    
    /*render mgame*/
    for(i = 0; i < GAMEWIDTH; i++)
        for(j = 0; j < GAMEHEIGHT; j++)
            mgame[i][j].MRenderCube();

    /*set health's string and pos*/
    mhealth.MSetTextRect(SPACE , 0, 0, 0);
    /*render health*/
    string.str("");
    string << "health: ";
    for(i = 0; i < health; i++)
        string << "+";
    mhealth.MSetTextString(string.str());
    mhealth.MRenderText();

    /*set per pos*/
    temp = (SCREEN_WIDTH - 2 * SPACE)/3 + mhealth.MGetTextRectPoxX();
    mper.MSetTextRect(temp, 0, 0, 0);
    /*render per*/
    string.str("");
    string << "per: " << per << "%";
    mper.MSetTextString(string.str());
    mper.MRenderText();

    /*set score pos*/
    temp = (SCREEN_WIDTH - 2 * SPACE)/3 + mper.MGetTextRectPoxX();
    mscore.MSetTextRect(temp, 0, 0, 0);
    /*render score*/
    string.str("");
    string << "score: " << score;
    mscore.MSetTextString(string.str());
    mscore.MRenderText();

    /*render monster*/
    for(i = 0; i < MONSTER; i++){
        if(count % rate == 0)
            monsters[i].Move();
        monsters[i].MRenderMonster();
    }

    /*render master*/
    master.MRenderMaster();
}

int MShow::MReturnPoxX(int x)
{
    return x * CUBE + SPACE;
}

int MShow::MReturnX(int x)
{
    return (x - SPACE)/CUBE;
}

int MShow::MReturnPoxY(int y)
{
    return (SCREEN_HEIGHT - SPACE - GAMEHEIGHT * CUBE) + y * CUBE;
}

int MShow::MReturnY(int y)
{
    return (y - (SCREEN_HEIGHT - SPACE - GAMEHEIGHT * CUBE))/CUBE;
}

enum cube MShow::MGetCubeState(int x, int y)
{
    return mgame[x][y].MGetCubeState();
}

void MShow::MSetCubeState(int x, int y, enum cube temp)
{
    mgame[x][y].MSetCubeState(temp);
}

void MShow::MFillShow()
{
    
}
