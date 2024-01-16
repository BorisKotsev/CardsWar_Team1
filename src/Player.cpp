#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>



void Player::init()
{
	playerCount++;	
	int numLines = 0;
	
	string currentString;
	string config = CONFIG_FOLDER + "playerCardPos.txt";
	fstream stream;
	string tmp;
	stream.open(config);
	while (numLines < playerCount) {
		stream >> tmp >> currentStringX >> currentStringY;
		cout << currentStringX << endl;
		cout << currentStringY << endl;
		numLines++;
		
	}
	stream.close();
	
}

void Player::loadPlayerCards(vector<SDL_Texture*> aCards)
{
	for (int i = 0; i < 26; i++)
	{
		pCards.push_back(aCards[i]);
	}
	playerCard.texture = loadTexture(CARD_FOLDER + "B1.bmp");
	playerCard.rect = { stoi(currentStringX), stoi(currentStringY), 200, 300 };
}
void Player::drawFromDeck()
{
	srand(time(0));
	a = rand() % 25 + 1;	
	playerCard.texture = pCards[a];
	playerCard.rect = { stoi(currentStringX), stoi(currentStringY), 200, 300};
	std::cout << a;
}

SDL_Texture* Player::RemoveFromDeck()
{
	if (pCards.empty()) {
		return nullptr; // if empty just return a nullptr
	}

	if (numsNotAllowed.empty()) {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(pCards.begin(), pCards.end(), g); // lets gooooooo shuffling
	}

	a = 0; // whatevs

	if (a < pCards.size()) { // check if its valid index
		playerCard.texture = pCards[a];
		SDL_Texture* removedCard = pCards[a];
		pCards.erase(pCards.begin() + a);
		numsNotAllowed.push_back(a);
		return removedCard; //returning the removed card to compare in a map and find its card value
	}

	return nullptr; // handle the nullz
}





void Player::draw()
{
	drawObject(playerCard);
}
