#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int LARGURA_TELA, ALTURA_TELA;
    int error_status;
    
} Resources;

// Função para acessar a instância
Resources* getResourceInstance();
