#include "AnimatedSprite.h"

//---------------------------------------------------------------------------------------------------------
// MÉTODOS privados
//---------------------------------------------------------------------------------------------------------
void AnimatedSprite::changeFrame(){
    accTime+=res->deltaTime;
    if(accTime>=frameTime){ // se o tempo acumulado do quadro alcançou o seu limite
        accTime=0.0f;
        frameIndex++; // pula para o próximo quadro da animação
        if(frameIndex==frameArray.size()) frameIndex=0;// verifica se ultrapassou o ultimo quadro e o reinicia caso positivo  
    }
}

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
AnimatedSprite::AnimatedSprite(BufferedImage* image,uint8_t lines, uint8_t cols):MultiSimpleSprite(image,lines,cols) {
    frameTime = 0.2f;
    accTime=0.0f;
}
AnimatedSprite::~AnimatedSprite(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
void AnimatedSprite::update(){
    changeFrame(); // verifica uma possível mudança de quadro
}



