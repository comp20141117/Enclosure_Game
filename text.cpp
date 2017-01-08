#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "text.h"
#include "global.h"

MText::MText()
{
    mtext.x = 0;
    mtext.y = 0;
    mtext.w = 100;
    mtext.h = 100;
    mstring = "init";
    mcolor.r = 0x00;
    mcolor.g = 0x00;
    mcolor.b = 0x00;
    mcolor.a = 0xFF;
}

void MText::MSetTextRect(int x, int y, int w, int h)
{
    mtext.x = x;
    mtext.y = y;
    mtext.w = w;
    mtext.h = h;
}

void MText::MSetTextString(std::string str)
{
    mstring = str;
}

void MText::MSetTextColor(SDL_Color color)
{
    mcolor = color;
}

void MText::MRenderText()
{
    if(texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    TTF_SizeText(font, mstring.c_str(), &mtext.w, &mtext.h);
    SDL_Surface *surface = TTF_RenderText_Solid(font, mstring.c_str(), mcolor);
    if(surface == NULL){
        printf("Unable to render text surface! SDL_ttf Error:%s\n",TTF_GetError());
    }else{
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(texture == NULL){
            printf("Unable to create texture from renderer text! SDL Error:%s\n", SDL_GetError());
        }else{
            SDL_RenderCopy(renderer, texture, NULL, &mtext);
        }

        SDL_FreeSurface(surface);
    }
}

int MText::MGetTextRectPoxX()
{
    return mtext.x;
}

int MText::MGetTextRectPoxY()
{
    return mtext.y;
}

int MText::MGetTextRectSizeW()
{
    return mtext.w;
}

int MText::MGetTextRectSizeH()
{
    return mtext.h;
}
