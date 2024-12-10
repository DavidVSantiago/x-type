#include "cenario.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
Cenario::Cenario(string name):SimpleScene(name){

    res->setImagesAsset("src/assets/imgs/"); // define o diretório dos arquivos de imagem

    // carrega as imagens
    res->loadImage("bg2","pNG");
    res->loadImage("sprite_inimigo",".Png");
    res->loadImage("parada2",".png");

    // Criar uma lista de sprites
    vector<Sprite*> listaSprites;
    bg = new SimpleSprite(res->getImage("bg2"));
    listaSprites.push_back(bg);
    inimigo = new AnimatedSprite(res->getImage("sprite_inimigo"),2,5);
    inimigo->posX=10;
    inimigo->posY=200;
    inimigo->speedY=100; // 100px/s
    //listaSprites.push_back(inimigo);
    inimigo2 = new AnimatedSprite(res->getImage("sprite_inimigo"),2,5);
    inimigo2->posX=130;
    inimigo2->posY=300;
    inimigo2->speedY=100; // 100px/s
    //listaSprites.push_back(inimigo2);
    inimigo3 = new AnimatedSprite(res->getImage("sprite_inimigo"),2,5);
    inimigo3->posX=240;
    inimigo3->posY=100;
    inimigo3->speedY=100; // 100px/s
    //listaSprites.push_back(inimigo3);
    person = new SimpleSprite(res->getImage("parada2"));
    person->posX=480;
    person->posY=180;
    person->speedY=50;
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
    if(inimigo2->posY<=0 || (inimigo2->posY+inimigo2->getFrame()->h)>=this->res->screenHeight){
        inimigo2->unmove();
        inimigo2->speedY*=-1;
    }
    if(inimigo3->posY<=0 || (inimigo3->posY+inimigo3->getFrame()->h)>=this->res->screenHeight){
        inimigo3->unmove();
        inimigo3->speedY*=-1;
    }
    if(person->posY<=0 || (person->posY+person->getFrame()->h)>=this->res->screenHeight){
        person->unmove();
        person->speedY*=-1;
    }
}