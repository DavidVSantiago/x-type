#pragma once
#include <vector>
#include "../Resources.h"
#include "utils/BufferedImage.h"
#include "utils/CollisionSet.h"

using namespace std;

/** Implementação abstrata de um Sprite.
 * Elementos básicos de todos os tipos de Sprites. */
class Sprite{
public:
    /* ATRIBUTOS ------------------------------------------------------------------*/
    BufferedImage *image; // imagem do sprite
    vector<SDL_Rect*> frameArray; // Array de Rects de origem para renderização
    vector<SDL_Rect*> destArray; // Array de Rcts de destino para renderização
    vector<CollisionSet*> collSetArray; // Array de conjuntos de caixas de colisão
    float posX, posY;
    float speedX;
    float speedY;
    Resources *res;

    /* CONSTRUTORES E DESTRUTORES -------------------------------------------------*/
    Sprite(BufferedImage* image); // recebe a ref da imagem do sprite
    virtual ~Sprite();

    /* GETTERS & SETTERS ----------------------------------------------------------*/
    virtual SDL_Rect* getFrame()=0; // Retorna a informação do Frame do sprite a ser desenhado
    virtual SDL_Rect* getDest()=0; // Retorna a informação da destino de desenho na tela

    /* MÉTODOS DO GAMELOOP --------------------------------------------------------*/
    void render();

    /* MÉTODOS --------------------------------------------------------------------*/
    void move();
    void unmove();
};