#include "GameMgt.h"


SDL_Window   *screen = NULL;
SDL_Renderer *renderer = NULL;

static bool   go    = 1;

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
                            SDL_WINDOWPOS_CENTERED,           // Window mov.position X
                            SDL_WINDOWPOS_CENTERED,           // Window mov.position Y
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



void enemy1Pattern()
{
  Pelement pl_enn = getEnemy1List();
  Pelement ship = getShip();
  while(pl_enn != NULL)
  {
    //circularPattern(&pl_enn->mov);
    //sinusoidalPattern(&pl_enn->mov);
    //followerPattern(ship->mov, &pl_enn->mov);

    pl_enn = pl_enn->next;
  }
}



void loadGame() 
{
  SA_Rect r;

  r.x = SCREEN_WIDTH / 2;
  r.y = SCREEN_HEIGHT / 2;
  updateMap( createElement( E_TEXT_BACKGROUND, 
                            r, 0, 0, -90.0, 
                            0,
                            NB_BOUNDING_BOX_MAP, setMapBoundingBox
                          ) 
           );

  r.x = SCREEN_WIDTH / 2;
  r.y = SCREEN_HEIGHT - 50;
  updateShip( createElement( E_TEXT_SHIP, 
                             r, SHIP_LINEAR_VELOCITY, SHIP_ANGULAR_VELOCITY, -90.f, 
                             SHIP_LIFE,
                             NB_BOUNDING_BOX_SHIP, setShipBoundingBox
                           ) 
            );
  //ship->bbox.init_bbox = setShipBoundingBox;
  Pelement ship = getShip();
  ship->weapon.desc[E_WEAPON_MAIN].weaponTexture = E_TEXT_SHIP_MAIN_FIRE;
  ship->weapon.desc[E_WEAPON_MAIN].setWeaponBBox = setShipFireBoundingBox;
  ship->weapon.desc[E_WEAPON_MAIN].damage        = SHIP_FIRE_DAMAGE;
  ship->weapon.desc[E_WEAPON_MAIN].fireRate      = SHIP_FIRE_RATE;
  ship->weapon.desc[E_WEAPON_MAIN].fireSpeed     = SHIP_FIRE_SPEED;
  ship->weapon.desc[E_WEAPON_MAIN].spot.x        = 0.f;
  ship->weapon.desc[E_WEAPON_MAIN].spot.y        = 0.f;

  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].weaponTexture = E_TEXT_SHIP_MAIN_FIRE;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].setWeaponBBox = setShipFireBoundingBox;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].damage        = SHIP_FIRE_DAMAGE;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].fireRate      = SHIP_FIRE_RATE/2.f;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].fireSpeed     = SHIP_FIRE_SPEED;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].spot.x        = -ship->mov.pos.w/2.f;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].spot.y        = ship->mov.pos.h/4.f;

  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].weaponTexture = E_TEXT_SHIP_MAIN_FIRE;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].setWeaponBBox = setShipFireBoundingBox;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].damage        = SHIP_FIRE_DAMAGE;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].fireRate      = SHIP_FIRE_RATE/2.f;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].fireSpeed     = SHIP_FIRE_SPEED;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].spot.x        = -ship->mov.pos.w/2.f;
  // Attention a l'offset 90 degré lié a l'affichage
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].spot.y        = -ship->mov.pos.h/4.f;

  Element_activateWeapon(ship, E_WEAPON_MAIN);
  Element_activateWeapon(ship, E_WEAPON_SECONDARY_LEFT);
  Element_activateWeapon(ship, E_WEAPON_SECONDARY_RIGHT);
  
  

  r.x = SCREEN_WIDTH / 2;
  r.y = 50;
  Pelement newEnemy1 = createElement( E_TEXT_ENEMY1, 
                                      r, ENEMY1_LINEAR_VELOCITY, ENEMY1_ANGULAR_VELOCITY, 90.f, 
                                      ENEMY1_LIFE,
                                      NB_BOUNDING_BOX_ENEMY1, setEnemy1BoundingBox
                                    );
  updateEnemy1List(addElement(getEnemy1List(), newEnemy1));
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
  BoundingBox bbox = boundingBoxToWorld(el->bbox, el->mov.pos);

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
  // Get Objects
  Pelement map  = getMap();
  Pelement shp  = getShip();
  Pelement enn1 = getEnemy1List();
  /*
  // Clean the Window
  SDL_RenderClear(renderer);
  // Draw background
  drawSATexture (map->texture_id, map->mov.pos, map->mov.angle);
  // Draw missiles
  Pelement pl_fire = getFireList();
  while(pl_fire != NULL)
  {
    drawSATexture (pl_fire->texture_id, pl_fire->mov.pos, pl_fire->mov.angle);
    //showBBox(pl_fire);
    pl_fire = pl_fire->next;
  }

  // Draw enemies ship
  Pelement pl_en = getEnemy1List();
  while(pl_en != NULL)
  {
    drawSATexture (pl_en->texture_id, pl_en->mov.pos, pl_en->mov.angle);
    //showBBox(pl_en);
    pl_en = pl_en->next;
  }
  // Draw gamer ship
  Pelement ship = getShip(); 
  drawSATexture (ship->texture_id, ship->mov.pos, ship->mov.angle);
  //showBBox(ship);
  */
  Element_draw(map);
  Element_draw(enn1);
  Element_draw(shp);
  /*
  SA_Point rspot;
      rspot.x = shp->weapon.desc[E_WEAPON_SECONDARY_RIGHT].spot.x;
      rspot.y = shp->weapon.desc[E_WEAPON_SECONDARY_RIGHT].spot.y;
      Geometry_rotatePoint(&rspot, M_PI/180.f * shp->mov.angle);
      rspot.x += shp->mov.pos.x;
      rspot.y += shp->mov.pos.y;
 Graphics_drawPoint(rspot.x,rspot.y);
 */

  drawExplosion();
  // Set red render for Bounding box dsplay
  SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
  // Update
  SDL_RenderPresent(renderer);
}



void checkCollisions()
{ 
  Pelement ship = getShip();
  updateBoundingBox(&(ship->bbox), ship->mov.angle);

  Pelement pl_enn = getEnemy1List();
  while(pl_enn != NULL)
  {
    if (pl_enn->life > 0)
    {
      updateBoundingBox(&(pl_enn->bbox), pl_enn->mov.angle);
      //Check collision between ship and enemy
      if( isElementsCollision(pl_enn, getShip()) )
      {
        ship->life -= pl_enn->life;
        pl_enn->life = 0;
        if (pl_enn->life <= 0)
          requestExplosion(pl_enn->mov.pos);

        //moveElementOutOfRange(pl_enn);

        break;
      }
      // Check Collison between ennemy and missile
      Pelement pl_fire = getFireList();
      while(pl_fire != NULL)
      {
        updateBoundingBox(&(pl_fire->bbox), pl_fire->mov.angle);
        if(isElementsCollision(pl_fire, pl_enn))
        {
          printf("Collision - ennemy life = %d - fire_life = %d\n", pl_enn->life, pl_fire->life);
          pl_enn->life -= pl_fire->life;
          pl_fire->life = 0;
   
          requestExplosion(pl_enn->mov.pos);

          printf("Collision - ennemy life = %d - fire_life = %d\n", pl_enn->life, pl_fire->life);
          //moveElementOutOfRange(pl_enn);
          //moveElementOutOfRange(pl_fire);
          break;
        }
        else 
          pl_fire = pl_fire->next;
      }
    }
    pl_enn = pl_enn->next;
  }
}


void mainGameLoop(int frameLimit)
{
  unsigned int next_frameLimit =  SDL_GetTicks() + frameLimit;
  
  while(go)
  {
    //printf("Tic = %u\n",SDL_GetTicks());
    updateEventManager();
    Element_updateMotion(getFireList());
    //updateListMotion(getFireList(),updateFireList);
    enemy1Pattern();
    Element_updateMotion(getEnemy1List());
    //updateListMotion(getEnemy1List(),updateEnemy1List);

    checkCollisions();
    printf("Element_collectGarbage(getFireList())\n");
    Element_collectGarbage(getFireList(), updateFireList);
    printf("Element_collectGarbage(getEnemy1List())\n");
    Element_collectGarbage(getEnemy1List(), updateEnemy1List);
    printf("Element_collectGarbage(getShip())\n");
    Element_collectGarbage(getShip(), updateShip);

    displayGame();
    //printf("Toc = %u\n",SDL_GetTicks());
    printf("######################################\n");
    delay(next_frameLimit);
    next_frameLimit = SDL_GetTicks() + frameLimit;  
  }
}



void cleanGame()
{
  cleanGraphics();
  printf("Graphics cleaned\n");
  Element_deleteList(getFireList());
  Element_deleteList(getEnemy1List());
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
