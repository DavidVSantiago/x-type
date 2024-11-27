#include "cenario.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Cenario::Cenario(string name):SimpleScene(name){
    // carrega as imagens
    this->res->loadImage("bg",".png");
    this->res->loadImage("inimigo",".png");
    this->res->loadImage("parada",".png");

    // Criar uma lista de sprites
    vector<Sprite*> listaSprites;
    bg = new SimpleSprite(this->res->getImage("bg"));
    listaSprites.push_back(bg);
    inimigo = new SimpleSprite(this->res->getImage("inimigo"));
    inimigo->posX=10;
    inimigo->posY=200;
    inimigo->speedY=100; // 100px/s
    listaSprites.push_back(inimigo);
    person = new SimpleSprite(this->res->getImage("parada"));
    person->posX=480;
    person->posY=180;
    listaSprites.push_back(person);

    // adiciona um layer com os sprites
    addLayer(listaSprites);
}
Cenario::~Cenario(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS DO GAMELOOP
//---------------------------------------------------------------------------------------------------------
void Cenario::handleEvents(){

}
void Cenario::update(){
    inimigo->move();
    checkCollisions();
}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

void Cenario::checkCollisions(){
    if(inimigo->posY<=0 || (inimigo->posY+inimigo->getFrame()->h)>=this->res->screenHeight){
        inimigo->unmove();
        inimigo->speedY*=-1;
    }
}