#include "CollisionSet.h"

// ---------------------------------------------------------------------------------------
/** Representa uma conjunto de caixas de colisão. Geralmente associado a cada frame de um Sprite */
// ---------------------------------------------------------------------------------------

/* CONSTRUTORES E DESTRUTORES --------------------------------------*/
CollisionSet::CollisionSet(){
    res = Resources::getInstance();
}
CollisionSet::~CollisionSet(){}

/* MÉTODOS DO GAMELOOP --------------------------------------------------------*/
void CollisionSet::render(){
    for(size_t i=0; i<collBoxList.size();i++){ // percorre cada caixa de colisão e desenha
        SDL_SetRenderDrawColor(this->res->renderer, 255, 0, 0, 255); // Vermelho (RGBA)
        SDL_RenderDrawRect(this->res->renderer, collBoxList[i]->rect);
    }
}

/* MÉTODOS --------------------------------------------------------------------*/
void CollisionSet::addBox(int x,int y, int w, int h){
    SDL_Rect* rect = new SDL_Rect();
    rect->x=x;
    rect->y=y;
    rect->w=w;
    rect->h=h;
    CollisionBox* box = new CollisionBox();
    box->refPosX=x;
    box->refPosY=y;
    box->rect=rect;
    collBoxList.push_back(box);
}
void CollisionSet::setBoxesPos(float posX, float posY){
    // move cada caixa de colisão
    for(size_t i=0; i<collBoxList.size();i++){
        collBoxList[i]->rect->x=collBoxList[i]->refPosX+(int)posX;
        collBoxList[i]->rect->y=collBoxList[i]->refPosY+(int)posY;
    }
}