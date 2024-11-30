#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
SimpleSprite::SimpleSprite(BufferedImage* image):Sprite(image) {
    
    /* Um SimpleSprite possui apenas um único quadro.
    *  Por isso, os Recs de origem e destino são mais simples de se definir */

    // define o array de Rects de origem para recorte do sprite
    frameArray = new SDL_Rect[1]; // apenas um único quadro
    frameArray[0].w=image->width*(res->drawAreaWidth/(float)image->width);
    frameArray[0].h=image->height*(res->drawAreaHeight/(float)image->height);
    frameArray[0].x=0+res->origX;
    frameArray[0].y=0+res->origY;
}
SimpleSprite::~SimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* SimpleSprite::getFrame(){
    return &frameArray[0]; // retorna o quadro único
}

