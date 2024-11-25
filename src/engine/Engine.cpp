#include "Engine.h"
#include <stdio.h>

/*****************************************************************************/
/* CONSTRUTORES E DESTRUTORES */
/*****************************************************************************/

Engine::Engine(int width, int height){
    this->frameDelay=16; // para 60FPS

    // inicializa o Resources
    this->res = Resources::getInstance();
    this->res->init(width, height);
    this->isRunning = true;

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

Engine::~Engine()
{
}

/*****************************************************************************/
/* MÉTODOS DO GAMELOOP */
/*****************************************************************************/

void Engine::handleEvents(){
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT: isRunning = false; break;
            case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE)isRunning = false;
        }
    }
    this->handleEvents(); // versão sobrescrita pelo cliente
}

void Engine::update(){
    this->update(); // versão sobrescrita pelo cliente
}

void Engine::render(){
    SDL_RenderClear(this->res->renderer);
    this->actualScene->render();
    SDL_RenderPresent(this->res->renderer);
}

void Engine::gameloop()
{
    while (this->isRunning)
    {
        this->tempoAtual = this->res->getTimeTick();
        this->res->deltaTime = (this->tempoAtual - this->tempoAnterior);

        Engine::handleEvents();
        Engine::update();
        Engine::render();

        this->tempoAnterior = this->tempoAtual; // atualiza o tempo anterior (para o próximo quadro)
        
        SDL_Delay(this->frameDelay); // Pausa pelo tempo restante
    }
    SDL_DestroyRenderer(this->res->renderer);
    SDL_DestroyWindow(this->res->window);
    SDL_Quit();
}