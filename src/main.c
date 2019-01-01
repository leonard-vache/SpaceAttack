#include <time.h>
#include "Common.h"
#include "GameMgt.h"


int main(int argc, char *argv[])
{
  unsigned int frameLimit = 1000 / FPS;
  srand(time(NULL));
  //atexit(Game_clean);

  if(! Game_initSDL()) return EXIT_FAILURE;
  Graphics_loadImages();
  Game_loadObjects();

  Game_mainLoop(frameLimit);

  Game_clean();
  return EXIT_SUCCESS;
}
