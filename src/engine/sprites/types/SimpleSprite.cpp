#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
SimpleSprite::SimpleSprite(BufferedImage* image):Sprite(image) {
    
    /* Um SimpleSprite possui apenas um único quadro.
    *  Por isso, os Recs de origem e destino são mais simples de se definir */

    // define a matriz de Rects de origem para recorte do sprite
    // a matriz possui apenas uma linha e uma coluna
    frameMatrix[0] = new SDL_Rect[1]; // apenas uma única coluna
    frameMatrix[0][0].w=image->width;
    frameMatrix[0][0].h=image->height;
    frameMatrix[0][0].x=(*frameMatrix)->y=0.0;
}
SimpleSprite::~SimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* SimpleSprite::getFrame(){
    return &frameMatrix[0][0]; // retorna o quadro único
}

