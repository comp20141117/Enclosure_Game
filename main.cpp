#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "global.h"

#define FONT_SIZE 30

bool Init();
bool LoadMedia();
void Close();

bool Init()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }else{
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
            printf("Warning:Linear texture filtering not enabled!\n");
        }

        window = SDL_CreateWindow("Enclosure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL){
            printf("window could not be created! SDL Error:%s\n", SDL_GetError());
            success = false;
        }else{
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == NULL){
                printf("renderer could not be created!SDL Error:%s\n", SDL_GetError());
                success = false;
            }else{
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgflags = IMG_INIT_PNG;
                if(!(IMG_Init(imgflags) & imgflags)){
                    printf("SDL_image could not initialize! SDL_image Error:%s\n", IMG_GetError());
                    success = false;
                }

                if(TTF_Init() == -1){
                    printf("SDL_ttf could not initialize! TTF_Error:%s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool LoadMedia()
{
    int i;
    bool success = true;
    font = TTF_OpenFont("./font.ttf", FONT_SIZE);
    if(font == NULL){
        printf("Failed to load font! SDL_ttf Error:%s\n", TTF_GetError());
        success = false;
    }
    show.MInitShow();
    return success;
}

void Close()
{
    SDL_DestroyTexture(texture);
    texture = NULL;

    TTF_CloseFont(font);
    font = NULL;
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *args[])
{
    if(!Init()){
        printf("Failed to initialize!\n");
    }else{
        if(!LoadMedia()){
            printf("Failed to load media!\n");
        }else{
            bool quit = false;
            SDL_Event e;

            while(!quit){
                count++;
                
                while(SDL_PollEvent(&e) != 0){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }
                    
                    master.MControlMaster(&e);
                }
                
                SDL_RenderClear(renderer);
                show.MRenderShow();
                SDL_RenderPresent(renderer);
            }
        }
    }

    Close();
    return 0;
}
