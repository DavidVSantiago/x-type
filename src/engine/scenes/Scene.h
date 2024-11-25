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
    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    Scene(std::string name);
    ~Scene();

    /* MÉTODOS DO GAMELOOP */
    virtual void handleEvents();
    virtual void update();
    virtual void render();

    /* MÉTODOS */
    void addLayer(vector<Sprite*> spriteList);
    SceneLayer* getLayer(int index);
};