#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "engine/scenes/types/SimpleScene.h"
#include "engine/sprites/types/SimpleSprite.h"
#include "engine/sprites/types/MultiSimpleSprite.h"

using namespace std;

class Cenario: public SimpleScene{
public:
    /* ATRIBUTOS ----------------------------------------------*/
    Sprite *bg,*inimigo,*person;
    /* CONSTRUTORES E DESTRUTORES -----------------------------*/
    Cenario(string name);
    ~Cenario();
    
    /* MÉTODOS DO GAMELOOP ------------------------------------*/
    void handleEvents() override;
    void update() override;

    /* MÉTODOS SOBRESCRITOS ------------------------------------------------*/
    void checkCollisions() override;
};