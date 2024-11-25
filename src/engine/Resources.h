#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "utils/libs/lodepng.h"
#include "utils/image/BufferedImage.h"

using namespace std;

class Resources
{
private:
    static Resources* instance; // singleton
    /** lista que armazenará todas as imagem do jogo carregadas em memória
        a cada imagem estará associada uma chave string */
    unordered_map<string, BufferedImage*> imagesMap; 

    /* CONSTRUTORES E DESTRUTORES PRIVADOS*/
    Resources(){}
    ~Resources(){}
public:

    /* ATRIBUTOS */
    float deltaTime;
    bool vk_up,vk_down,vk_left,vk_right;
    int screenWidth,screenHeigth;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    /* CONSTANTES ESTÁTICAS */
    static string PATH_IMGS_ASSETS;

    /* MÉTODOS */
    static Resources* getInstance();
    void init(int width, int height);
    Uint64 getTimeTick();
    bool loadImage(string fileName, string fileExt);
    BufferedImage* getImage(string imageName); // obtém a ref de uma imagem específico
};