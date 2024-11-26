#include "BufferedImage.h"

//---------------------------------------------------------------------------------------------------------
// CONSTRUTORES E DESTRUTORES
//---------------------------------------------------------------------------------------------------------
BufferedImage::BufferedImage(SDL_Texture* texture, int width, int height){
    this->texture = texture;
    this->width=width;
    this->height=height;
}
BufferedImage::~BufferedImage(){}