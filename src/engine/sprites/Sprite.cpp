#include "Sprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Sprite::Sprite(BufferedImage* image) {
    this->image = image;
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
    SDL_RenderCopy(this->res->renderer, this->image->texture,this->getFrame(),this->getDest());
    for(size_t i=0; i<collSetArray.size();i++){ // percorre cada caixa de colisão e desenha
        collSetArray[i]->render();
    }
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------
void Sprite::move(){
    posX+=(speedX*this->res->deltaTime);
    posY+=(speedY*this->res->deltaTime);
    // Move cada caixa de colisão
    for(size_t i=0; i<collSetArray.size();i++){
        collSetArray[i]->move(speedX,speedY);
    }

}
void Sprite::unmove(){
    posX-=((speedX*this->res->deltaTime));
    posY-=((speedY*this->res->deltaTime));
    // Desmove cada caixa de colisão
    for(size_t i=0; i<collSetArray.size();i++){
        collSetArray[i]->unmove(speedX,speedY);
    }
}
