#pragma once
#include <SDL2/SDL.h>
#include "Scene.h"


class SceneLayer; // declaração antecipada

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CENA SIMPLES */
/***********************************************************************************/
class SimpleScene : public Scene {    
public:
    // Sprite* sprite;

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    SimpleScene(std::string name);
    ~SimpleScene();
    
    /* MÉTODOS */
    // void registrarSprite(Sprite* sprite);

    /* MÉTODOS DO GAMELOOP */
    void render() override;
    void handleEvents() override;
    void update() override;
};

/***********************************************************************************/
/* CLASSE QUE REPRESENTA UMA CAMADA DE SPRITES A SER INCORPORADA NA CENA */
/***********************************************************************************/