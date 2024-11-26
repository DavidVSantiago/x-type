#include "MultiSimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
MultiSimpleSprite::MultiSimpleSprite(BufferedImage* image,uint8_t lines, uint8_t cols):Sprite(image) {
    
    /* Um MultiSimpleSprite possui vários quadros.
    *  Por isso, os rects precisam ser definidos um a um.
    *  apesar da imagem ser recebida em matriz, os quadros são armazenados em um array */

    frameMatrixColumns = lines*cols; // define a quantidade de quadros na matriz
    uint8_t width = image->width/cols; // calcula a largura de cada quadro
    uint8_t height = image->height/lines; // calcula a altura de cada quadro
    
    // define a matriz de Rects de origem para recorte do sprite
    // a matriz possui apenas uma linha, mas várias colunas
    frameMatrix = new SDL_Rect*[1]; // aloca apenas uma única linha
    frameMatrix[0] = new SDL_Rect[frameMatrixColumns]; // várias colunas, uma para cada quadro

    // percorre a matriz de quadros e adiciona e configura cada um dos quadros de recorte
    for(int l=0;l<lines;l++){
        for(int c=0;c<cols;c++){
            SDL_Rect* rect = frameMatrix[cols*l+c];
            rect->w=width;
            rect->h=height;
            rect->x=width*c;
            rect->y=height*l;
        }
    }
    frameIndex = 0;

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
    return frameMatrix[frameIndex]; // retorna o quadro especificado da matriz
}