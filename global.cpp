#include "global.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>

int count = 0;
int rate = 1;
MMonster monsters[MONSTER];
MMaster master;

int health = 3;
int per = 0;
int score = 0;

MShow show;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
TTF_Font *font = NULL;

void LoadTexture(std::string path)
{
    if(texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    SDL_Texture *newtexture = NULL;
    SDL_Surface *surface = IMG_Load(path.c_str());
    if(surface == NULL){
        printf("unable to load image %s! SDL_image Error:%s\n", path.c_str(), IMG_GetError());
    }else{
        newtexture = SDL_CreateTextureFromSurface(renderer, surface);
        if(newtexture == NULL){
            printf("unable to create texture from %s! SDL Error:%s\n",path.c_str(), SDL_GetError());
        }

        SDL_FreeSurface(surface);
    }
    
    texture = newtexture;
    if(texture == NULL){
        printf("texture load failed! SDL Error:%s\n", SDL_GetError());
    }
}
