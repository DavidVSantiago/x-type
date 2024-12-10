#include "SimpleScene.h"

//---------------------------------------------------------------------------------------------------------
/* CONSTRUTORES E DESTRUTORES PRIVADOS*/
//---------------------------------------------------------------------------------------------------------
SimpleScene::SimpleScene(std::string name):Scene(name){}
SimpleScene::~SimpleScene(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------

void SimpleScene::update(){
    this->checkCollisions(); // invoca a implementação a ser fornecida por quem herdar
}