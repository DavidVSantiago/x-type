#include "game.h"
#include "cenario.h"

/* CONSTRUTORES E DESTRUTORES */
Game::Game(int width, int height):Engine(width,height){
    
    // criação da tela de splash
    Cenario* cenario = new Cenario();
    // this->sceneManager->startScene(cenario);

    gameloop(); // dispara o gameloop
}
Game::~Game(){}

void Game::handleEvents(){

}
void Game::update(){

}
void Game::render(){
    SDL_Rect origem,destino;
    
    SDL_RenderClear(this->res->renderer);
    SDL_RenderCopy(this->res->renderer, this->img, this->getFrame(),this->getPos());
    SDL_RenderPresent(this->res->renderer);
}