#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include "sdlw.h"

SDL_Surface* surface;
SDLWrapper sdl;

int main()
{
	bool quit = false;
	SDL_Event e;

	sdl.Window( 640, 480, -1, -1, 0,"test", surface);
	while (!quit)
	{

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

		}
		SDL_SetRenderDrawColor(sdl.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		sdl.renderClear();
		sdl.refresh();
		
	}
	return 0;
}

