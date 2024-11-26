#include "Sprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Sprite::Sprite(BufferedImage* image) {
    this->image = image;
    res = Resources::getInstance();
    posX = 0.0;
    posY = 0.0;
    speedX = 0.0;
    speedY = 0.0;
}
Sprite::~Sprite(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
void Sprite::render(){
    SDL_RenderCopy(this->res->renderer, this->image->texture,this->getFrame(),this->getRectDest());
}

