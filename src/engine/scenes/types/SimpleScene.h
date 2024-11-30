#pragma once
#include <SDL2/SDL.h>
#include "../Scene.h"
#include "../../sprites/Sprite.h"

/***********************************************************************************/
/* CLASSE ABSTRATA QUE REPRESENTA UMA CENA SIMPLES */
/***********************************************************************************/
class SimpleScene : public Scene {    
public:
    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SimpleScene(string name);
    ~SimpleScene();
    
    /* MÉTODOS */
    virtual void checkCollisions()=0;
};

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DE SPRITES A SER INCORPORADA NA CENA */
/***********************************************************************************/