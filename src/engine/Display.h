#pragma once
#include <SDL2/SDL.h>

using namespace std;

class Display
{
public:
    /* ATRIBUTOS -------------------------------------------------------*/
    SDL_Window* window;
    uint16_t screenWidth, screenHeight; // resolução em pixels
    uint16_t displayWidth, displayHeight; // dimensões do display (monitor)
    uint16_t drawWidth, drawHeight; // resolução de desenho, da tela cheia
    float drawOriginX, drawOriginY; // origem do desenho da tela cheia
    float scaleRatio; // fator de escala para tela cheia
    /* CONSTRUTORES E DESTRUTORES --------------------------------------*/
    Display(uint16_t width, uint16_t height);
    ~Display();

    /* MÉTODOS ---------------------------------------------------------*/
   
};