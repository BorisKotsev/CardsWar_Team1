#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>



void Player::init()
{
/*	int numLines = 0;
	
	string currentString;
	string config = CONFIG_FOLDER + "playerCardPos.txt";
	fstream stream;
	string tmp;
	stream.open(config);
	while (numLines < playerCount) {
		stream >> tmp >> currentX >> currentY;
		cout << currentX << endl;
		cout << currentY << endl;
		numLines++;
		
	}
	stream.close();*/ //mai ne ni trqbva
	if (playerCount == 1)
		currentY -= 400;
	playerCount++;	
}

void Player::loadPlayerCards(vector<SDL_Texture*> aCards)
{
	for (int i = 0; i < 26; i++)
	{
		pCards.push_back(aCards[i]);
		aCards.erase(aCards.begin()+i);
	}
	playerCard.texture = loadTexture(CARD_FOLDER + "B1.bmp");
	playerCard.rect = { currentX, currentY, 200, 300 };

	// lets gooooooo shuffling
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(pCards.begin(), pCards.end(), g);
}
void Player::drawFromDeck()
{
	playerCard.texture = pCards[0];
	playerCard.rect = {currentX, currentY, 200, 300};
}

SDL_Texture* Player::RemoveFromDeck()
{
	if (pCards.empty()) {
		return nullptr; // if empty just return a nullptr
	}

	//if (a < pCards.size()) { // check if its valid index
		playerCard.texture = pCards[0];
		SDL_Texture* removedCard = pCards[0];
		pCards.erase(pCards.begin());
		return removedCard; //returning the removed card to compare in a map and find its card value
	//}

	//return nullptr; // handle the nullz
}





void Player::draw()
{
	drawObject(playerCard);
}
