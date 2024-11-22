#include "game.h"

/** ATRIBUTOS */
int game_isRunning;
SDL_Event game_event;
Resources* res = NULL;
Cenario* cenarioAtual;

// Definições das funções 
void gameInit(){
    res = getResourceInstance(); // obtém a intância de recursos
    game_isRunning = 1;

    // carregar o cenário, juntamente com as imagens referêntes ao cenário
    cenarioAtual = carregarCenario("fase_01");

    gameloop();
}
void gameloop() {
    while (game_isRunning) {

        handleEvents();// trata os eventos
        update();
        render();
    }
}

void handleEvents() {
    /** Teste de eventos do SDL*/
    while (SDL_PollEvent(&game_event)) {
        switch (game_event.type) {
            case SDL_QUIT:
                game_isRunning = 0;
                break;
            case SDL_KEYDOWN:
                if (game_event.key.keysym.sym == SDLK_ESCAPE) game_isRunning = 0;
        }
    }
    cenarioAtual.handleEvents();
}
void update() {
    cenarioAtual.update();
}
void render() {
    cenarioAtual.render();
    // SDL_RenderClear(res->renderer);
    // SDL_RenderPresent(res->renderer);
}
