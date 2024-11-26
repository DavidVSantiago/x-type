#include "MultiSimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
MultiSimpleSprite::MultiSimpleSprite(BufferedImage* image,uint8_t lines, uint8_t cols):Sprite(image) {
    
    /* Um MultiSimpleSprite possui vários quadros.
    *  Por isso, os rects precisam ser definidos um a um.
    *  apesar da imagem ser recebida em matriz, os quadros são armazenados em um array */

    uint8_t width = image->width/cols; // calcula a largura de cada quadro
    uint8_t height = image->height/lines; // calcula a altura de cada quadro
    
    // define a lista de Rects de origem para recorte do sprite
    for(uint8_t l=0; l<lines;l++){ // percorre as linhas
        for(uint8_t c=0; c<cols;c++){ // percorre as linhas
            SDL_Rect* rect = new SDL_Rect();
            rect->x=c*width;
            rect->y=l*height;
            rect->w=width;
            rect->h=height;
            rectOrigList.push_back(rect);
        }
    }

    // define o Rect de destino para desenhar o sprite na tela
    rectDest.w=width;
    rectDest.h=height;
    rectDest.x=rectDest.y=0.0;
}
MultiSimpleSprite::~MultiSimpleSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* MultiSimpleSprite::getFrame(){
    return rectOrigList.at(5); // TESTE
}
SDL_Rect* MultiSimpleSprite::getRectDest(){
    rectDest.x=(int)posX;
    rectDest.y=(int)posY;
    return &rectDest;
}

