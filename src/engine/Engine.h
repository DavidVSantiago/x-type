#pragma once

#include <SDL2/SDL.h>
#include "Resources.h"
#include "scenes/SceneManager.h"
#include "scenes/Scene.h"

class Engine
{
protected:
    /* ATRIBUTOS PRIVADOS */
    Uint64 tempoAnterior, tempoAtual;
    Resources* res;
    SceneManager* sceneManager;
    Scene* actualScene;
    Uint32 frameDelay;

    /* MÉTODOS PRIVADOS */
    void checkEvents();

public:
    /* ATRIBUTOS */
    SDL_Event event;
    bool isRunning;

    /* CONSTRUTORES E DESTRUTORES */
    Engine(int width, int height);
    ~Engine();

    /* MÉTODOS DO GAMELOOP */
    virtual void handleEvents();
    virtual void update();
    void render();
    void gameloop();

    /* MÉTODOS */
    void checkSDLEvents();
    void setActualScene(Scene* scene){
        this->actualScene = scene;
    }
};