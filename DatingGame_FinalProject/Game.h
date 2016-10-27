#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "LTexture.h"
#include "Dialogue.h"
#include "System.h"

class Game
{
	std::vector<LTexture> textLines;
	LTexture gBackgroundTexture;
	LTexture gPersonTexture;
	
	std::vector<std::string> para;
	std::vector<int> personDisplays;
	Dialogue dial;
	SDL_Color textColor = { 0, 0, 0 };
	
public:
	Game();
	~Game();

	SDL_Color getColor(){ return textColor; };

	void displayPerson();
	bool initialize();
	void quitGame();
};

#endif