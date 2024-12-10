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
    frameIndex=0;
    
}
Sprite::~Sprite(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
void Sprite::update(){
    destArray[frameIndex]->x=(int)posX;
    destArray[frameIndex]->y=(int)posY;
}

void Sprite::render(){
    SDL_RenderCopy(this->res->renderer, this->image->texture,this->getFrame(),this->getDest());
    for(size_t i=0; i<collSetArray.size();i++){ // percorre cada caixa de colisão e desenha
        collSetArray[i]->render();
    }
}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* Sprite::getFrame(){
    return frameArray[frameIndex]; // retorna o quadro único
}
SDL_Rect* Sprite::getDest(){
    return destArray[frameIndex];
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------
void Sprite::move(){
    posX+=(speedX*this->res->deltaTime);
    posY+=(speedY*this->res->deltaTime);
    updateCollBoxes();
}
void Sprite::unmove(){
    posX-=((speedX*this->res->deltaTime));
    posY-=((speedY*this->res->deltaTime));
    updateCollBoxes();
    
}
// atualiza as posições das caixas de colisão
void Sprite::updateCollBoxes(){
    for(size_t i=0; i<collSetArray.size();i++){
        collSetArray[i]->setBoxesPos(posX,posY);
    }
}
