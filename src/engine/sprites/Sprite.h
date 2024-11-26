#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "../Resources.h"
#include "../utils/image/BufferedImage.h"

using namespace std;

/** Implementação abstrata de um Sprite.
 * Elementos básicos de todos os tipos de Sprites. */
class Sprite{
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
    BufferedImage* image; // imagem do sprite
    float posX, posY;
    float speedX;
    float speedY;
    Resources* res;

    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    Sprite(BufferedImage* image); // recebe a ref da imagem do sprite
    ~Sprite();

    /* GETTERS & SETTERS ----------------------------------------------------------*/
    virtual SDL_Rect* getFrame()=0; // Retorna a informação do Frame do sprite a ser desenhado
    virtual SDL_Rect* getRectDest()=0; // Retorna a informação da destino de desenho na tela

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/
    void render();
};