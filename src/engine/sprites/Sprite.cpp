#include "Sprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Sprite::Sprite(BufferedImage* image) {
    this->image = image;
    // define o Rect de destino para desenhar o sprite na tela
    rectDest.w=image->width;
    rectDest.h=image->height;
    rectDest.x=rectDest.y=0.0;
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
void Sprite::render(){
    SDL_RenderCopy(this->res->renderer, this->image->texture,this->getFrame(),this->getRectDest());
}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* Sprite::getRectDest(){
    rectDest.x=(int)posX;
    rectDest.y=(int)posY;
    return &rectDest;
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
