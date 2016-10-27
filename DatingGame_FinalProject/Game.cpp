#include "Game.h"

Game::Game():
textLines(), gBackgroundTexture(), gPersonTexture(), personDisplays(), para(), dial()
{
	for (unsigned i = 0; i < 5; i++)
	{
		LTexture temp;
		textLines.push_back(temp);
	}

	for (unsigned i = 0; i < 5; i++)
		personDisplays.push_back(800);
}


Game::~Game()
{
}

bool Game::initialize()
{
	//Get renderer
	SDL_Renderer* renderer = System::getRenderer();
	
	TTF_Font* font = System::getGameFont();

	//Render text
	if (!textLines[2].loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor, font, renderer))
	{
		printf("Failed to render text texture!\n");
		//success = false;
	}
	if (!gBackgroundTexture.loadFromFile("media/bar_blurry.png", renderer))
	{
		printf("Failed to render background texture!\n");
		//success = false;
	}
	if (!gPersonTexture.loadFromFile("media/blank.png", renderer))
	{
		printf("Failed to render text texture!\n");
		//success = false;
	}

	textLines[3].loadFromRenderedText("Line 4", getColor(), font, renderer);
	textLines[4].loadFromRenderedText("Line 5", getColor(), font, renderer);
	textLines[0].loadFromRenderedText("Line 1", getColor(), font, renderer);
	textLines[1].loadFromRenderedText("Line 2", getColor(), font, renderer);

}

void Game::displayPerson()
{
	if (dial.getGirls(0) == true)
		personDisplays[0] = 400;
	else
		personDisplays[0] = 600;

	if (dial.getGirls(1) == true)
		personDisplays[0] = 400;
	else
		personDisplays[0] = 600;

	if (dial.getGirls(2) == true)
		personDisplays[0] = 400;
	else
		personDisplays[0] = 600;

	if (dial.getGirls(3) == true)
		personDisplays[0] = 400;
	else
		personDisplays[0] = 600;

	SDL_Renderer* renderer = System::getRenderer();

	TTF_Font* font = System::getGameFont();

	textLines[0].loadFromRenderedText(para[0], getColor(), font, renderer);
	textLines[1].loadFromRenderedText(para[1], getColor(), font, renderer);
	textLines[2].loadFromRenderedText(para[2], getColor(), font, renderer);
	textLines[3].loadFromRenderedText(para[3], getColor(), font, renderer);
	textLines[4].loadFromRenderedText(para[4], getColor(), font, renderer);
}

void Game::quitGame(){
	//Free resources and close SDL
	//Free loaded images
	gBackgroundTexture.free();
	gPersonTexture.free();
	textLines[0].free();
	textLines[1].free();
	textLines[2].free();
	textLines[3].free();
	textLines[4].free();

	//Free font
	TTF_CloseFont(System::getGameFont());

	//Destroy window	
	SDL_DestroyRenderer(System::getRenderer());
	SDL_DestroyWindow(System::getWindow());

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

