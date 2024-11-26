#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "../Resources.h"
#include "SceneLayer.h"

using namespace std;

/***********************************************************************************/
/* CLASSE ABSTRATA QUE REPRESENTA A BASE DAS CENAS */
/***********************************************************************************/
class Scene {
protected:
    std::string name;
    Resources* res;
    vector<SceneLayer*> layersList;

public:
    /* CONSTRUTORES E DESTRUTORES*/
    Scene(std::string name);
    virtual ~Scene();

    /* MÉTODOS DO GAMELOOP */
    virtual void handleEvents()=0; // pure virtual (sem implementação aqui. deve ser implementada na derivada)
    virtual void update()=0; // pure virtual (sem implementação aqui. deve ser implementada na derivada)
    virtual void render();

    /* MÉTODOS */
    void addLayer(vector<Sprite*> spriteList);
    SceneLayer* getLayer(int index);
};