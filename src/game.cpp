#include "game.h"
#include "cenario.h"

/* CONSTRUTORES E DESTRUTORES */
Game::Game(int width, int height){
    Engine* engine = new Engine(width,height);

    Cenario* cenario = new Cenario("Cenario");

    engine->gameloop(); // dispara o gameloop
}
Game::~Game(){}