#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include "cenario.h"
#include "utils/resources.h"

class Game{
private:
    /* ATRIBUTOS PRIVADOS */
    int game_isRunning;
    SDL_Event game_event;

    /* MÉTODOS PRIVADOS */
public:
    /* ATRIBUTOS PÚBLICOS */
    Resources* res = NULL;
    Cenario cenarioAtual;
    
    /* MÉTODOS PÚBLICOS */
    void gameInit();
    void gameloop();
    void handleEvents();
    void update();
    void render();
}