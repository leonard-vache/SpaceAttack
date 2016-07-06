#include "Common.h"
#include "Prototypes.h"
//#include <SDL_image.h>


int main(int argc, char *argv[])
{
  unsigned int frameLimit = SDL_GetTicks() + 1000 / FPS;
  srand(time(NULL));
  //atexit(cleanGame);

  if(! initGame()) return EXIT_FAILURE;
  loadGraphics();
  loadGame();

  mainGameLoop(frameLimit);

  cleanGame();
  return EXIT_SUCCESS;
}
