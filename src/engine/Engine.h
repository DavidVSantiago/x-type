#pragma once
#include <SDL2/SDL.h>
#include "Resources.h"
#include "scenes/SceneManager.h"
#include "scenes/Scene.h"

using namespace std;

class Engine
{
private:
/* ATRIBUTOS privados -----------------------------------------------*/
    static Engine* instance; // singleton
    
    // variáveis de gerenciamento de deltatime
    Uint64 startFrameTime, endFrameTime, oldFrameTime, diffTime, frameDelay;

    Resources* res;
    SceneManager* sceneManager;

    /* CONSTRUTORES E DESTRUTORES privados -----------------------------*/
    Engine();
    ~Engine();

    /* MÉTODOS PRIVADOS */
    void checkEvents();

public:
    /* ATRIBUTOS */
    SDL_Event event;
    bool isRunning;

    /* MÉTODOS DO GAMELOOP */
    void handleEvents();
    void update();
    void render();
    void gameloop();

    /* MÉTODOS */
    static Engine* getInstance(); // obtém o singleton
    void init(uint16_t width, uint16_t height, uint32_t pixelFormat = ImageIO::RGBA32);
    void start(Scene* startScene, uint64_t timeMilis);
};