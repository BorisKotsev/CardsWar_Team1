#pragma once

#include "Engine.h"

class Card
{


public:
    Card();
    ~Card();

    void init();
    void changeTexture();
    void draw();
    void destroy();

    Drawable card;
private:


    SDL_Texture* Cardback;
    SDL_Texture* Cardfront;


};