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
    frameArray = new SDL_Rect[frameArraySize]; // vários quadros (máximo de 256)

    // percorre o array de quadros e adiciona e configura cada um dos quadros de recorte
    for(int l=0;l<lines;l++){
        for(int c=0;c<cols;c++){
            frameArray[cols*l+c].w=width;
            frameArray[cols*l+c].h=height;
            frameArray[cols*l+c].x=width*c;
            frameArray[cols*l+c].y=height*l;
        }
    }
    frameIndex = 0;

    // define o Rect de destino para desenhar o sprite na tela
    rectDest.w=width*res->scaleRatio;
    rectDest.h=height*res->scaleRatio;
    rectDest.x=res->origX;
    rectDest.y=res->origY;
}
MultiSimpleSprite::~MultiSimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* MultiSimpleSprite::getFrame(){
    return &frameArray[frameIndex]; // retorna o quadro especificado da matriz
}