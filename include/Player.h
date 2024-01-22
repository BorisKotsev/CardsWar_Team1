#pragma once
#include "defines.h"
#include "Presenter.h"
#include<vector>
#include<time.h>
#include<time.h>
#include <stdio.h>      
#include <stdlib.h>   
#include <fstream>
#include <iostream>
#include <algorithm> 
class Player
{
public:
	int currentX = 850;
	int currentY =741;
	vector<int> numsNotAllowed;
	void init();
	void loadPlayerCards(vector<SDL_Texture*> aCards);
	void drawFromDeck();
    SDL_Texture* RemoveFromDeck();
	
	void draw();
	vector<SDL_Texture*> pCards;
	int a = 0; // rand card

	Drawable playerCard;

private:

//>>>>>>> e5922bbc9c882b6a3a70da039d645c46b03456ff
};