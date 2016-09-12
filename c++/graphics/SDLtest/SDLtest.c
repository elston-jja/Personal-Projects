#include <SDL/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if(SDL_Init(SDL_INIT_VIDEO) != 0)

    fprintf(stderr, "could not initialize SDL: %s\n", SDL_GetError()); // Error

  printf("SDL Initialized\n");

  SDL_Quit();
  
  printf("SDL Shutdown\n");

  return 0;
}
