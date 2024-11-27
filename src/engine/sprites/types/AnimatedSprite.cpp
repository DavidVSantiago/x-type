#include "AnimatedSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
AnimatedSprite::AnimatedSprite(BufferedImage* image,uint8_t lines, uint8_t cols):MultiSimpleSprite(image,lines,cols) {
    frameTime = 0.2f;
    accTime=0.0f;
}
AnimatedSprite::~AnimatedSprite(){}

//---------------------------------------------------------------------------------------------------------
// GETTERS & SETTERS
//---------------------------------------------------------------------------------------------------------
SDL_Rect* AnimatedSprite::getFrame(){
    changeFrame(); // verifica uma possível mudança de quadro
    return MultiSimpleSprite::getFrame(); // invoca a versão da classe pai
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------
void AnimatedSprite::changeFrame(){
    accTime+=res->deltaTime;
    if(accTime>=frameTime){ // se o tempo acumulado do quadro alcançou o seu limite
        accTime=0.0f;
        frameIndex++; // pula para o próximo quadro da animação
        if(frameIndex==rectOrigMatrixSize) frameIndex=0;// verifica se ultrapassou o ultimo quadro e o reinicia caso positivo  
    }
}

