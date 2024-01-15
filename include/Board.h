#pragma once

#include "Engine.h"

//dali raboti?

class Board
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void destroy();

private:
	SDL_Texture* m_background;
};