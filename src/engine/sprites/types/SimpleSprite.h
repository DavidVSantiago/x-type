#pragma once
#include "../Sprite.h"

using namespace std;

/** A Implementação mais simples de um Sprite.
 *  Possui apenas um único quadro de sprite. */
class SimpleSprite: public Sprite{
public:
    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    SimpleSprite(BufferedImage* image); // recebe a ref da imagem do sprite
    virtual ~SimpleSprite();

    /* GETTERS & SETTERS ----------------------------------------------------------*/
    SDL_Rect* getFrame() override; // Retorna a informação do Quadro único do sprite a ser desenhado
};