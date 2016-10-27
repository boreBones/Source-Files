#include <iostream>

#include "System.h"
#include "Game.h"

namespace
{
	SDL_Window*     g_Window = NULL;
	int             g_WindowWidth = 0;
	int             g_WindowHeight = 0;

	TTF_Font*		g_Font = NULL;

	SDL_Renderer*   g_Renderer = NULL;
	const Uint8*    g_KeyStates = NULL;

	Game	mainGame;

}

namespace System
{
	SDL_Window* getWindow()
	{
		return g_Window;
	}

	int getWindowWidth()
	{
		return g_WindowWidth;
	}

	int getWindowHeight()
	{
		return g_WindowHeight;
	}

	SDL_Renderer* getRenderer()
	{
		return g_Renderer;
	}

	const Uint8* getKeyStates()
	{
		return g_KeyStates;
	}

	TTF_Font* getGameFont(){
		return g_Font;
	}


}

int main(int argc, char* args[])
{

	//
	// initialize SDL
	//
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "*** Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//
	// initialize SDL_image library
	//
	if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) {
		std::cerr << "*** Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//
	// create a window
	//
	g_WindowWidth = 800;
	g_WindowHeight = 600;
	g_Window = SDL_CreateWindow("Hello!",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		g_WindowWidth, g_WindowHeight,
		SDL_WINDOW_SHOWN);
	if (!g_Window) {
		std::cerr << "*** Failed to create window: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//
	// get a pointer to keyboard state managed by SDL
	//
	g_KeyStates = SDL_GetKeyboardState(NULL);


	//Create Renderers
	g_Renderer = SDL_CreateRenderer(g_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!g_Renderer) {
		std::cerr << "*** Failed to create renderer: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//Background Colour
	SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	//Initilize True Type Font
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	g_Font = TTF_OpenFont("Raleway-Regular.ttf", 25);

	if (!mainGame.initialize()) {
		std::cerr << "*** Game initialization failed" << std::endl;
		return EXIT_FAILURE;
	}


	//Main loop flag
	bool quit = false;

	//While application is running
	while (!quit)
	{
		SDL_Event e;    // structure that receives event information from SDL

		//Handle events on queue
		while (SDL_PollEvent(&e))
		{
			switch (e.type) {
			case SDL_QUIT:
				printf("User closed the window\n");
				quit = true;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					printf("User pressed Escape\n");
					quit = true;  // set quit flag
					break;
				case SDLK_1:
					if (dial.getQuestAsked() && (dial.getAnswer() == 0)){
						dial.setAnswer(1);
						para = dial.quest();
						display();
					}
					break;
				case SDLK_2:
					if (dial.getQuestAsked() && (dial.getAnswer() == 0)){
						dial.setAnswer(2);
						para = dial.quest();
						display();
					}
					break;
				case SDLK_SPACE:
					if (dial.getQuestAsked() == false){
						para = dial.convo();
					}

					//std::cout << text << std::endl;

					display();

					break;
				}
				break;
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(g_Renderer);

		//Render current frame
		gBackgroundTexture.render(g_Renderer, 0, 0);
		gPersonTexture.render(g_Renderer, personDisplay, 50);
		textLines[0].render(g_Renderer, 25, 430);
		textLines[1].render(g_Renderer, 25, 460);
		textLines[2].render(g_Renderer, 25, 490);
		textLines[3].render(g_Renderer, 25, 520);
		textLines[4].render(g_Renderer, 25, 550);

		//gTextLn3.render(g_Renderer, (SCREEN_WIDTH - gTextLn3.getWidth()) / 2, 425);


		//Update screen
		SDL_RenderPresent(g_Renderer);
	}
	//}
	//}

	mainGame.quitGame();

	return 0;
}