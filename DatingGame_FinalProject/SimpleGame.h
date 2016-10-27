#ifndef SIMPLEGAME_H_
#define SIMPLEGAME_H_

#include <SDL.h>
#include <SDL_image.h>

namespace SimpleGame
{
	SDL_Window*     GetWindow(){};
	int             GetWindowWidth();
	int             GetWindowHeight();

	SDL_Renderer*   GetRenderer();

	float           GetTime();
	float           GetTimeSinceLastFrame();

	void            Quit();
}

#endif