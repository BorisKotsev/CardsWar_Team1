#include "Engine.h"

SDL_Texture* LoadTexture(string imgPath, SDL_Renderer* renderer)
{
	string tmpImg = IMG_FOLDER + imgPath;

	SDL_Surface* loadingSurface = SDL_LoadBMP(tmpImg.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);

	if (texture == nullptr)
	{
		std::cerr << "FAILURE LOADING TEXTURE!!!!!!!" << endl;
		std::cout << imgPath;
		
		tmpImg = "img\\Null.bmp";

		loadingSurface = SDL_LoadBMP(tmpImg.c_str());

		texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);
	}

	SDL_FreeSurface(loadingSurface);

	return texture;
}

bool isMouseInRect(int2 mouseCoor, SDL_Rect rect)
{
	SDL_Point mousePosiiton = { mouseCoor.x, mouseCoor.y };
	if (SDL_PointInRect(&mousePosiiton, &rect)) {
		return true;
	}

	return false;
}

bool collRectRect(SDL_Rect rect1, SDL_Rect rect2)
{
	if (rect1.x + rect1.w < rect2.x || rect1.x > rect2.x + rect2.w || rect1.y + rect1.h < rect2.y || rect1.y > rect2.y + rect2.h)
	{
		return false;
	}
	else
	{
		return true;
	}
}