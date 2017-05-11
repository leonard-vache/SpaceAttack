#include "Common.h"
#include "GameMgt.h"


int main(int argc, char *argv[])
{
  unsigned int frameLimit = 1000 / FPS;
  srand(time(NULL));
  //atexit(cleanGame);

  if(! initGame()) return EXIT_FAILURE;
  loadGraphics();
  loadGame();

  mainGameLoop(frameLimit);

  cleanGame();
  return EXIT_SUCCESS;
}
