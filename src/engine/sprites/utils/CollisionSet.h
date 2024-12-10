#pragma once
#include <SDL2/SDL.h>
#include <cstdint>
#include <vector>
#include "../../Resources.h"

using namespace std; 

/** Representa uma conjunto de caixas de colisão. Geralmente associada a cada frame de um Sprite */
class CollisionSet{
    public:
    /* ATRIBUTOS -------------------------------------------------------*/
    vector<SDL_Rect*> collBoxList; // lista de caixa de colisão
    Resources *res;

    /* CONSTRUTORES E DESTRUTORES --------------------------------------*/
    CollisionSet();
    virtual ~CollisionSet();

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/
    void render();

    /* MÉTODOS --------------------------------------------------------------------*/
    void addBox(int x,int y, int w, int h);
    void move(float speedX, float speedY);
    void unmove(float speedX, float speedY);
};