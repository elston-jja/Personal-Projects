#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>


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

// Shuts down SDL
void close();



// Load Window to render to
SDL_Window* gWindow = NULL;

// The surface contained within the window
SDL_Surface* gScreenSurface = NULL;

// The images that correspond to keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

// Current Displayed image
SDL_Surface* gCurrentSurface = NULL;



SDL_Surface* loadSurface(std::string path){
  
  // Load image at specified path
  SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str());

  if (loadedSurface == NULL) {
    printf("Unable tho load the image %s, SDL ERROR: %s\n",path.c_str(), SDL_GetError() );
  }
  
  return loadedSurface;
}


int main(int argc, char *argv[])
{

  if (!init()){
    printf("Failed to initilize!\n");
    
  }
  else{

    if (!loadMedia()){

      printf( "Failed to load media!\n" );
    }
    else{

    // Main loop flag
    bool quit = false;

    SDL_Event e;

    while (!quit){

      // Handle events
      while (SDL_PollEvent( &e ) != 0){

	// User requests to quit
	if(e.type == SDL_QUIT){
	  quit  = true;
	}
	
	// Check if key is pressed
	else if (e.key.keysym.sym) {

	  // Select surfaces based of keys
	  switch (e.key.keysym.sym){

	  default:
	    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
	    break;

	  case SDLK_DOWN:
	    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
	    break;
	    
	  case SDLK_UP:
	    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
	    break;

	  case SDLK_LEFT:
	    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
	    break;

	  case SDLK_RIGHT:
	    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
	    break;
	  }

	  
	}
      }
      
      // Apply the image
      SDL_BlitSurface (gCurrentSurface, NULL, gScreenSurface, NULL);
      
      // Update the surface
      SDL_UpdateWindowSurface(gWindow);  
      
    }
    }
  }

  close();
return 0;
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
    else{
      gScreenSurface = SDL_GetWindowSurface( gWindow);
    }
  }
  return success;
}


bool loadMedia(){

  // Success Flag
  bool success = true;

  /* Load the different keysurface images */
  
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface("keys/press.bmp");
  if (gKeyPressSurfaces [ KEY_PRESS_SURFACE_DEFAULT ] == NULL){
    printf("Failed to load default image\n");
    success = false;
  }

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface("keys/up.bmp");
  if (gKeyPressSurfaces [ KEY_PRESS_SURFACE_UP ] == NULL){
    printf("Failed to load default image\n");
    success = false;
  }
  
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface("keys/down.bmp");
  if (gKeyPressSurfaces [ KEY_PRESS_SURFACE_DOWN ] == NULL){
    printf("Failed to load default image\n");
    success = false;
  }
  
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface("keys/left.bmp");
  if (gKeyPressSurfaces [ KEY_PRESS_SURFACE_LEFT ] == NULL){
    printf("Failed to load default image\n");
    success = false;
  }
  
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface("keys/right.bmp");
  if (gKeyPressSurfaces [ KEY_PRESS_SURFACE_RIGHT ] == NULL){
    printf("Failed to load default image\n");
    success = false;
  }
  
  return success;
}


void close(){

  // Deallocate the surface
  SDL_FreeSurface( gCurrentSurface);
  gCurrentSurface = NULL;

  // Destroy the window
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
    
}

