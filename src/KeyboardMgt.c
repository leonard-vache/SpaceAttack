#include "KeyboardMgt.h"



enum key { UP, DOWN, LEFT, RIGHT, SHOOT, NUM_KEY };
static int keyState[NUM_KEY] = {0,0,0,0};


void shooting()
{
  static unsigned int previous_ticks = 0;

  // Set FPS in ms for test + adapt fire rate in function of FPS
  if( (SDL_GetTicks() - previous_ticks) >= (FIRE_RATE / (FPS * 0.001)) )
  {
    Pelement shp = getShip();
    Pelement newMissile = create(getSPTexture().shipFire,shp->pos,SHIP_FIRE_SPEED,0,shp->angle,NB_BOUNDING_BOX_FIRE_SHIP, setShipFireBoundingBox);
    updateFireList(add(getFireList(),newMissile));
    previous_ticks = SDL_GetTicks();
  }
}

void manageMapBorder(Pelement el)
{
  if(el->pos.x <= el->pos.w /2)
    el->pos.x = el->pos.w / 2;

  if(el->pos.y <= el->pos.h / 2)
    el->pos.y = el->pos.h / 2;

  if(el->pos.x + el->pos.w / 2 >= SCREEN_WIDTH)
    el->pos.x = SCREEN_WIDTH - el->pos.w / 2;

  if(el->pos.y + el->pos.h / 2 >= SCREEN_HEIGHT)
    el->pos.y = SCREEN_HEIGHT - el->pos.h / 2;
}

void shipMove()
{
  Pelement shp = getShip();
  //SDL_Point center;
  int i;
  for(i = 0; i < NUM_KEY; i++)
  {
    if(keyState[i] == 1)
    {
      switch(i)
      {
        case UP :
          shp->pos.y +=  round(sin(shp->angle*M_PI/180.0) * (float)shp->speed[0]);
          shp->pos.x +=  round(cos(shp->angle*M_PI/180.0) * (float)shp->speed[0]);
          manageMapBorder(shp);
          break;

        case DOWN :
          shp->pos.y += round(sin(shp->angle*M_PI/180.0) * (float)(-shp->speed[0]));
          shp->pos.x += round(cos(shp->angle*M_PI/180.0) * (float)(-shp->speed[0]));
          manageMapBorder(shp);
          break;

        case LEFT :
          shp->angle -= (float)shp->speed[1];    
          if (shp->angle < -360 )
            shp->angle = fmod(shp->angle,360.f);     

          break;

        case RIGHT :
          shp->angle += (float)shp->speed[1];
          if (shp->angle > 360 )
            shp->angle = fmod(shp->angle,360.f);  

          break;

        case SHOOT :
          shooting();
          break;

        default :
          printf("Error unknown motion\n");
          stopGame();
          break;
      }
    }
  }
}



void updateKey()
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

          case SDLK_UP:
              keyState[UP] = 1;
              //shipMove(UP);
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
            printf("Warning : Key unrecogize\n");
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
            printf("Warning : Key unrecogize\n");
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
 
