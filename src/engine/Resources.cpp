#include "Resources.h"
#include <iostream>
#include <vector>
#include <fstream>

//---------------------------------------------------------------------------------------------------------
// ATRIBUTOS privados
//---------------------------------------------------------------------------------------------------------
Resources *Resources::instance = nullptr; // inicialização da instância (específico do C++)

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES privados
//---------------------------------------------------------------------------------------------------------
Resources::Resources(){}
Resources::~Resources(){}

//---------------------------------------------------------------------------------------------------------
// MÉTODOS
//---------------------------------------------------------------------------------------------------------
Resources* Resources::getInstance(){
    if (instance == nullptr) {
        instance = new Resources;
    }
    return instance;
}

void Resources::init(uint16_t width, uint16_t height, uint32_t pixelFormat){
    this->pixelFormat = pixelFormat;
    vk_up = vk_down = vk_left = vk_right = false;
    screenWidth = width;
    screenHeight = height;
    deltaTime = 0;
    window = nullptr;
    renderer = nullptr;
    PATH_IMGS_ASSETS = "";
}

uint64_t Resources::getTimeTick(){return SDL_GetPerformanceCounter();}
uint64_t Resources::getTimeTickFrequency(){return SDL_GetPerformanceFrequency();}

bool Resources::loadImage(string fileName, string fileExt){

    string source = PATH_IMGS_ASSETS + fileName + fileExt; // prepara a string de consulta no arquivo

    // prepara os dados para decodificação do arquivo
    unsigned width, height;
    
    // carrega e decodifica os dados brutos da imagem PNG a partir do arquivo.
    unsigned char* imageData = decode_PNG_File(source,&width,&height);

    SDL_Texture* newTexture = nullptr; // textura da imagem na memória

    // converte os dados brutos da imagem PNG para uma Textura SDL
    if (pixelFormat==RGBA5551) newTexture = load_RGBA5551_Texture(imageData,width,height);
    else if (pixelFormat==RGBA4444) newTexture = load_RGBA4444_Texture(imageData,width,height);
    else newTexture = load_RGBA32_Texture(imageData,width,height);
    

    delete[] imageData; // Liberar memória de imageData
    
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
void Resources::clearImagens(){
    for (auto& pair : imagesMap) { // percorre todos os pares do mapa
        delete pair.second; // Libera a memória do BufferedImage*
    }
    imagesMap.clear(); // Remove todas as chaves e valores do mapa
}


unsigned char* Resources::decode_PNG_File(string source, unsigned* width,unsigned* height){
    unsigned char* imageData = nullptr; // dados brutos a serem retornados

    // Lê o arquivo PNG, a partir do arquivo, como um vetor de bytes
    std::ifstream file(source, ios::binary);
    if (!file) std::cerr << "Erro ao abrir o arquivo: " << source << std::endl;
    std::vector<unsigned char> fileData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close(); // fecha o stream de leitura do arquivo

    LodePNGState state; // para armazenar as informações do PNG
    lodepng_state_init(&state);  // Inicializa o estado do LodePNG
    
    // descodifica em RGBA os bytes da imagem carregada
    unsigned error = lodepng_decode(&imageData, width, height, &state, fileData.data(), fileData.size());
    if(error) printf("Erro ao descodificar a imagem PNG %s: %s\n",source.c_str(),lodepng_error_text(error));

    lodepng_state_cleanup(&state); // limpa os dados do estado
    return imageData;
}

SDL_Texture* Resources::load_RGBA32_Texture(unsigned char* imageData,unsigned width,unsigned height){

    SDL_Texture* newTexture = nullptr; // textura a ser retornada
    std::cout << "Formato GRBA8888." << std::endl;
    
    // cria a textura RGBA4444
    newTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
    if (!newTexture) std::cerr << "Erro ao criar a textura SDL: " << SDL_GetError() << std::endl;

    // Atualiza a textura com os dados convertidos
    SDL_UpdateTexture(newTexture, nullptr, imageData, width * 4);

    // Tenta definir o modo de mistura para suportar transparência
    if (SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND) < 0) std::cerr << "Erro ao configurar o blending mode: " << SDL_GetError() << std::endl;

    return newTexture;
}

SDL_Texture* Resources::load_RGBA4444_Texture(unsigned char* imageData,unsigned width,unsigned height){

    SDL_Texture* newTexture = nullptr; // textura a ser retornada
    std::cout << "Formato GRBA4444." << std::endl;
    // Converte a imagem RGBA para o formato RGBA4444
    std::vector<unsigned short> rgba4444Data(width * height);
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x) {
            // Cada pixel na imagem é RGBA (4 bytes por pixel)
            unsigned char r = imageData[(y * width + x) * 4 + 0];  // Red
            unsigned char g = imageData[(y * width + x) * 4 + 1];  // Green
            unsigned char b = imageData[(y * width + x) * 4 + 2];  // Blue
            unsigned char a = imageData[(y * width + x) * 4 + 3];  // Alpha

            // Converte a cor para o formato RGBA4444 (4 bits por canal)
            unsigned short rgba4444 = ((r >> 4) << 12) | ((g >> 4) << 8) | ((b >> 4) << 4) | (a >> 4);
            rgba4444Data[y * width + x] = rgba4444;
        }
    }
    
    // cria a textura RGBA4444
    newTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA4444, SDL_TEXTUREACCESS_STATIC, width, height);
    if (!newTexture) std::cerr << "Erro ao criar a textura SDL: " << SDL_GetError() << std::endl;

    // Atualiza a textura com os dados convertidos
    SDL_UpdateTexture(newTexture, nullptr, rgba4444Data.data(), width * sizeof(unsigned short));

    // Tenta definir o modo de mistura para suportar transparência
    if (SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND) < 0) std::cerr << "Erro ao configurar o blending mode: " << SDL_GetError() << std::endl;

    return newTexture;
}

SDL_Texture* Resources::load_RGBA5551_Texture(unsigned char* imageData, unsigned width, unsigned height){
    SDL_Texture* newTexture = nullptr; // textura a ser retornada
    std::cout << "Formato GRBA5551." << std::endl;
    // Converte a imagem RGBA para o formato RGBA5551
    std::vector<unsigned short> rgba5551Data(width * height);
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x) {
            // Cada pixel na imagem é RGBA (4 bytes por pixel)
            unsigned char r = imageData[(y * width + x) * 4 + 0];  // Red
            unsigned char g = imageData[(y * width + x) * 4 + 1];  // Green
            unsigned char b = imageData[(y * width + x) * 4 + 2];  // Blue
            unsigned char a = imageData[(y * width + x) * 4 + 3];  // Alpha

            // Converte a cor para o formato RGBA5551 (5 bits por canal de cor, 1 bit para alfa)
            unsigned short rgba5551 = ((r >> 3) << 11) | ((g >> 3) << 6) | ((b >> 3) << 1) | (a > 127 ? 1 : 0);
            rgba5551Data[y * width + x] = rgba5551;
        }
    }
    
    // cria a textura RGBA4444
    newTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA5551, SDL_TEXTUREACCESS_STATIC, width, height);
    if (!newTexture) std::cerr << "Erro ao criar a textura SDL: " << SDL_GetError() << std::endl;

    // Atualiza a textura com os dados convertidos
    SDL_UpdateTexture(newTexture, nullptr, rgba5551Data.data(), width * sizeof(unsigned short));

    // Tenta definir o modo de mistura para suportar transparência
    if (SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND) < 0) std::cerr << "Erro ao configurar o blending mode: " << SDL_GetError() << std::endl;

    return newTexture;
}