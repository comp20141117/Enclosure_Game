#ifndef _TEXT_H_
#define _TEXT_H_

#include <SDL2/SDL.h>
#include <string>

/*class text*/
class MText{
public:
    MText();
    void MSetTextRect(int x, int y, int w, int h);
    void MSetTextString(std::string str);
    void MSetTextColor(SDL_Color color);
    void MRenderText();
    int MGetTextRectPoxX();
    int MGetTextRectPoxY();
    int MGetTextRectSizeW();
    int MGetTextRectSizeH();
private:
    SDL_Rect mtext;
    SDL_Color mcolor;
    std::string mstring;
};
#endif
