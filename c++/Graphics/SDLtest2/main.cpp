#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "texture.h"

bool initialize();
bool loadMedia();
void drawShapes();
void destroy();
SDL_Texture* loadTexture(std::string path);

SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gScreenSurface = NULL;
LTexture gFooTexture;
LTexture gBackgroundTexture;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() 
{
	if (!(initialize()))
	{
		printf("Could not initialize SDL\n");
	}
	else
	{
		if ( !(loadMedia()))
		{
			printf("Could not initialize media\n");
		}
		else
		{
			bool quit = false;

			SDL_Event e;

			while(!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				// Fill screen color white and cleat the renderer
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				// Reset the viewpoint
				SDL_RenderSetViewport(gRenderer, NULL);

				gBackgroundTexture.render(0,0);
				gFooTexture.render(5,190);
				
				
				// Draws shapes using geometry
				drawShapes();
				
				// Refresh the screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	return 0;
}

bool initialize()
{
	bool success = true;
	printf("Starting SDL...\n");
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("SDL could not be initialized | SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Project 0",
								   SDL_WINDOWPOS_UNDEFINED,
								   SDL_WINDOWPOS_UNDEFINED,
								   SCREEN_WIDTH,
								   SCREEN_HEIGHT,
								   SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("The window could not be created | SDL Error: %s\n",SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

			if (gRenderer == NULL)
			{
				printf("Could not create renderer | SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;

				if ( !(IMG_Init(imgFlags)&imgFlags))
				{
					printf("The images could not be initialized | IMG Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					gScreenSurface = SDL_GetWindowSurface( gWindow );
				}
			}
		}
	}	
	return success;
}

bool loadMedia()
{
	bool success = true;
	printf("Loading media\n");
	
	if (!gFooTexture.loadFromFile("texture.png"))
	{
		printf("Failed to load image from file\n");
		success = false;
	}

	if (!gBackgroundTexture.loadFromFile("texture1.png"))
	{
		printf("Failed to load image from file\n");
		success = false;
	}
		
	return success;
}

void destroy()
{
	// DEALLOCATE POINTERS
	
	SDL_FreeSurface(gCurrentSurface);
	gCurrentSurface = NULL;

	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	gFooTexture.free();
	gBackgroundTexture.free();

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	
	if (loadedSurface == NULL)
	{
		printf("Could not load image %s SDL ERROR: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface);

		if (newTexture == NULL)
		{
			printf("Failed to create texture\n");
		}

		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

void drawShapes()
{
	// Draw filled yellow rectangle
	SDL_Rect fillRect =
		{
			SCREEN_WIDTH /4,SCREEN_HEIGHT /4, SCREEN_WIDTH /2, SCREEN_HEIGHT/2	
		};
	SDL_SetRenderDrawColor(gRenderer, 0xFF,0xFF,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);

	// Draw Diagonal line
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0x00);
	SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
	
}

LTexture :: LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path)
{
	// Get rid of pre-existing texture
	free();

	// The final Texture
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
// Load image from suface
	if (loadedSurface == NULL)
	{
		printf("Could not load the image | SDL Error: %s\n",SDL_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format,0, 0xFF, 0xFF));

		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

		if (newTexture == NULL)
		{
			printf("The texture could not be created | SDL Error %s\n", SDL_GetError());
		}
		else
		{
			// Dimentions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	// success and new texture
	mTexture = newTexture;
	return mTexture != NULL;
	
}

void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y )
{
	// Set render spacing and render on the screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight};
	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
