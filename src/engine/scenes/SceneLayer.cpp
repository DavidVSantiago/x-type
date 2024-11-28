#include "SceneLayer.h"

SceneLayer::SceneLayer(){
    res = Resources::getInstance();
    posX = posY=0.0;
    spriteListCapacity = 50; // valor padrão da capacidade de sprites da cena
    spriteList = new Sprite*[spriteListCapacity];
    spriteListSize=0; // a princípio, nenhum sprite adicionado
}
SceneLayer::~SceneLayer(){}

/* MÉTODOS DO GAMELOOP */
void SceneLayer::render(){
    for(size_t i=0;i<spriteListSize;i++){
        spriteList[i]->render();
    }
}

/* MÉTODOS */
void SceneLayer::addSprite(Sprite* sprite){
    spriteList[spriteListSize++]=sprite;
}
Sprite* SceneLayer::getSprite(int index){
    return spriteList[index];
}