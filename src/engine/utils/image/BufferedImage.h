#pragma once
#include <SDL2/SDL.h>

class BufferedImage{
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
    SDL_Texture* texture; // referência ao sprite na memória que será desenhado
    int width, heigth; // dimensões da imagem

    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    BufferedImage(SDL_Texture* texture, int width, int heigth);
    ~BufferedImage();
};