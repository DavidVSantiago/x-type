#pragma once
#include <SDL2/SDL.h>
#include "../Scene.h"
#include "../../sprites/Sprite.h"

using namespace std;

class SceneLayer; // declaração antecipada

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CENA SIMPLES */
/***********************************************************************************/
class SimpleScene : public Scene {    
public:
    /* ATRIBUTOS */

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SimpleScene(std::string name);
    ~SimpleScene();
    
    /* MÉTODOS */
    // void registrarSprite(Sprite* sprite);
    
    /* MÉTODOS DO GAMELOOP */
    virtual void handleEvents();
    virtual void update();
    virtual void render();
};

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DE SPRITES A SER INCORPORADA NA CENA */
/***********************************************************************************/