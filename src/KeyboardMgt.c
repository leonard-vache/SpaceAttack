#include "KeyboardMgt.h"

#include "Element.h"
#include "GameMgt.h"



enum key { UP, DOWN, LEFT, RIGHT, SHOOT, SLOW, PAUSE, NUM_KEY };

static int S_KeyState[NUM_KEY] = {0};

/* SDL ticks passed while game was paused */
static unsigned int S_DeltaTick = 0;

static void manageMapBorder(Pelement el);
static void pauseEvent();


static void manageMapBorder(Pelement el)
{
  if(el->mov.pos.x <= el->mov.pos.w / 2)
    el->mov.pos.x = el->mov.pos.w / 2;

  if(el->mov.pos.y <= el->mov.pos.h / 2)
    el->mov.pos.y = el->mov.pos.h / 2;

  if(el->mov.pos.x + el->mov.pos.w / 2 >= SCREEN_WIDTH)
    el->mov.pos.x = SCREEN_WIDTH - el->mov.pos.w / 2;

  if(el->mov.pos.y + el->mov.pos.h / 2 >= SCREEN_HEIGHT)
    el->mov.pos.y = SCREEN_HEIGHT - el->mov.pos.h / 2;
}


unsigned int Keybord_getTick()
{
  return (SDL_GetTicks() - S_DeltaTick);
}


static void pauseEvent()
{
  /* SDL tick when gam is paused */
  static unsigned int s_pausedTick = 0;
  /* Put Game in pause */
  Game_setPause(S_KeyState[PAUSE]);

  if (1 == S_KeyState[PAUSE])
  {
    /* Game is paused */
    s_pausedTick = SDL_GetTicks();
    printf ("**** GAME PAUSES ***\n");
  }
  else
  {
    /* Resume game => compute time elapsed during pause */
    S_DeltaTick += SDL_GetTicks() - s_pausedTick;
    printf ("**** GAME RESUMES ***\n");
  }
}


void Keyboard_handleShipEvent()
{
  Pelement shp = getShip();
  int i;
  for(i = 0; i < NUM_KEY; i++)
  {
    if(S_KeyState[i] == 1)
    {
      switch(i)
      {
        case UP :
          shp->mov.pos.y += sin(shp->mov.angle*M_PI/180.0) * ADAPT_TO_FPS(shp->mov.speed.x);
          shp->mov.pos.x += cos(shp->mov.angle*M_PI/180.0) * ADAPT_TO_FPS(shp->mov.speed.x);
          manageMapBorder(shp);
          break;

        case DOWN :
          shp->mov.pos.y += sin(shp->mov.angle*M_PI/180.0) * (- ADAPT_TO_FPS(shp->mov.speed.x));
          shp->mov.pos.x += cos(shp->mov.angle*M_PI/180.0) * (- ADAPT_TO_FPS(shp->mov.speed.x));
          manageMapBorder(shp);
          break;

        case LEFT :
          shp->mov.angle -= ADAPT_TO_FPS(shp->mov.speed.y);    
          if (shp->mov.angle < -360 )
            shp->mov.angle = fmod(shp->mov.angle,360.f);     
          break;

        case RIGHT :
          shp->mov.angle += ADAPT_TO_FPS(shp->mov.speed.y);
          if (shp->mov.angle > 360 )
            shp->mov.angle = fmod(shp->mov.angle,360.f);  
          break;

        case SHOOT : 
          Element_shoot(shp, E_WEAPON_MAIN);
          Element_shoot(shp, E_WEAPON_SECONDARY_LEFT);
          Element_shoot(shp, E_WEAPON_SECONDARY_RIGHT);
          break;

        case SLOW :
          shp->mov.speed.x = 2.f;
          shp->mov.speed.y = 2.f;
          printf("SLOW => speed = (%f,%f)\n", shp->mov.speed.x, shp->mov.speed.y);
          break;

      } // End switch(i)

    } // End if(S_KeyState[i] == 1)

  } // End for(i = 0; i < NUM_KEY; i++)
  
}



void Keyboard_updateEvent( void )
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        printf( "SDL_QUIT event received \n");
        Game_stop();
        break;

      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            Game_stop();
            break;

          case SDLK_SPACE:
            S_KeyState[SHOOT] = 1;
            break;

          case SDLK_p:
            S_KeyState[PAUSE] = !S_KeyState[PAUSE];
            pauseEvent();         
            break;

          case SDLK_RSHIFT:
            S_KeyState[SLOW] = 1;
            break;

          case SDLK_UP:
            S_KeyState[UP] = 1;
            break;

          case SDLK_DOWN:
            S_KeyState[DOWN] = 1;
            break;

          case SDLK_LEFT: 
            S_KeyState[LEFT] = 1;
            break;

          case SDLK_RIGHT:
            S_KeyState[RIGHT] = 1;
            break;

          default:
            //Game_stop();
            printf("Warning : Unknown key %d\n", event.key.keysym.sym);
            break;
        }
        break;
      
      case SDL_KEYUP:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            Game_stop();
            break;

          case SDLK_SPACE:
            S_KeyState[SHOOT] = 0;
            break;

          case SDLK_RSHIFT:
            S_KeyState[SLOW] = 0;
            break;

          case SDLK_UP: 
            S_KeyState[UP] = 0;
            break;

          case SDLK_DOWN:
            S_KeyState[DOWN] = 0;
            break;

          case SDLK_LEFT: 
            S_KeyState[LEFT] = 0;
            break;

          case SDLK_RIGHT:
            S_KeyState[RIGHT] = 0;
            break;

        }
        break;
      
      default:
        break;
    }
  }
}

 
