#include "BufferedImage.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
BufferedImage::BufferedImage(SDL_Texture* texture, uint16_t width, uint16_t height){
    this->texture = texture;
    this->width=width;
    this->height=height;
}
BufferedImage::~BufferedImage(){}