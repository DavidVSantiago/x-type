#include "SimpleSprite.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
SimpleSprite::SimpleSprite(BufferedImage* image):Sprite(image) {
    
    /* Um SimpleSprite possui apenas um único quadro.
    *  Por isso, os Recs de origem e destino são mais simples de se definir */

    // define o array de Rects de origem para recorte do sprite
    frameArray.push_back(new SDL_Rect()); // apenas um único quadro
    frameArray[0]->w = image->width;
    frameArray[0]->h = image->height;
    frameArray[0]->x = frameArray[0]->y=0.0;

    // define o Rect de destino para desenhar o sprite na tela
    destArray.push_back(new SDL_Rect()); // apenas um único quadro
    destArray[0]->w = image->width;
    destArray[0]->h = image->height;
    destArray[0]->x = destArray[0]->y=0.0;

    // define o array de Rects de origem para recorte do sprite
    CollisionSet* set = new CollisionSet(); // cria um novo conjunto de caixas de colisão
    set->addBox(30,5,image->width-60,image->height-10); // adiciona 
    set->addBox(0,10,image->width-30,image->height-5); // adiciona 
    collSetArray.push_back(set);
}
SimpleSprite::~SimpleSprite(){}

/** MÉTODOS */
void SimpleSprite::addCollisionBox(int x, int y, int w, int h){
    CollisionSet* set = new CollisionSet(); // cria um novo conjunto de caixas de colisão
    set->addBox(x,y,w,h); // adiciona 
    collSetArray.push_back(new CollisionSet()); // adiciona o conjunto de caixas de colisão para o quadro único
    collSetArray[0]->addBox(10,10,image->width-20,image->height-20); // adiciona
    
}

