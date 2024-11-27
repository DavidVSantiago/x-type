#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
SimpleSprite::SimpleSprite(BufferedImage* image):Sprite(image) {
    
    /* Um SimpleSprite possui apenas um único quadro.
    *  Por isso, os Recs de origem e destino são mais simples de se definir */

    // define o Rect de origem para recorte do sprite
    rectOrigMatrix = (SDL_Rect**) malloc(sizeof(SDL_Rect*));
    *rectOrigMatrix = (SDL_Rect*) malloc(sizeof(SDL_Rect));
    (*rectOrigMatrix)->w=image->width;
    (*rectOrigMatrix)->h=image->height;
    (*rectOrigMatrix)->x=(*rectOrigMatrix)->y=0.0;
}
SimpleSprite::~SimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* SimpleSprite::getFrame(){
    return (*rectOrigMatrix);
}

