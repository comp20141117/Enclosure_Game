#ifndef _CUBE_H_
#define _CUBE_H_

#include <SDL2/SDL.h>
/*cube's state*/
enum cube{EMPTY, TRACE, OCCUPY};

/*class cube*/
class MCube
{
public:
    MCube();
    void MSetCubePox(int x, int y);
    void MSetCubeState(enum cube temp);
    void MRenderCube();
    int MGetCubePoxX();
    int MGetCubePoxY();
    enum cube MGetCubeState();
private:
    SDL_Rect mcube;
    enum cube mstate;
};

#endif
