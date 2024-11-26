#include "cenario.h"


Cenario::Cenario(string name):SimpleScene(name){
    // carrega as imagens
    this->res->loadImage("bg",".png");
    this->res->loadImage("inimigo",".png");
    this->res->loadImage("parada",".png");

    // Criar uma lista de sprites
    vector<Sprite*> listaSprites;
    bg = new Sprite(this->res->getImage("bg"));
    listaSprites.push_back(bg);
    inimigo = new Sprite(this->res->getImage("inimigo"));
    inimigo->posX=10;
    inimigo->posY=200;
    listaSprites.push_back(inimigo);
    person = new Sprite(this->res->getImage("parada"));
    person->posX=480;
    person->posY=180;
    listaSprites.push_back(person);

    // adiciona um layer com os sprites
    addLayer(listaSprites);
}
Cenario::~Cenario(){}


/* MÉTODOS */
void Cenario::handleEvents(){

}
void Cenario::update(){
    
}