#include "Sprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Sprite::Sprite(BufferedImage* image) {
    res = Resources::getInstance();
    this->image = image;
    res->scaleRatio = res->drawAreaWidth/(float)res->screenWidth;
    // define o Rect de destino para desenhar o sprite na tela
    rectDest.w=image->width*res->scaleRatio;
    rectDest.h=image->height*res->scaleRatio;
    rectDest.x=res->origX;
    rectDest.y=res->origY;
    posX = 0.0;
    posY = 0.0;
    speedX = 0.0;
    speedY = 0.0;
    
}
Sprite::~Sprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* Sprite::getRectDest(){
    rectDest.x=res->origX + (int)(posX*res->scaleRatio);
    rectDest.y=res->origY + (int)(posY*res->scaleRatio);
    return &rectDest;
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
void Sprite::render(){
    SDL_RenderCopy(this->res->renderer, this->image->texture,this->getFrame(),this->getRectDest());
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------
void Sprite::move(){
    posX+=(speedX*this->res->deltaTime);
    posY+=(speedY*this->res->deltaTime);
}
void Sprite::unmove(){
    posX-=((speedX*this->res->deltaTime));
    posY-=((speedY*this->res->deltaTime));
}
