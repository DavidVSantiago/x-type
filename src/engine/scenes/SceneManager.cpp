#include "SceneManager.h"

SceneManager *SceneManager::instance = nullptr; // inicialização da instância (específico do C++)

//---------------------------------------------------------------------------------------------------------
/* MÉTODOS */
//---------------------------------------------------------------------------------------------------------

SceneManager* SceneManager::getInstance(){
    if (instance == nullptr) {
        instance = new SceneManager();
    }   
    return instance;
}
void SceneManager::init(){
    actualScene = nullptr;
}
void SceneManager::startScene(Scene* scene){
    this->actualScene = scene;
}

//---------------------------------------------------------------------------------------------------------
/* MÉTODOS DO GAMELOOP */
//---------------------------------------------------------------------------------------------------------

void SceneManager::handleEvents(){
    this->actualScene->handleEvents();
}
void SceneManager::update(){
    this->actualScene->update();
}
void SceneManager::render(){
    this->actualScene->render();
}