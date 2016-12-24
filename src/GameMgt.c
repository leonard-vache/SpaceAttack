#include "GameMgt.h"


SDL_Window* screen = NULL;
SDL_Renderer* renderer = NULL;
/*
Pelement map = NULL;
Pelement ship = NULL;
Pelement fireList = NULL;
Pelement enemy1List = NULL;
*/
int go = 1;


//int adaptToFPS(float value) { return 60 / (round(60.0 * FPS / value) / FPS); }
/*
Pelement getMap() { return map; }

Pelement getFireList() { return fireList; }
void updateFireList(Pelement l) { fireList = l; }

Pelement getEnemy1List() { return enemy1List; }
void updateEnemy1List(Pelement l) { enemy1List = l; }

Pelement getShip() { return ship; }
*/

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
  SDL_Rect r;

  r.x = SCREEN_WIDTH / 2;
  r.y = SCREEN_HEIGHT / 2;
  updateMap( createElement(E_TEXT_BACKGROUND, r, 0, 0, -90.0, NB_BOUNDING_BOX_MAP, setMapBoundingBox) );

  Pelement map2 = getMap();
  if (map2 == NULL)
    printf("Map NULL !!!\n");

  r.x = 300;
  r.y = 600;
  updateShip( createElement(E_TEXT_SHIP, r, SHIP_LINEAR_VELOCITY, SHIP_ANGULAR_VELOCITY, -90.0, NB_BOUNDING_BOX_SHIP, setShipBoundingBox) );
  //ship->bbox.init_bbox = setShipBoundingBox;

  r.x = 300;
  r.y = 30;
  Pelement newEnemy1 = createElement(E_TEXT_ENEMY1, r, ENEMY1_LINEAR_VELOCITY, ENEMY1_ANGULAR_VELOCITY, 90.0, NB_BOUNDING_BOX_ENEMY1, setEnemy1BoundingBox);
  //newEnemy1->bbox.init_bbox = setEnemy1BoundingBox;
  updateEnemy1List(addElement(getEnemy1List(),newEnemy1));
}


void delay(unsigned int frameLimit)
{
  // Gestion des fps (images/stories/seconde)
  unsigned int ticks = SDL_GetTicks();
  unsigned int freq = 1000 / FPS;

  if (frameLimit < ticks)
  {
    printf("Error Scheduling : frameLimit(%d) < ticks(%d). Jitter = %d\n", frameLimit, ticks, ticks - frameLimit);
    return;
  } 

  if (frameLimit > ticks + freq) SDL_Delay(freq);
  else SDL_Delay(frameLimit - ticks);
}


void showBBox(Pelement el)
{
  // Warning polygonsToWorld alloate a pointer on Polygon
  Polygon *poly_el = polygonsToWorld(el);

  int i;
  for(i = 0; i < el->bbox.nb_box; i++)
    drawPolygon( poly_el[i].ul,
                 poly_el[i].ur,
                 poly_el[i].br,
                 poly_el[i].bl 
               );

  free (poly_el);
}


void displayGame(void)
{ 
  // Clean la fenêtre
  SDL_RenderClear(renderer);
  // Affiche les éléments du jeu
  // Draw background
  Pelement map = getMap();
  drawSATexture (map->texture_id, map->pos, map->angle);
  // Draw missiles
  Pelement pl_fire = getFireList();
  while(pl_fire != NULL)
  {
    drawSATexture (pl_fire->texture_id, pl_fire->pos, pl_fire->angle);
    showBBox(pl_fire);
    pl_fire = pl_fire->next;
  }
  // Draw enemies ship
  Pelement pl_en = getEnemy1List();
  while(pl_en != NULL)
  {
    drawSATexture (pl_en->texture_id, pl_en->pos, pl_en->angle);
    showBBox(pl_en);
    pl_en = pl_en->next;
  }
  // Draw gamer ship
  Pelement ship = getShip(); 
  drawSATexture (ship->texture_id, ship->pos, ship->angle);
  //drawElement(getShip());
  showBBox(ship);
  drawExplosion();
  // Set red render for Bounding box dsplay
  SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
  // Update
  SDL_RenderPresent(renderer);
}


void mainGameLoop(int frameLimit)
{
  unsigned int next_frame =  SDL_GetTicks() + frameLimit;
  
  while(go)
  {
    //printf("Tic = %d\n",SDL_GetTicks());
    updateEventManager();
    updateListMotion(getFireList(),updateFireList);
    //enemy1Pattern();
    updateListMotion(getEnemy1List(),updateEnemy1List);
    checkCollisions();
    displayGame();
    //printf("Toc = %d\n",SDL_GetTicks());
    //printf("######################################\n");
    delay(next_frame);
    next_frame = SDL_GetTicks() + frameLimit;  
  }
}



void cleanGame()
{
  cleanGraphics();
  printf("Graphics cleaned\n");
  deleteListOfElement(getFireList());
  deleteListOfElement(getEnemy1List());
  printf("Lists cleaned\n");
  free(getShip());
  free(getMap());
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_DestroyWindow(screen);
  screen = NULL;
  printf("Renderer & Window destroyed\n");

  SDL_Quit();
}
