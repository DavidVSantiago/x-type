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
    SimpleScene(string name);
    ~SimpleScene();
    
    /* MÉTODOS DO GAMELOOP */
    void update() override; // implementa para invocar 'checkCollisions'

    /* MÉTODOS */
    virtual void checkCollisions()=0; // metodo que verificará as colisões entre os objetos da cena
};