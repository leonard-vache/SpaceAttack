#include "GameMgt.h"


SDL_Window* screen = NULL;
SDL_Renderer* renderer = NULL;

bool go = 1;

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


void updateListMotion(Pelement pl, ptrFunctionPelement updateList)
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


void circularMotion(Pelement el)
{
  el->angle = fmod(el->angle + el->speed[1],360.f);
}

void sinusoidalMotion(Pelement el)
{
  static double sinusoidal_angle = 0.f;
  double sinusoidal_speed = 6.f;

  el->angle = fmod(el->angle + el->speed[1] * cos(sinusoidal_angle*M_PI/180) ,360.f);

  //printf("sinusoidal_angle=%f - el->speed[1]=%f - el->angle=%f\n",sinusoidal_angle, el->speed[1]*sin(sinusoidal_angle*M_PI/180), el->angle);
  sinusoidal_angle = fmod(sinusoidal_angle + sinusoidal_speed, 360.f);
}


void enemy1Pattern()
{
  Pelement pl_enn = getEnemy1List();
  while(pl_enn != NULL)
  {
    //circularMotion(pl_enn);
    sinusoidalMotion(pl_enn);
    pl_enn = pl_enn->next;
  }
  updateListMotion(getEnemy1List(),updateEnemy1List);
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
  // Warning boundingBoxToWorld alloate pointer
  BoundingBox bbox = boundingBoxToWorld(el->bbox, el->pos);

  int i;
  for(i = 0; i < bbox.nb_box; i++)
    drawPolygon( bbox.box[i].ul,
                 bbox.box[i].ur,
                 bbox.box[i].br,
                 bbox.box[i].bl 
               );

  free (bbox.box);
}


void displayGame(void)
{ 
  // Clean the Window
  SDL_RenderClear(renderer);
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
  showBBox(ship);

  drawExplosion();
  // Set red render for Bounding box dsplay
  SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
  // Update
  SDL_RenderPresent(renderer);
}



void checkCollisions()
{ 
  Pelement ship = getShip();
  updateBoundingBox(&(ship->bbox), ship->angle);

  Pelement pl_enn = getEnemy1List();
  while(pl_enn != NULL)
  {
    updateBoundingBox(&(pl_enn->bbox), pl_enn->angle);
    //Check collision between ship and enemy
    if( isElementsCollision(pl_enn, getShip()) )
    {
      requestExplosion(pl_enn->pos);
      moveElementOutOfRange(pl_enn);
      break;
    }
    // Check Collison entre ennemy and missile
    Pelement pl_fire = getFireList();
    while(pl_fire != NULL)
    {
      updateBoundingBox(&(pl_fire->bbox), pl_fire->angle);
      if(isElementsCollision(pl_fire, pl_enn))
      {
        requestExplosion(pl_enn->pos);
        moveElementOutOfRange(pl_enn);
        moveElementOutOfRange(pl_fire);
        break;
      }
      else 
        pl_fire = pl_fire->next;
    }
    pl_enn = pl_enn->next;
  }
}


void mainGameLoop(int frameLimit)
{
  unsigned int next_frameLimit =  SDL_GetTicks() + frameLimit;
  
  while(go)
  {
    //printf("Tic = %d\n",SDL_GetTicks());
    updateEventManager();
    updateListMotion(getFireList(),updateFireList);
    enemy1Pattern();
    checkCollisions();
    displayGame();
    //printf("Toc = %d\n",SDL_GetTicks());
    //printf("######################################\n");
    delay(next_frameLimit);
    next_frameLimit = SDL_GetTicks() + frameLimit;  
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
