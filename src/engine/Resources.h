#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "utils/libs/lodepng.h"
#include <cstdint>
#include "utils/image/BufferedImage.h"

using namespace std;

class Resources
{
private:
    /* ATRIBUTOS privados -----------------------------------------------*/
    static Resources* instance; // singleton
    /** lista que armazenará todas as imagem do jogo carregadas em memória
        a cada imagem estará associada uma chave string */
    unordered_map<string, BufferedImage*> imagesMap;
    uint32_t pixelFormat;

    /* CONSTRUTORES E DESTRUTORES privados -----------------------------*/
    Resources();
    ~Resources();
public:

    /* ATRIBUTOS -------------------------------------------------------*/
    float deltaTime;
    bool vk_up,vk_down,vk_left,vk_right;
    uint16_t screenWidth,screenHeight;
    SDL_Window* window;
    SDL_Renderer* renderer;
    string PATH_IMGS_ASSETS;

    /* MÉTODOS ---------------------------------------------------------*/
    static Resources* getInstance(); // obtém o singleton
    void init(uint16_t width, uint16_t height, uint32_t pixelFormat);
    uint64_t getTimeTick();
    uint64_t getTimeTickFrequency();
    bool loadImage(string fileName, string fileExt); // adiciona uma nova imagem à lista
    BufferedImage* getImage(string imageName); // obtém a ref de uma imagem específico
    void clearImagens(); // limpa a lista de imagens carregadas na memória
    unsigned char* decode_PNG_File(string source, unsigned* width,unsigned* height);
    SDL_Texture* load_RGBA32_Texture(unsigned char* imageData, unsigned width, unsigned height);
    SDL_Texture* load_RGBA4444_Texture(unsigned char* imageData, unsigned width, unsigned height);
    SDL_Texture* load_RGBA5551_Texture(unsigned char* imageData, unsigned width, unsigned height);

    // formatos de profundidade de pixel a ser usado para renderizar as imagens do jogo
    enum {RGBA32,RGBA4444,RGBA5551};
};