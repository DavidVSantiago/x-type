#include "Engine.h"
#include <stdio.h>

/*****************************************************************************/
/* CONSTRUTORES E DESTRUTORES */
/*****************************************************************************/

Engine::Engine(int width, int height)
{
    // inicializa o SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    this->isRunning = true;
    
    this->frameDelay=16; // para 60FPS

    // inicializa o Resources
    this->res = Resources::getInstance();
    this->res->init(width, height);

    // inicializa o SceneManager
    this->sceneManager = SceneManager::getInstance();
    this->sceneManager->init();
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
}

void Engine::update(){
}

void Engine::render(){
    // SDL_RenderClear(this->res->renderer);
    // //this->sceneManager->render();
    // SDL_RenderPresent(this->res->renderer);
}

void Engine::gameloop()
{
    while (this->isRunning)
    {
        this->tempoAtual = this->res->getTimeTick();
        this->res->deltaTime = (this->tempoAtual - this->tempoAnterior);

        this->handleEvents();
        this->update();
        this->render();

        this->tempoAnterior = this->tempoAtual; // atualiza o tempo anterior (para o próximo quadro)
        
        SDL_Delay(this->frameDelay); // Pausa pelo tempo restante
    }
    SDL_DestroyRenderer(this->res->renderer);
    SDL_DestroyWindow(this->res->window);
    SDL_Quit();
}