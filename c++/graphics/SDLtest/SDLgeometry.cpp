#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <string>

// Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Key press surfaces constants
enum KeyPressSurfaces{
  KEY_PRESS_SURFACE_DEFAULT,
  KEY_PRESS_SURFACE_UP,
  KEY_PRESS_SURFACE_DOWN,
  KEY_PRESS_SURFACE_LEFT,
  KEY_PRESS_SURFACE_RIGHT,
  KEY_PRESS_SURFACE_TOTAL
};

// Starts SDL
bool init();

// Load media to display on the screen
bool loadMedia();

// Loads the individual textures
SDL_Texture* loadTexture( std::string path);

// Shuts down SDL
void close();


// Load Window to render to
SDL_Window* gWindow = NULL;

// The surface contained within the window
SDL_Surface* gScreenSurface = NULL;

// Current Displayed image
SDL_Surface* gCurrentSurface = NULL;

// The window renderer
SDL_Renderer* gRenderer = NULL;

// Current displayed texture
SDL_Texture* gTexture = NULL;

// // Drawing Texture
// SDL_Texture* gDraw = NULL;



// main()
int main(int argc, char *argv[])
{

  if (!init())
    {
      printf("Failed to initilize!\n");
    
    }
  else
    {
      printf("Main loaded\n");

      if (!loadMedia())
	{
	  printf( "Failed to load media!\n" );
	}
      
      else
	{
	  printf("Media Loaded\n");
	  // Main loop flag
	  bool quit = false;
      
	  SDL_Event e;
      
	  while (!quit)
	    {
	
	      // Handle events
	      while (SDL_PollEvent( &e ) != 0)
		{
		  
		  // User requests to quit
		  if(e.type == SDL_QUIT)
		    {
		      quit  = true;
		    }
		}

	      
	      SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	      SDL_RenderClear(gRenderer);

	      // Render red filled quad
	      SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT /4, SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
	      SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	      SDL_RenderFillRect(gRenderer, &fillRect);


	      // Render green outline quad
	      SDL_Rect outlineRect = {SCREEN_WIDTH/6, SCREEN_HEIGHT/6, SCREEN_WIDTH *2/3, SCREEN_HEIGHT *2/3};
	      SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	      SDL_RenderDrawRect(gRenderer, &outlineRect);

	      //Draw vertical line

	      SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	      for (int i = 0; i < SCREEN_HEIGHT; i+=4 )
		{
		  SDL_RenderDrawLine(gRenderer, 0 , 0 + i, SCREEN_WIDTH,0+i );
		}
	      for (int i = 0; i < SCREEN_WIDTH; i+=4 )
		{
		  SDL_RenderDrawLine(gRenderer, 0 + i, 0, 0+i, SCREEN_HEIGHT );
		}
	      
	      // Render the Screen
	      SDL_RenderPresent(gRenderer);
	      
	    }
	}
    }

  close();
  return 0;
}


SDL_Texture* loadTexture( std::string path){

  // The final texture
  SDL_Texture* newTexture = NULL;

  // Load Image at specified path
  SDL_Surface* loadedSurface = IMG_Load( path.c_str());

  if (loadedSurface == NULL) {
    printf("Unable to load the surface, IMAGE: %s SDL ERROR: %s\n", path.c_str(), SDL_GetError());
  }
  else{

    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture form the suface provided SDL ERROR: %s\n", SDL_GetError());
    }
    // Get rid of the loaded surface
    SDL_FreeSurface(loadedSurface);
  }
  return newTexture;
}


bool init(){

  // Value to return
  bool success = true;

  if ( SDL_Init( SDL_INIT_VIDEO ) < 0){
    printf("SDL could not initialize! SDL ERROR: %s\n", SDL_GetError());
    success = false;
    
  }
  else {

    // Create the window
    gWindow = SDL_CreateWindow("Testing",
			       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			       SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);    
    if (gWindow == NULL) {

      printf("Window could not be created SDL ERROR: %s \n", SDL_GetError());
      success = false;
    }
    else {
      
      // Create renderer for window
      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

      if (gRenderer == NULL) {
	printf("Renderer could not be created SDL ERROR %s\n",SDL_GetError() ); 
      }
      else {

	// Set renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	// Inialize PNG Loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags)&imgFlags)) {
	  printf("The image could not be initialized ERROR: %s\n", IMG_GetError());
	  success = false;
	}
	else {
	  
	  gScreenSurface = SDL_GetWindowSurface( gWindow);
	  
	}
      }
    }
  }
  return success;
}


bool loadMedia(){

  // Success Flag
  bool success = true;
  
  return success;
}


void close(){

  // Deallocate the surface
  SDL_FreeSurface( gCurrentSurface);
  gCurrentSurface = NULL;  

  // Destroy texture
  SDL_DestroyTexture(gTexture);
  gTexture = NULL;
  
  // Destroy the window
  SDL_DestroyWindow( gWindow);
  gWindow = NULL;
  
  IMG_Quit();
  SDL_Quit();
    
}


