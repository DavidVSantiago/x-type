#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
SimpleSprite::SimpleSprite(BufferedImage* image):Sprite(image) {
    
    /* Um SimpleSprite possui apenas um único quadro.
    *  Por isso, os Recs de origem e destino são mais simples de se definir */

    // define o Rect de origem para recorte do sprite
    rectOrig.w=image->width;
    rectOrig.h=image->height;
    rectOrig.x=rectOrig.y=0.0;
}
SimpleSprite::~SimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* SimpleSprite::getFrame(){
    return &rectOrig;
}

