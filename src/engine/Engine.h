#pragma once
#include <SDL2/SDL.h>
#include "Resources.h"
#include "scenes/SceneManager.h"
#include "scenes/Scene.h"

using namespace std;

class Engine
{
protected:
    /* ATRIBUTOS PRIVADOS */
    Uint64 startFrameTime, endFrameTime, oldFrameTime, diffTime, frameDelay;
    Resources* res;
    SceneManager* sceneManager;
    Scene* actualScene;

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
    void handleEvents();
    void update();
    void render();
    void gameloop();

    /* MÉTODOS */
    void checkSDLEvents();
    void setActualScene(Scene* scene){
        this->actualScene = scene;
    }
};