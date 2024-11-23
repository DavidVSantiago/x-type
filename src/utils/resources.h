#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

class Resources{
private:
    SDL_Window *window;
    SDL_Renderer *renderer
    /* ATRIBUTOS PRIVADOS */

    /* MÉTODOS PRIVADOS */
public:
    /* ATRIBUTOS PÚBLICOS */
    int LARGURA_TELA, ALTURA_TELA;
   
    /* MÉTODOS PÚBLICOS */
}


typedef struct {
   
    
} Resources;

// Função para acessar a instância
Resources* getResourceInstance();
