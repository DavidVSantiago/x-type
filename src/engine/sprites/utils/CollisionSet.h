#pragma once
#include <SDL2/SDL.h>
#include <cstdint>
#include <vector>
#include <cmath>
#include "../../Resources.h"

using namespace std; 

/** Representa uma caixa de colisão */
typedef struct{
    SDL_Rect* rect; // coordenadas de renderização
    int refPosX,refPosY; // posição de referência, em relação ao sprite
}CollisionBox;

/** Representa uma conjunto de caixas de colisão. Geralmente associada a cada frame de um Sprite */
class CollisionSet{
    public:
    /* ATRIBUTOS -------------------------------------------------------*/
    vector<CollisionBox*> collBoxList; // lista de caixa de colisão
    Resources *res;

    /* CONSTRUTORES E DESTRUTORES --------------------------------------*/
    CollisionSet();
    virtual ~CollisionSet();

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/
    void render();

    /* MÉTODOS --------------------------------------------------------------------*/
    void addBox(int x,int y, int w, int h);
    void setBoxesPos(float posX, float posY);
};