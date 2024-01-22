#pragma once

#include "Engine.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include <vector>
#include <Card.h>
#include <string>
#include "defines.h"
#include "Player.h"

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
	Player player;
private:
	SDL_Texture* m_background;
};