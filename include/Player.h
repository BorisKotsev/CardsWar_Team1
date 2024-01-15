#pragma once
#include "defines.h"
#include "Presenter.h"
#include<vector>
#include<time.h>
#include<time.h>
#include <stdio.h>      
#include <stdlib.h>     

class Player
{
public:
	void init();
	void loadPlayerCards();
	void drawFromDeck();
    SDL_Texture* RemoveFromDeck();
	
	void draw();
	vector<SDL_Texture*> pCards;
	int a = 0; // rand card

	Drawable playerCard;

private:

};