#include "MultiSimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
MultiSimpleSprite::MultiSimpleSprite(BufferedImage* image,uint8_t lines, uint8_t cols):Sprite(image) {
    
    /* Um MultiSimpleSprite possui vários quadros.
    *  Por isso, os rects precisam ser definidos um a um.
    *  apesar da imagem ser recebida em matriz, os quadros são armazenados em um array */

    frameArraySize = lines*cols; // define a quantidade de quadros na matriz
    uint8_t width = image->width/cols; // calcula a largura de cada quadro
    uint8_t height = image->height/lines; // calcula a altura de cada quadro
    
    // define o array de Rects de origem para recorte do sprite
    for(int l=0;l<lines;l++){
        for(int c=0;c<cols;c++){
            SDL_Rect* rect = new SDL_Rect();
            rect->w=width;
            rect->h=height;
            rect->x=width*c;
            rect->y=height*l;
            frameArray.push_back(rect);
        }
    }
    frameIndex = 0;

    // define o Rect de destino para desenhar o sprite na tela
    for(int l=0;l<lines;l++){
        for(int c=0;c<cols;c++){
            SDL_Rect* rect = new SDL_Rect();
            rect->w=width;
            rect->h=height;
            rect->x=rect->y=0.0;
            destArray.push_back(rect);

        }
    }
}
MultiSimpleSprite::~MultiSimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* MultiSimpleSprite::getFrame(){
    return frameArray[frameIndex]; // retorna o quadro especificado da matriz
}

SDL_Rect* MultiSimpleSprite::getDest(){
    destArray[frameIndex]->x=(int)posX;
    destArray[frameIndex]->y=(int)posY;
    return destArray[frameIndex];
}
