#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <cstdint>
#include <vector>
#include "../../Resources.h"
#include "../../utils/image/BufferedImage.h"
#include "../Sprite.h"

using namespace std;

/** Uma Implementação simples de um Sprite com vários quadros com a mesma dimensão.
 *  Cada quadro é usado para representar um estado, não quadros de uma animação!. */
class MultiSimpleSprite: public Sprite{
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
    uint16_t frameIndex; // indice do quadro a ser renderizado
    uint16_t frameArraySize; // quantidade de quadros do array

    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    // recebe a ref da imagem do sprite, junto com as quantidades de linhas e colunas do sprite
    // de onde serão cortados os quadros (máximo de 255 linhas e 255 colunas)
    MultiSimpleSprite(BufferedImage* image,uint8_t lines, uint8_t cols);
    virtual ~MultiSimpleSprite();

    /* GETTERS & SETTERS ----------------------------------------------------------*/
    SDL_Rect* getFrame() override; // Retorna a informação do Frame do sprite a ser desenhado
};