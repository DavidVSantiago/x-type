#pragma once

#include <SDL2/SDL.h>
#include "../Resources.h"
#include "../sprites/Sprite.h"

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DA CENA. Os sprites da camada se movem junto com a camada*/
/***********************************************************************************/
class SceneLayer {
private:
    /* ATRIBUTOS privados ------------------------------------------------------------------*/
    Sprite** spriteList; // lista de sprites do layer
    uint8_t spriteListCapacity; // capacidade máxima da lista de sprites do layer (inicial = 50)
    uint8_t spriteListSize; // quantidade de layers atualmente na cena
    
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
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
    virtual void move();
};