#include "Player.h"

void Player::init()
{
	string config = CONFIG_FOLDER + "playerCardPos.txt";
	fstream stream;
	string tmp;
	stream.open(config);
	stream >> tmp >> playerCard.rect.x >> playerCard.rect.y >> playerCard.rect.w >> playerCard.rect.h;
	stream.close();

}

void Player::loadPlayerCards()
{
	for (int i = 0; i < 26; i++)
	{
		pCards.push_back(cards[i]);
	}
}
void Player::drawFromDeck()
{
	srand(time(0));
	a = rand() % 26;
	playerCard.texture = pCards[a];
}

SDL_Texture* Player::RemoveFromDeck()
{
	SDL_Texture* tmp = pCards[0];
	pCards.erase(pCards.begin());
	return tmp;
	
	
}

void Player::draw()
{
	drawObject(playerCard);
}
