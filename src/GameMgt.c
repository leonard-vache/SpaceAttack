#include "GameMgt.h"


SDL_Window* screen = NULL;
SDL_Renderer* renderer = NULL;
Pelement map = NULL;
Pelement ship = NULL;
Pelement fireList = NULL;
Pelement enemy1List = NULL;
int go = 1;


//int adaptToFPS(float value) { return 60 / (round(60.0 * FPS / value) / FPS); }

Pelement getMap() { return map; }

Pelement getFireList() { return fireList; }
void updateFireList(Pelement l) { fireList = l; }

Pelement getEnemy1List() { return enemy1List; }
void updateEnemy1List(Pelement l) { enemy1List = l; }

Pelement getShip() { return ship; }

void stopGame() { go = 0; }

SDL_Renderer *getRenderer() { return renderer; }


int initGame()
{
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 
  { 
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); 
    return 0; 
  }

  screen = SDL_CreateWindow("Space Attack",                   // Title
                            SDL_WINDOWPOS_CENTERED,           // Window Position X
                            SDL_WINDOWPOS_CENTERED,           // Window Position Y
                            SCREEN_WIDTH, SCREEN_HEIGHT,      // Sreen width and height
                            SDL_WINDOW_OPENGL);               // SDL Flag
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);
  if(screen == NULL || renderer == NULL)
  {
    printf( "SDL could not create window or renderer! SDL_Error: %s\n", SDL_GetError() ); 
    return 0;
  }

  return 1;
}

void updateListMotion(Pelement pl, ptrFunction updateList)
{
  Pelement pl_prev = pl;
  Pelement pl_to_free;

  while(pl != NULL)
  {
    if (pl->pos.y > SCREEN_HEIGHT + pl->pos.h || pl->pos.y < 0 ||
        pl->pos.x > SCREEN_WIDTH + pl->pos.w  || pl->pos.x < 0)
    {
      // First element of the list
      if(pl_prev == pl)
      {
        pl_prev = pl->next;
        // Call adapted function to update
        updateList(pl_prev);
      }
      else
      {
        // Link previous element with next one
        pl_prev->next = pl->next;
      }
      pl_to_free = pl;
      pl = pl->next;
      free(pl_to_free);
    }
    else
    {
      pl->pos.y += sin(pl->angle*M_PI/180) * pl->speed[0];
      pl->pos.x += cos(pl->angle*M_PI/180) * pl->speed[0];
      pl_prev = pl;
      pl = pl->next;
    }
  }
}

// Durty... To rework !
void enemy1Pattern()
{
  Pelement pl_enn = getEnemy1List();
  static positif = 0;
  static int turn_left=0;
  static int turn_right=1;
  while(pl_enn != NULL)
  {
    int x = pl_enn->pos.x;
    int y = pl_enn->pos.y;
    if (x < SCREEN_WIDTH / 7 && turn_left == 0) turn_left = 1;
    if (turn_left == 1)
    {
        if(pl_enn->angle <= 0 ) 
        {
          pl_enn->angle = 0;
          turn_left=2;
          turn_right=0;
        }
        else 
          pl_enn->angle -= pl_enn->speed[1];
    }
    
    if (x > 6 * SCREEN_WIDTH / 7 && turn_right == 0) turn_right = 1;
    if (turn_right == 1)
    {
        if(pl_enn->angle >= 180 )
        {
          pl_enn->angle = 180;
          turn_left=0;
          turn_right=2;
        } 
        else pl_enn->angle += pl_enn->speed[1];
    }
   // printf("enn angle = %d\n",pl_enn->angle);
    pl_enn = pl_enn->next;
  }
}


void loadGame() 
{
  SpaceAttack_Texture spTxt = getSPTexture();
  SDL_Rect r;

  r.x = SCREEN_WIDTH / 2;
  r.y = SCREEN_HEIGHT / 2;
  map = create(spTxt.background, r, 0, 0, -90.0, NB_BOUNDING_BOX_MAP, setMapBoundingBox);

  r.x = 300;
  r.y = 600;
  ship = create(spTxt.ship, r, SHIP_LINEAR_VELOCITY, SHIP_ANGULAR_VELOCITY, -90.0, NB_BOUNDING_BOX_SHIP, setShipBoundingBox);
  //ship->bbox.init_bbox = setShipBoundingBox;

  r.x = 300;
  r.y = 30;
  Pelement newEnemy1 = create(spTxt.enemy1, r, ENEMY1_LINEAR_VELOCITY, ENEMY1_ANGULAR_VELOCITY, 0.0, NB_BOUNDING_BOX_ENEMY1, setEnemy1BoundingBox);
  //newEnemy1->bbox.init_bbox = setEnemy1BoundingBox;
  updateEnemy1List(add(getEnemy1List(),newEnemy1));
}


void delay(unsigned int frameLimit)
{
  // Gestion des fps (images/stories/seconde)
  unsigned int ticks = SDL_GetTicks();
  unsigned int freq = 1000 / FPS;

  if (frameLimit < ticks) return;

  if (frameLimit > ticks + freq) SDL_Delay(freq);
  else SDL_Delay(frameLimit - ticks);
}


void drawGame(void)
{ 
  // Clean la fenêtre
  SDL_RenderClear(renderer);
  // Affiche les éléments du jeu
  drawGraphics();
  // Actualise
  SDL_RenderPresent(renderer);
  // Délai pour laisser respirer le proc
  SDL_Delay(1);
}


void mainGameLoop(int frameLimit)
{
  unsigned int freq = 1000 / FPS;

  while(go)
  {
    updateEventManager();
    updateListMotion(getFireList(),updateFireList);
    //enemy1Pattern();
    //updateListMotion(getEnemy1List(),updateEnemy1List);
    checkCollisions();
    drawGame();
    delay(frameLimit);
    frameLimit = SDL_GetTicks() + freq;
  }
}



void cleanGame()
{
  cleanGraphics();
  printf("Graphics clean\n");
  delete_all(fireList);
  delete_all(enemy1List);
  printf("List Clean\n");
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_DestroyWindow(screen);
  screen = NULL;

  SDL_Quit();
}
