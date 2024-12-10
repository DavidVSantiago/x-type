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
        SDL_RenderDrawRect(this->res->renderer, collBoxList[i]);
    }
}

/* MÉTODOS --------------------------------------------------------------------*/
void CollisionSet::addBox(int x,int y, int w, int h){
    SDL_Rect* newBox = new SDL_Rect();
    newBox->x=x;
    newBox->y=y;
    newBox->w=w;
    newBox->h=h;
    collBoxList.push_back(newBox);
}
void CollisionSet::move(float speedX, float speedY){
    // move cada caixa de colisão
    for(size_t i=0; i<collBoxList.size();i++){
        collBoxList[i]->x+=(speedX*this->res->deltaTime);
        collBoxList[i]->y+=(speedY*this->res->deltaTime);
        printf("posY: %d\n",collBoxList[i]->y);
    }

}
void CollisionSet::unmove(float speedX, float speedY){
    // desmove cada caixa de colisão
    for(size_t i=0; i<collBoxList.size();i++){
        collBoxList[i]->x-=(speedX*this->res->deltaTime);
        collBoxList[i]->y-=(speedY*this->res->deltaTime);
    }
}