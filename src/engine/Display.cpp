#include "Display.h"
#include <iostream>

/* CONSTRUTORES E DESTRUTORES --------------------------------------*/
Display::Display(uint16_t width, uint16_t height):screenWidth(width),screenHeight(height){    
    updateDisplayScale(); // faz os calculos de escalonamento da tela
}


Display::~Display(){
    SDL_DestroyWindow(window);
}

void Display::setFullScreen(bool fullScreen){
    if(fullScreen){
        isFullscreen = true;
        updateDisplayScale();
        // Alternar para "fake fullscreen"
        SDL_SetWindowFullscreen(window, SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_SetWindowSize(window, displayWidth, displayWidth);
        // cout << "tela cheia: " << displayWidth << "x" << displayHeight << endl;
    }else{
        isFullscreen = false;
        updateDisplayScale();
        // Alternar para modo janela
        SDL_SetWindowFullscreen(window, 0); // Remove fullscreen
        SDL_SetWindowSize(window, displayWidth, displayHeight);
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        SDL_SetWindowBordered(window, SDL_TRUE);
        // cout << "janela: " << displayWidth << "x" << displayHeight << endl;
    }
}

void Display::updateDisplayScale(){
    // obtém as dimensões da janela
    if(isFullscreen){
        if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) cerr << "Erro ao obter a resolução da tela! Erro: " << SDL_GetError() << endl;
        displayWidth = displayMode.w;
        displayHeight = displayMode.h;
    }else{
        displayWidth = screenWidth;
        displayHeight = screenHeight;
    }

    // Calcula o fator de escala para crescer a tela para a tela cheia
    float scaleWidth = static_cast<float>(displayWidth) / screenWidth;
    float scaleHeight = static_cast<float>(displayHeight) / screenHeight;
    scaleRatio = (scaleWidth < scaleHeight) ? scaleWidth : scaleHeight; // a menor das duas escalas (para caber no display)

    // Calcula o tamanho das novas dimensões de desenho (preservando a proporção)
    drawWidth = static_cast<uint16_t>(screenWidth * scaleRatio);
    drawHeight = static_cast<uint16_t>(screenHeight * scaleRatio);

    // formula para calcular a nova origem, afastando o letterbox à esquerda.
    drawOriginX = (displayWidth - drawWidth) / 2;
    drawOriginY = (displayHeight - drawHeight) / 2;

    scaled_destArray = new SDL_Rect();
    scaled_destArray->x=drawOriginX;
    scaled_destArray->y=drawOriginY;
    scaled_destArray->w=drawWidth;
    scaled_destArray->h=drawHeight;
}