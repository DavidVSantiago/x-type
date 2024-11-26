#include "SceneLayer.h"

SceneLayer::SceneLayer(){
    res = Resources::getInstance();
    posX = posY=0.0;
}
SceneLayer::~SceneLayer(){}

/* MÉTODOS DO GAMELOOP */
void SceneLayer::render(){
    for(size_t i=0;i<spriteList.size();i++){
        spriteList.at(i)->render();
    }
}

/* MÉTODOS */
void SceneLayer::addSprite(Sprite* sprite){
    spriteList.push_back(sprite);
}
Sprite* SceneLayer::getSprite(int index){
    return spriteList.at(index);
}