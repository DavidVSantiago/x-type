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
    Scene::update(); // obrigatório
}