#include "game.h"
#include "cenario.h"

/* CONSTRUTORES E DESTRUTORES */
Game::Game(int width, int height):Engine(width,height){
    
    Cenario* cenario = new Cenario("Cenario");
    setActualScene(cenario);

    gameloop(); // dispara o gameloop
}
Game::~Game(){}

void Game::handleEvents(){

}