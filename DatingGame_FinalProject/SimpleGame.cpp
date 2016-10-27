//Include Libraries and Headers
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//#include <stdio.h>
#include <iostream>
#include <vector>

#include "LTexture.h"
#include "Dialogue.h"

// declare variables
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Color textColor = { 242, 193, 124 };

TTF_Font *gFont = NULL;
Dialogue dial;

LTexture gBackgroundTexture;
LTexture gBoxTexture;
std::vector<LTexture> gTextLines;
std::vector<LTexture> gPersonTextures; 
std::vector<std::string> para; 
std::vector<int> gPersonDisplay; 

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Displays girls based on the values from the Girls array in Dialogue
void display()
{

	if (dial.getGirls(0) == true)
		gPersonDisplay[0] = 300;
	else
		gPersonDisplay[0] = SCREEN_WIDTH;

	if (dial.getGirls(1) == true)
		gPersonDisplay[1] = 300;
	else
		gPersonDisplay[1] = SCREEN_WIDTH;

	if (dial.getGirls(2) == true)
		gPersonDisplay[2] = 100;
	else
		gPersonDisplay[2] = SCREEN_WIDTH;

	if (dial.getGirls(3) == true)
		gPersonDisplay[3] = 500;
	else
		gPersonDisplay[3] = SCREEN_WIDTH;

	if (dial.getGirls(4) == true)
		gPersonDisplay[4] = 300;
	else
		gPersonDisplay[4] = SCREEN_WIDTH;
 
	if (dial.getGirls(5) == true)
		gPersonDisplay[5] = 300;
	else
		gPersonDisplay[5] = SCREEN_WIDTH;

	for (unsigned i = 0; i < gTextLines.size(); i++){
		gTextLines[i].loadFromRenderedText(para[i], textColor, gFont, gRenderer);
	}
}

void quitGame(){
	//Free resources and close SDL
	//Free loaded images
	gBackgroundTexture.free();
	gBoxTexture.free();

	for (unsigned i = 0; i < gTextLines.size(); i++)
		gTextLines[i].free();

	for (unsigned i = 0; i < gPersonDisplay.size(); i++)
		gPersonTextures[i].free();

	//Free font
	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	const Uint8* keys = NULL;       // pointer to keyboard state managed by SDL
	bool quit = false;

	//Fill all the arrays
	for (unsigned i = 0; i < 5; i++)
	{
		LTexture temp;
		gTextLines.push_back(temp);
	}

	for (unsigned i = 0; i < 6; i++)
	{
		LTexture temp;
		gPersonTextures.push_back(temp);
	}

	for (unsigned i = 0; i < 6; i++)
		gPersonDisplay.push_back(SCREEN_WIDTH);

	//
	// initialize SDL
	//
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "*** Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	//
	// create a window
	//
	gWindow = SDL_CreateWindow("Welcome to GAME!!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!gWindow) {
		std::cout << "*** Failed to create window:" << SDL_GetError() << std::endl;
		return 1;
	}

	//
	// get a pointer to keyboard state managed by SDL
	//
	keys = SDL_GetKeyboardState(NULL);


	//Create Renderers
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!gRenderer) {
		std::cout << "*** Failed to create renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(gWindow);
		return 1;
	}

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	//Open the font
	gFont = TTF_OpenFont("Raleway-Regular.ttf", 25);

	//Render text
	if (!gTextLines[2].loadFromRenderedText("Welcome to the dating game!", textColor, gFont, gRenderer))
	{
		printf("Failed to render text texture!\n");
		//success = false;
	}
	if (!gBackgroundTexture.loadFromFile("media/bar_blurry.png", gRenderer))
	{
		printf("Failed to render background texture!\n");
		//success = false;
	}
	if (!gPersonTextures[0].loadFromFile("media/character4.png", gRenderer))
	{
		printf("Failed to render text texture!\n");
		//success = false;
	}

	if (!gBoxTexture.loadFromFile("media/box.png", gRenderer))
	{
		printf("Failed to render text texture!\n");
		//success = false;
	}

	
	gTextLines[0].loadFromRenderedText("You are at a bar, looking for a good time.", textColor, gFont, gRenderer);
	gTextLines[1].loadFromRenderedText("Press the space bar to continue.", textColor, gFont, gRenderer);
	gTextLines[2].loadFromRenderedText("Get ready to work your magic.", textColor, gFont, gRenderer);
	gTextLines[3].loadFromRenderedText(" ", textColor, gFont, gRenderer);
	gTextLines[4].loadFromRenderedText(" ", textColor, gFont, gRenderer);

	gPersonTextures[1].loadFromFile("media/Couger.png", gRenderer);
	gPersonTextures[2].loadFromFile("media/character3_1.png", gRenderer);
	gPersonTextures[3].loadFromFile("media/character2_2.png", gRenderer);
	gPersonTextures[4].loadFromFile("media/monster1.png", gRenderer);
	gPersonTextures[5].loadFromFile("media/monster2.png", gRenderer);
		
	//While application is running
	while (!quit)
	{
		//variable that receives event information from SDL
		SDL_Event e;    

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
				//If the user selects an option
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

						//If player wins or loses
						if (!para[1].compare("DEAD")){
							quit = true; 
						}
						else if (!para[1].compare("Winner!")){
							quit = true;
						}
					}
					display();
					
						break;
					}
						break;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render current frame
				gBackgroundTexture.render(gRenderer, 0, 0);
				
				for (unsigned i = 0; i < gPersonTextures.size(); i++){
					int defHeight = 50;
					if (i == 3){
						defHeight = 95;
					}
					else if (i == 5 || i == 4)
					{
						defHeight = 150;
					}
					gPersonTextures[i].render(gRenderer, gPersonDisplay[i], defHeight);

					
				}
				gBoxTexture.render(gRenderer, -13, 373);
				for (unsigned i = 0; i < gTextLines.size(); i++)
					gTextLines[i].render(gRenderer, (SCREEN_WIDTH - gTextLines[i].getWidth())/ 2, 430 + (i * 30));

				//Update screen
				SDL_RenderPresent(gRenderer);
			}

	quitGame();

	return 0;
}