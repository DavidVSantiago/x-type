#include "BufferedImage.h"

BufferedImage::BufferedImage(SDL_Texture* texture, int width, int heigth){
    this->texture = texture;
    this->width=width;
    this->heigth=heigth;
}
BufferedImage::~BufferedImage(){}