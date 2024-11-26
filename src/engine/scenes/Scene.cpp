#include "Scene.h"

//---------------------------------------------------------------------------------------------------------
/* CONSTRUTORES E DESTRUTORES PRIVADOS*/
//---------------------------------------------------------------------------------------------------------
Scene::Scene(std::string name){
    this->name = name; // toda Scene possui um nome associado a ela
    this->res = Resources::getInstance();
}
Scene::~Scene(){}

/* MÉTODOS DO GAMELOOP */
void Scene::render(){
    for(size_t i=0;i<layersList.size();i++){
        layersList.at(i)->render();
    }
}

/* MÉTODOS */
void Scene::addLayer(vector<Sprite*> spriteList){
    SceneLayer* layer = new SceneLayer();
    for(size_t i=0;i<spriteList.size();i++){
        layer->addSprite(spriteList.at(i)); // adiciona cada sprite ao novo layer
    }
    layersList.push_back(layer); // adiciona o novo layer (com seus sprites) à lista de layers
}

SceneLayer* Scene::getLayer(int index){
    return layersList.at(index);
}
