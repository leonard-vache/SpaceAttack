#include "KeyboardMgt.h"



enum key { UP, DOWN, LEFT, RIGHT, SHOOT, SLOW, NUM_KEY };

static int keyState[NUM_KEY] = {0};

static void manageMapBorder(Pelement el);

static void manageMapBorder(Pelement el)
{
  if(el->mov.pos.x <= el->mov.pos.w /2)
    el->mov.pos.x = el->mov.pos.w / 2;

  if(el->mov.pos.y <= el->mov.pos.h / 2)
    el->mov.pos.y = el->mov.pos.h / 2;

  if(el->mov.pos.x + el->mov.pos.w / 2 >= SCREEN_WIDTH)
    el->mov.pos.x = SCREEN_WIDTH - el->mov.pos.w / 2;

  if(el->mov.pos.y + el->mov.pos.h / 2 >= SCREEN_HEIGHT)
    el->mov.pos.y = SCREEN_HEIGHT - el->mov.pos.h / 2;
}


void shipMove()
{
  Pelement shp = getShip();
  int i;
  for(i = 0; i < NUM_KEY; i++)
  {
    if(keyState[i] == 1)
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
          //shooting();
          Element_shoot(shp, E_WEAPON_MAIN);
          Element_shoot(shp, E_WEAPON_SECONDARY_LEFT);
          Element_shoot(shp, E_WEAPON_SECONDARY_RIGHT);
          break;

        case SLOW :
          shp->mov.speed.x = 2.f;
          shp->mov.speed.y = 2.f;
          printf("SLOW => speed = (%f,%f)\n", shp->mov.speed.x, shp->mov.speed.y);
          break;

        default :
          printf("Error unknown motion\n");
          stopGame();
          break;

      } // End switch(i)

    } // End if(keyState[i] == 1)

  } // End for(i = 0; i < NUM_KEY; i++)
  
}



void updateKey( void )
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        stopGame();
        break;

      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            stopGame();
            break;

          case SDLK_SPACE:
            keyState[SHOOT] = 1;
            break;

          case SDLK_RSHIFT:
            keyState[SLOW] = 1;
            break;

          case SDLK_UP:
            keyState[UP] = 1;
            break;

          case SDLK_DOWN:
            keyState[DOWN] = 1;
            break;

          case SDLK_LEFT: 
            keyState[LEFT] = 1;
            break;

          case SDLK_RIGHT:
            keyState[RIGHT] = 1;
            break;

          default:
            //stopGame();
            printf("Warning : Unknown key %d\n", event.key.keysym.sym);
            break;
        }
        break;
      
      case SDL_KEYUP:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            stopGame();
            break;

          case SDLK_SPACE:
            keyState[SHOOT] = 0;
            break;

          case SDLK_RSHIFT:
            keyState[SLOW] = 0;
            break;

          case SDLK_UP: 
            keyState[UP] = 0;
            break;

          case SDLK_DOWN:
            keyState[DOWN] = 0;
            break;

          case SDLK_LEFT: 
            keyState[LEFT] = 0;
            break;

          case SDLK_RIGHT:
            keyState[RIGHT] = 0;
            break;

          default:
            //stopGame();
            printf("Warning : Unknown key %d\n", event.key.keysym.sym);
            break;
        }
        break;
      
      default:
        break;
    }
  }
}

void updateEventManager()
{
  updateKey();
  shipMove();
}
 
