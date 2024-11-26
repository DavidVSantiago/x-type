#include "Resources.h"

//---------------------------------------------------------------------------------------------------------
// ATRIBUTOS privados
//---------------------------------------------------------------------------------------------------------
Resources *Resources::instance = nullptr; // inicialização da instância (específico do C++)

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
    screenHeight = height;
    deltaTime = 0;
    window = nullptr;
    renderer = nullptr;
    PATH_IMGS_ASSETS = "src/assets/imgs/";
}

uint64_t Resources::getTimeTick(){return SDL_GetPerformanceCounter();}

bool Resources::loadImage(string fileName, string fileExt){

    string source = PATH_IMGS_ASSETS + fileName + fileExt; // prepara a string de consulta no arquivo
    SDL_Texture* newTexture = nullptr; // textura a ser colocada dentro da imagem

    // vetor para armazenar os dados brutos do pixel
    vector<unsigned char> imageData;
    unsigned width, height;

    // faz uso da biblioteca para carregar o png
    unsigned error = lodepng::decode(imageData,width,height,source.c_str());

    if(error){ // caso haja erro, imprime e retorna null
        printf("Erro ao carregar a imagem PNG %s: %s\n",source.c_str(),lodepng_error_text(error));
        return false;
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
        return false;
    }

    // após carregar o SDL_Surface, podemos convertê-lo para SDL_Texture
    newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!newTexture) { // verifica erro de conversão para SDL_Texture
        printf("Unable to create SDL_Texture: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface); // limpa memória para o surface

    // cria o objeto BufferedImage para ser retornado
    BufferedImage* image = new BufferedImage(newTexture, width, height);

    this->imagesMap[fileName] = image; // adiciona a imagem no mapa
    return true; // indica o sucesso da operação
}

BufferedImage* Resources::getImage(string imageName){
    if (this->imagesMap.find(imageName) != this->imagesMap.end())
        return this->imagesMap[imageName];
    printf("imagem não encontrada para a chave %s!\n",imageName.c_str());
    return nullptr;
}