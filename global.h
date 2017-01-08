#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "show.h"

/*MCube's side*/
#define CUBE 10
#define MONSTER 3

/*master's rate*/
extern int count;
extern int rate;

extern MMonster monsters[MONSTER];
extern MMaster master;

/*health,percent and score*/
extern int health;
extern int per;
extern int score;

/*MShow*/
extern MShow show;

/*size of screen*/
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

/*window, renderer, texture*/
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

/*font*/
extern TTF_Font *font;

/*render texture*/
void LoadTexture(std::string path);
#endif
