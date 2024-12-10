#pragma once
#include <SDL2/SDL.h>

class BufferedImage{
public:
    /* ATRIBUTOS -------------------------------------------------------*/
    SDL_Texture* texture; // referência ao sprite na memória que será desenhado
    uint16_t width, height; // dimensões da imagem

    /* CONSTRUTORES E DESTRUTORES --------------------------------------*/
    BufferedImage(SDL_Texture* texture, uint16_t width, uint16_t height);
    ~BufferedImage();
};