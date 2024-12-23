#include "Engine.h"
#include <stdio.h>

//---------------------------------------------------------------------------------------------------------
// ATRIBUTOS privados
//---------------------------------------------------------------------------------------------------------
Engine *Engine::instance = nullptr; // inicialização da instância (específico do C++)

/*****************************************************************************/
/* CONSTRUTORES E DESTRUTORES */
/*****************************************************************************/

Engine::Engine(){}
Engine::~Engine(){}

/*****************************************************************************/
/* MÉTODOS DO GAMELOOP */
/*****************************************************************************/

void Engine::handleEvents(){
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT: res->isRunning = false; break;
            case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE)res->isRunning = false; break;
            // case SDL_WINDOWEVENT:
            //     this->oldFrameTime=this->res->getTimeTick();
            break;
        }
    }
    this->sceneManager->handleEvents(); // versão sobrescrita pelo cenário do cliente
}

void Engine::update(){
    this->sceneManager->update();
}

void Engine::render(){
    SDL_SetRenderDrawColor(this->res->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->res->renderer);
    this->sceneManager->render();
    SDL_RenderPresent(this->res->renderer);
}

void Engine::gameloop(){
    while (res->isRunning){
        startFrameTime = res->getTimeTick(); // amostra de tempo INICIAL do quadro
        res->deltaTime = (startFrameTime - oldFrameTime)/(float)res->getTimeTickFrequency();
        if(res->deltaTime>0.1) res->deltaTime = 0.1; // correção para limite máximo do deltatime
        oldFrameTime = startFrameTime; // atualiza o tempo anterior (para o próximo quadro)

        Engine::handleEvents();
        Engine::update();
        Engine::render();
        
        endFrameTime = res->getTimeTick(); // amostra de tempo FINAL do quadro
        diffTime=((endFrameTime-startFrameTime)*1000)/res->getTimeTickFrequency();
        if(diffTime < frameDelay) SDL_Delay(frameDelay - diffTime); // Pausa pelo tempo restante
    }
    SDL_DestroyRenderer(res->renderer);
    SDL_Quit();
}

/*****************************************************************************/
/* MÉTODOS */
/*****************************************************************************/
Engine* Engine::getInstance(){
    if (instance == nullptr) {
        instance = new Engine();
    }
    return instance;
}

void Engine::init(uint16_t width, uint16_t height, uint32_t pixelFormat){

    // inicializa o Resources
    res = Resources::getInstance();

    // inicializa as variável de tempo do gameloop
    this->frameDelay=16; // 16ms para 60FPS
    this->startFrameTime = this->oldFrameTime = this->res->getTimeTick();

    // inicializa o SDL ---------------
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        res->isRunning = false;
    }else{
        res->initDisplay(width,height,pixelFormat);
        res->getDisplay()->window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, res->getDisplay()->displayWidth, res->getDisplay()->displayHeight, SDL_WINDOW_SHOWN);
        if(res->getDisplay()->window == NULL ){
        printf( "WNão pode criar a janela do SDL! SDL_Error: %s\n", SDL_GetError() );
        res->isRunning=false;
        }else{
            res->setRenderer(SDL_CreateRenderer(res->getDisplay()->window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
            // inicializa o SceneManager
            this->sceneManager = SceneManager::getInstance();
            this->sceneManager->init();
        }
    }
}

void Engine::start(Scene* startScene, uint64_t timeMilis){
    sceneManager->startScene(startScene,timeMilis);
    SDL_Delay(1000);
    gameloop();
}