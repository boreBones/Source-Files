#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "Game.h"

namespace System
{
	SDL_Window*     getWindow(){};
	int             getWindowWidth();
	int             getWindowHeight();
	TTF_Font*		getGameFont();
	//SDL_Color*		getColor();

	SDL_Renderer*   getRenderer();
	const Uint8*    getKeyStates();

	//void            quit();
}

#endif