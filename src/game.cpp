#include "game.h"

/** ATRIBUTOS */

// Definições das funções 
void Game::gameInit(){
    res = getResourceInstance(); // obtém a intância de recursos
    game_isRunning = 1;

    // carregar o cenário, juntamente com as imagens referêntes ao cenário

    gameloop();
}
void Game::gameloop() {
    while (game_isRunning) {

        handleEvents();// trata os eventos
        update();
        render();
    }
}

void Game::handleEvents() {
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
    // cenarioAtual.handleEvents();
}
void Game::update() {
    // cenarioAtual.update();
}
void Game::render() {
    // cenarioAtual.render();
    // SDL_RenderClear(res->renderer);
    // SDL_RenderPresent(res->renderer);
}
