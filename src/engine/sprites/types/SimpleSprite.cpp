#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
SimpleSprite::SimpleSprite(BufferedImage* image):Sprite(image) {
    
    /* Um SimpleSprite possui apenas um único quadro.
    *  Por isso, os Recs de origem e destino são mais simples de se definir */

    // define o array de Rects de origem para recorte do sprite
    frameArray = new SDL_Rect[1]; // apenas um único quadro
    frameArray[0].w = image->width;
    frameArray[0].h = image->height;
    frameArray[0].x = frameArray[0].y=0.0;

    // define o Rect de destino para desenhar o sprite na tela
    destArray = new SDL_Rect[1]; // apenas um único quadro
    destArray[0].w = image->width;
    destArray[0].h = image->height;
    destArray[0].x = destArray[0].y=0.0;
}
SimpleSprite::~SimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* SimpleSprite::getFrame(){
    return &frameArray[0]; // retorna o quadro único
}

SDL_Rect* SimpleSprite::getDest(){
    destArray[0].x=(int)posX;
    destArray[0].y=(int)posY;
    return &destArray[0];
}

