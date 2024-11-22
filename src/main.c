#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h"
#include "resources.h"

int main(int argc, char **argv) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {printf("SDL_Init Error: %s\n",SDL_GetError());return 1;}
    
    Resources* res = getResourceInstance(); // obtém a intancia de recursos
    if(res->error_status==1) return 1; // verifica erro de carregamento
    
    gameInit();

    SDL_DestroyRenderer(res->renderer);
    SDL_DestroyWindow(res->window);
    SDL_Quit();

    return 0;
}