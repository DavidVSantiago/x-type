#include "resources.h"

// Ponteiro para a instância única
static Resources* instance = NULL;

// Função para acessar a instância
Resources* getResourceInstance() {
    if (instance == NULL) {
        // Inicializa a instância na primeira chamada
        instance = (Resources*)malloc(sizeof(Resources));

        instance->error_status = 0; // nehum erro de carregamento!

        instance->LARGURA_TELA = 853;
        instance->ALTURA_TELA = 480;

         /** Inicializa a janela*/
        instance->window = SDL_CreateWindow("Programa", 100, 100, instance->LARGURA_TELA, instance->ALTURA_TELA, SDL_WINDOW_SHOWN);
        if(instance->window == 0) {printf("SDL_Init Error: %s\n",SDL_GetError());SDL_Quit();instance->error_status = 1;}

        /* Inicializa o renderizador*/
        instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(instance->renderer == 0) {printf("SDL_Init Error: %s\n",SDL_GetError());SDL_DestroyWindow(instance->window);SDL_Quit();instance->error_status = 1;}

        if (instance == NULL) {
            fprintf(stderr, "Falha ao alocar memória para Singleton\n");
            exit(EXIT_FAILURE);
        }
    }
    return instance;
}
// Opcional: função para liberar a instância
void freeResourceInstance() {
    if (instance != NULL) {
        free(instance);
        instance = NULL;
    }
}