#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <algorithm>
#include <cctype> 
#include "utils/libs/lodepng.h"
#include "utils/ImageIO.h"

using namespace std;

class Resources
{
private:
    /* ATRIBUTOS privados -----------------------------------------------*/
    static Resources* instance; // singleton
    /** lista que armazenará todas as imagem do jogo carregadas em memória
        a cada imagem estará associada uma chave string */
    unordered_map<string, SDL_Texture*> imagesMap;
    ImageIO* imageIO;

    /* CONSTRUTORES E DESTRUTORES privados -----------------------------*/
    Resources();
    virtual ~Resources();
public:
    string PATH_IMGS_ASSETS;

    /* ATRIBUTOS -------------------------------------------------------*/
    float deltaTime;
    bool vk_up,vk_down,vk_left,vk_right;
    uint16_t screenWidth,screenHeight;
    SDL_Window* window;
    SDL_Renderer* renderer;

    /* MÉTODOS ---------------------------------------------------------*/
    static Resources* getInstance(); // obtém o singleton
    void init(uint16_t width, uint16_t height, uint32_t pixelFormat);
    void setRenderer(SDL_Renderer* renderer);
    void setImagesAsset(string path);
    string getImagesAsset();

    uint64_t getTimeTick();
    uint64_t getTimeTickFrequency();
    bool loadImage(string fileName, string fileExt);
    SDL_Texture* getImage(string imageName); // obtém a ref de uma imagem específico
    void clearImagens(); // limpa a lista de imagens carregadas na memória
    void formatFileExt(string &str);
};