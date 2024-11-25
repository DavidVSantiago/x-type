#include "SceneLayer.h"


/* MÉTODOS DO GAMELOOP */
void SceneLayer::render(){
    for(int i=0;i<spriteList.size();i++){
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