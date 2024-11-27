#pragma once
#include <SDL2/SDL.h>
#include "../Scene.h"
#include "../../sprites/Sprite.h"

using namespace std;

/***********************************************************************************/
/* CLASSE ABSTRATA QUE REPRESENTA UMA CENA SIMPLES */
/***********************************************************************************/
class SimpleScene : public Scene {    
public:
    /* ATRIBUTOS */

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SimpleScene(std::string name);
    ~SimpleScene();
    
    /* MÉTODOS */
    virtual void checkCollisions()=0;
};

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DE SPRITES A SER INCORPORADA NA CENA */
/***********************************************************************************/