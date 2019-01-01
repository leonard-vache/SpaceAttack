#include "GameMgt.h"
#include "KeyboardMgt.h"


static SDL_Window   *screen   = NULL;
static SDL_Renderer *renderer = NULL;

static bool   go    = 1;
static bool   pause = 0;
static int    score = 0;

void Game_stop() { go = 0; }
void Game_setPause(bool p) { pause = p; }


SDL_Renderer *getRenderer() { return renderer; }



int Game_initSDL()
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

void createEnemy1( )
{
  SA_Rect r;

  r.x = SCREEN_WIDTH / 2;
  r.y = 50;
  Pelement newEnemy1 = createElement( E_TEXT_ENEMY1, 
                                      r, ENEMY1_LINEAR_VELOCITY, ENEMY1_ANGULAR_VELOCITY, 90.f, 
                                      ENEMY1_LIFE,
                                      NB_BOUNDING_BOX_ENEMY1, setEnemy1BoundingBox
                                    );
  /* Init Enemy 1 Weapon */
  newEnemy1->weapon.desc[E_WEAPON_MAIN].weaponTexture = E_TEXT_ENEMY1_MAIN_FIRE;
  newEnemy1->weapon.desc[E_WEAPON_MAIN].setWeaponBBox = setEnemy1MainFireBoundingBox;
  newEnemy1->weapon.desc[E_WEAPON_MAIN].damage        = ENEMY1_FIRE_DAMAGE;
  newEnemy1->weapon.desc[E_WEAPON_MAIN].fireRate      = ENEMY1_FIRE_RATE;
  newEnemy1->weapon.desc[E_WEAPON_MAIN].fireSpeed     = ENEMY1_FIRE_SPEED;
  newEnemy1->weapon.desc[E_WEAPON_MAIN].spot.x        = 0.f;
  newEnemy1->weapon.desc[E_WEAPON_MAIN].spot.y        = 0.f;

  Element_activateWeapon(newEnemy1, E_WEAPON_MAIN);

  updateEnemy1List(addElement(getEnemy1List(), newEnemy1));
}



void enemy1Pattern()
{
  Pelement pl_enn = getEnemy1List();
  Pelement ship = getShip();
  while(pl_enn != NULL)
  {
    //circularPattern(&pl_enn->mov);
    //sinusoidalPattern(&pl_enn->mov);
    followerPattern(ship->mov, &pl_enn->mov);
    
    Element_shoot(pl_enn, E_WEAPON_MAIN);
    pl_enn = pl_enn->next;
  }
}



void Game_loadObjects() 
{
  SA_Rect r;

  /* ********************************* MAP ********************************* */
  r.x = SCREEN_WIDTH / 2;
  r.y = SCREEN_HEIGHT / 2;
  updateMap( createElement( E_TEXT_BACKGROUND, 
                            r, 0, 0, -90.0, 
                            0,
                            NB_BOUNDING_BOX_MAP, setMapBoundingBox
                          ) 
           );

  /* ******************************** SHIP ********************************* */
  r.x = SCREEN_WIDTH / 2;
  r.y = SCREEN_HEIGHT - 50;
  updateShip( createElement( E_TEXT_SHIP, 
                             r, SHIP_LINEAR_VELOCITY, SHIP_ANGULAR_VELOCITY, -90.f, 
                             SHIP_LIFE,
                             NB_BOUNDING_BOX_SHIP, setShipBoundingBox
                           ) 
            );
  /* Init Ship Weapon */
  Pelement ship = getShip();
  ship->weapon.desc[E_WEAPON_MAIN].weaponTexture = E_TEXT_SHIP_MAIN_FIRE;
  ship->weapon.desc[E_WEAPON_MAIN].setWeaponBBox = setShipMainFireBoundingBox;
  ship->weapon.desc[E_WEAPON_MAIN].damage        = SHIP_FIRE_DAMAGE;
  ship->weapon.desc[E_WEAPON_MAIN].fireRate      = SHIP_FIRE_RATE;
  ship->weapon.desc[E_WEAPON_MAIN].fireSpeed     = SHIP_FIRE_SPEED;
  ship->weapon.desc[E_WEAPON_MAIN].spot.x        = 0.f;
  ship->weapon.desc[E_WEAPON_MAIN].spot.y        = 0.f;

  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].weaponTexture = E_TEXT_SHIP_MAIN_FIRE;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].setWeaponBBox = setShipMainFireBoundingBox;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].damage        = SHIP_FIRE_DAMAGE;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].fireRate      = SHIP_FIRE_RATE/2.f;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].fireSpeed     = SHIP_FIRE_SPEED;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].spot.x        = -ship->mov.pos.w/2.f;
  ship->weapon.desc[E_WEAPON_SECONDARY_RIGHT].spot.y        = ship->mov.pos.h/4.f;

  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].weaponTexture = E_TEXT_SHIP_MAIN_FIRE;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].setWeaponBBox = setShipMainFireBoundingBox;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].damage        = SHIP_FIRE_DAMAGE;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].fireRate      = SHIP_FIRE_RATE/2.f;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].fireSpeed     = SHIP_FIRE_SPEED;
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].spot.x        = -ship->mov.pos.w/2.f;
  // Attention a l'offset 90 degré lié a l'affichage
  ship->weapon.desc[E_WEAPON_SECONDARY_LEFT].spot.y        = -ship->mov.pos.h/4.f;

  Element_activateWeapon(ship, E_WEAPON_MAIN);
  //Element_activateWeapon(ship, E_WEAPON_SECONDARY_LEFT);
  //Element_activateWeapon(ship, E_WEAPON_SECONDARY_RIGHT);
  

  /* ******************************* ENEMY 1 ******************************* */
  createEnemy1();
}


void delay(unsigned int frameLimit)
{
  // Gestion des fps (images/stories/seconde)
  unsigned int ticks = Keybord_getTick();
  unsigned int freq = 1000 / FPS;

  if (frameLimit < ticks)
  {
    printf("Error Scheduling : frameLimit(%d) < ticks(%d). Jitter = %d\n", frameLimit, ticks, ticks - frameLimit);
    return;
  } 

  if (frameLimit > ticks + freq) SDL_Delay(freq);
  else SDL_Delay(frameLimit - ticks);
}





void displayGame(void)
{ 
  // Get Objects
  Pelement map  = getMap();
  Pelement shp  = getShip();
  Pelement enn1 = getEnemy1List();
  
  // Clean the Window. Useless because of map
  SDL_RenderClear(renderer);

  // Draw Game Object 
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
  // Set red render for Bounding box display
  SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
  // Update
  SDL_RenderPresent(renderer);
}



void checkCollisions()
{ 
  Pelement ship = getShip();
  //updateBoundingBox(&(ship->bbox), ship->mov.angle);

  Pelement pl_enn = getEnemy1List();
  while(pl_enn != NULL)
  {
    if (pl_enn->life > 0)
    {
      //Check collision between ship and enemy
      if( Element_isCollision(pl_enn, getShip()) )
      {
        ship->life -= pl_enn->life;
        pl_enn->life = 0;
        requestExplosion(pl_enn->mov.pos);
        break;
      }
      // Check Collison between enemy and ship missile
      Pelement pl_fire = getFireList();
      while(pl_fire != NULL)
      {
        if(Element_isCollision(pl_fire, pl_enn))
        {
          pl_enn->life -= pl_fire->life;
          pl_fire->life = 0;
          if( pl_enn->life <= 0 )
            score ++;
          
          requestExplosion(pl_enn->mov.pos);
          break;
        }
        else 
          pl_fire = pl_fire->next;
      }

      // Check Collision between ship and enemy's missiles
      Pelement en_missile = getMissilesList(pl_enn);
      while(en_missile != NULL)
      {
        if( Element_isCollision(en_missile, ship) )
        {

          ship->life -= en_missile->life;
          en_missile->life = 0;
          printf("Collision : ship->life = %d\n", ship->life);
        }

        en_missile = en_missile->next;
      }

    }
    pl_enn = pl_enn->next;
  }
}


void updateShipBehavior(Pelement shp)
{
  /* Update Keybord Event (user interface) */
  Keyboard_handleShipEvent();
  // Only update missiles' motion
  Element_updateMotion(getMissilesList(getShip()));
  updateBoundingBox(&shp->bbox, shp->mov.angle);
}


void updateEnemiesBehavior( void )
{
  /* *** ENEMY 1 *** */
  if ( getEnemy1List() == NULL )
  {
    createEnemy1();
  }
  enemy1Pattern();
  Element_updateMotion(getEnemy1List());

  /* *** BOSS    *** */
  //TODO

}


void Game_mainLoop(int frameLimit)
{
  unsigned int next_frameLimit =  Keybord_getTick() + frameLimit;
  
  while(go)
  {
    /* Update User interface */
    Keyboard_updateEvent();

    if (false == pause)
    {
      /* Update Element Behavior */
      updateShipBehavior(getShip());
      updateEnemiesBehavior();
      /* Once all Game objects are updated, check potential collision */
      checkCollisions();
      /* Delete dead objects ( => life < 0 ) */
      Element_collectGarbage(getFireList(), updateFireList);
      Element_collectGarbage(getEnemy1List(), updateEnemy1List);
      Element_collectGarbage(getShip(), updateShip);
      /* Game Over if ship's life reach 0 */
      if (NULL == getShip())
      {
        printf(" ***** YOU ARE DEAD *****\n");
        break;
      } 
      /* Draw result */
      displayGame();
      // printf("Toc = %u\n",SDL_GetTicks());
    }
    /* Sleep until end of cycle   */
    delay(next_frameLimit);
    /* Compute next cycle timeout */
    next_frameLimit = Keybord_getTick() + frameLimit;  
  }

  printf("SCORE : %d\n", score);
}



void Game_clean()
{
  Graphics_clean();
  printf("Graphics cleaned\n");

  Element_deleteAll(getEnemy1List());
  Element_deleteOne(getShip());
  Element_deleteOne(getMap());
  printf("Elements cleaned\n");

  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_DestroyWindow(screen);
  screen = NULL;
  printf("Renderer & Window destroyed\n");

  SDL_Quit();
}
