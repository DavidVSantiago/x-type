#include "Sprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Sprite::Sprite(BufferedImage* image) {
    this->image = image;
    // define o Rect de origem para recorte do sprite
    rectOrig.w=image->width;
    rectOrig.h=image->heigth;
    rectOrig.x=rectOrig.y=0.0;
    // define o Rect de destino para desenhar o sprite na tela
    rectDest.w=image->width;
    rectDest.h=image->heigth;
    rectDest.x=rectDest.y=0.0;
    // ajusta as variáveis de posição e velocidade
    posX = 0.0;
    posY = 0.0;
    speedX = 0.0;
    speedY = 0.0;
    res = Resources::getInstance();
}
Sprite::~Sprite(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
SDL_Rect* Sprite::getRectOrig(){
    return &rectOrig;
}
SDL_Rect* Sprite::getRectDest(){
    rectDest.x=(int)posX;
    rectDest.y=(int)posY;
    return &rectDest;
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
void Sprite::render(){
    SDL_RenderCopy(this->res->renderer, this->image->texture,this->getRectOrig(),this->getRectDest());
}

