#pragma once

#include <SDL2/SDL.h>
#include "../Resources.h"
#include "../sprites/Sprite.h"

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DA CENA. Os sprites da camada se movem junto com a camada*/
/***********************************************************************************/
class SceneLayer {
private:
    vector<Sprite*> spriteList;
public:
    Resources* res;
    float posX,posY;

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SceneLayer();
    ~SceneLayer();

    /* MÉTODOS DO GAMELOOP */
    void render();
    
    /* MÉTODOS */
    void addSprite(Sprite* sprite);
    Sprite* getSprite(int index);
};