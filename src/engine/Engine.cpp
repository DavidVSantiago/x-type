#include "Engine.h"
#include <stdio.h>

/*****************************************************************************/
/* CONSTRUTORES E DESTRUTORES */
/*****************************************************************************/

Engine::Engine(int width, int height){

    // inicializa o Resources
    this->res = Resources::getInstance();
    this->res->init(width, height);
    this->isRunning = true;

    // inicializa as variável de tempo do gameloop
    this->frameDelay=16; // 16ms para 60FPS
    this->startFrameTime = this->oldFrameTime = this->res->getTimeTick();

    // inicializa o SDL ---------------
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        this->isRunning = false;
    }else{
        this->res->window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        if( this->res->window == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            this->isRunning = false;
        }else
        this->res->renderer = SDL_CreateRenderer(this->res->window, -1, 0);

        // inicializa o SceneManager
        this->sceneManager = SceneManager::getInstance();
        this->sceneManager->init();
    }
}

Engine::~Engine(){
}

/*****************************************************************************/
/* MÉTODOS DO GAMELOOP */
/*****************************************************************************/

void Engine::handleEvents(){
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT: isRunning = false; break;
            case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE)isRunning = false; break;
            case SDL_WINDOWEVENT:
                this->oldFrameTime=this->res->getTimeTick();
            break;
        }
    }
    this->sceneManager->handleEvents(); // versão sobrescrita pelo cenário do cliente
}

void Engine::update(){
    this->sceneManager->update();
}

void Engine::render(){
    SDL_RenderClear(this->res->renderer);
    this->sceneManager->render();
    SDL_RenderPresent(this->res->renderer);
}

void Engine::gameloop(){
    while (this->isRunning){
        this->startFrameTime = this->res->getTimeTick(); // amostra de tempo INICIAL do quadro
        this->res->deltaTime = (this->startFrameTime - this->oldFrameTime)/(float)this->res->getTimeTickFrequency();
        this->oldFrameTime = this->startFrameTime; // atualiza o tempo anterior (para o próximo quadro)

        Engine::handleEvents();
        Engine::update();
        Engine::render();
        
        this->endFrameTime = this->res->getTimeTick(); // amostra de tempo FINAL do quadro
        this->diffTime=((this->endFrameTime-this->startFrameTime)*1000)/this->res->getTimeTickFrequency();
        // printf("DeltaTime: %f\n",this->res->deltaTime);
        if(this->diffTime < this->frameDelay) SDL_Delay(this->frameDelay - this->diffTime); // Pausa pelo tempo restante
    }
    SDL_DestroyRenderer(this->res->renderer);
    SDL_DestroyWindow(this->res->window);
    SDL_Quit();
}