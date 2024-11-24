#include "Resources.h"

//---------------------------------------------------------------------------------------------------------
// DEFINIÇÃO DOS ATRIBUTOS ESTÁTICOS
//---------------------------------------------------------------------------------------------------------
Resources *Resources::instance = nullptr; // inicialização da instância (específico do C++)
std::string Resources::PATH_IMGS_ASSETS = "src/assets/imgs/";

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------

Resources* Resources::getInstance(){
    if (instance == nullptr) {
        instance = new Resources;
    }
    return instance;
}

void Resources::init(int width, int height){
    vk_up = vk_down = vk_left = vk_right = false;
    screenWidth = width;
    screenHeigth = height;
    deltaTime = 0;
    window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

Uint64 Resources::getTimeTick(){return SDL_GetPerformanceCounter();}

SDL_Texture* loadImage(std::string fileName){
    // TODO implementar aqui a lógica de carregar a textura usando a biblioteca

    std::string source = Resources::PATH_IMGS_ASSETS+fileSource;
    // The final texture
    SDL_Texture *newTexture = NULL;
    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(source.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", source.c_str(), IMG_GetError());
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(res->renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", source.c_str(), SDL_GetError());
        }
        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}