#include "game.h"
#include "cenario.h"

/* CONSTRUTORES E DESTRUTORES */
Game::Game(int width, int height):Engine(width,height){
    
    // criação da tela de splash
    Cenario* cenario = new Cenario();
    testeImg = res->loadImage("ship.png");
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
    origem.x=0;
    origem.y=0;
    origem.w=65;
    origem.h=25;
    destino.x=0;
    destino.y=0;
    destino.w=65;
    destino.h=25;
    
    SDL_RenderClear(this->res->renderer);
    SDL_RenderCopy(this->res->renderer, this->testeImg,&origem,&destino);
    SDL_RenderPresent(this->res->renderer);
}