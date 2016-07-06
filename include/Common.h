#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <SDL.h>

#include "opstruct.h"
 
// Screen size in pixels
#define SCREEN_WIDTH 600    
#define SCREEN_HEIGHT 700   
                            
//#define RPM 200          // Round Per Minutes
#define FPS 30                    // 
#define FIRE_RATE 10              // Fire per Frame 
#define SHIP_FIRE_SPEED 18
#define SHIP_ANGULAR_VELOCITY 12  // Express in pixel per frame, to adapt ...
#define SHIP_LINEAR_VELOCITY 8

#define ENEMY1_FIRE_SPEED 18
#define ENEMY1_ANGULAR_VELOCITY 5  // Express in pixel per frame, to adapt ...
#define ENEMY1_LINEAR_VELOCITY 4

typedef struct spaceatack_texture 
{
  SDL_Texture *background;
  SDL_Texture *ship;
  SDL_Texture *shipFire;
  SDL_Texture *enemy1;
  SDL_Texture *bossLife;
} SpaceAttack_Texture;

#endif