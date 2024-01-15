#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include <vector>
#include <Card.h>
#include <string>
#include "defines.h"
std::vector<SDL_Texture*> cards = {};
Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	
	
	string configFile = "boardInit.txt";

	fstream stream;

	string backgorundImg, tmp;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;

	stream.close();

	m_background = loadTexture(backgorundImg);

	string of_clubs = "_of_clubs";
	string of_hearts = "_of_hearts";
	string of_diamonds = "_of_diamonds";
	string of_spades = "_of_spades";
	string currentString = "";

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			currentString = of_clubs;
			
		}
		if (i == 1) {
			currentString = of_hearts;
		}
		if (i == 2) {
			currentString = of_diamonds;
		}
		if (i == 3) {
			currentString = of_spades;
		}
		for (int z = 2; z < 15; z++) {
			string texture_string = to_string(z) + currentString + ".bmp";
			
			if(z > 10){
				switch (z) {
				default:
					break;

				case 11:
					texture_string = "ace" + currentString + ".bmp";
					break;
				case 12:
					texture_string = "jack" + currentString + ".bmp";
					break;
				case 13:
					texture_string = "king" + currentString + ".bmp";
					break;
				case 14:
					texture_string = "queen" + currentString + ".bmp";
					break;
				}
			
			}
			SDL_Texture* texture = loadTexture(CARD_FOLDER + texture_string);
			cards.push_back(texture);
			std::cout << cards.size() << endl;
			std::cout << texture_string << endl;
		}
	
		
	}


}

void Board::update()
{
	
}

void Board::draw()
{
	drawObject(m_background);
	
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);
}