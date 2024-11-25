#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "engine/scenes/types/SimpleScene.h"

using namespace std;

class Cenario: public SimpleScene{
private:
    /* ATRIBUTOS PRIVADOS */
    /* MÉTODOS PRIVADOS */
public:
    Sprite *bg,*inimigo,*person;
    Cenario(string name);
    ~Cenario();
    /* ATRIBUTOS PÚBLICOS */
    /* MÉTODOS PÚBLICOS */
    
    /* MÉTODOS DO GAMELOOP */
    void handleEvents();
    void update();
    void render() override;
};