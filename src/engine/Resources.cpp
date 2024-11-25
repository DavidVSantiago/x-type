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
    window = nullptr;
    renderer = nullptr;
}

Uint64 Resources::getTimeTick(){return SDL_GetPerformanceCounter();}

SDL_Texture* Resources::loadImage(std::string fileName){
    // TODO implementar aqui a lógica de carregar a textura usando a biblioteca

    std::string source = Resources::PATH_IMGS_ASSETS + fileName; // prepara a string de consulta no arquivo
    SDL_Texture* newTexture = nullptr; // objeto a ser retornado com a imagem em memória
    
    // vetor para armazenar os dados brutos do pixel
    std::vector<unsigned char> imageData;
    unsigned width, height;

    // faz uso da biblioteca para carregar o png
    unsigned error = lodepng::decode(imageData,width,height,source.c_str());

    if(error){ // caso haja erro, imprime e retorna null
        printf("Erro ao carregar a imagem PNG %s: %s\n",source.c_str(),lodepng_error_text(error));
        return nullptr;
    }

    // uma vez que não houve erro, pode-se converter os dados para SDL_Surface
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
        imageData.data(), // Dados brutos dos pixels
        width,            // Largura da imagem
        height,           // Altura da imagem
        32,               // Bits por pixel
        width * 4,        // Pitch (bytes por linha)
        SDL_PIXELFORMAT_RGBA32 // Formato de pixel RGBA
    );

    if (!surface) {
        printf("Erro ao criar SDL_Surface: %s\n", SDL_GetError());
        return nullptr;
    }

    // após carregar o SDL_Surface, podemos convertê-lo para SDL_Texture
    newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!newTexture) { // verifica erro de conversão para SDL_Texture
        printf("Unable to create SDL_Texture: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface); // limpa memória para o surface

    return newTexture; // retorna a imagem pronta
}