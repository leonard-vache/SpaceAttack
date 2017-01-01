#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

//#include "Element.h"


// Screen size in pixels
#define SCREEN_WIDTH            600    
#define SCREEN_HEIGHT           700   
                            
//#define RPM 200          // Round Per Minutes
#define FPS                     30                   
#define FIRE_RATE               10  // Frame per Fire (1 fire every X frame)
#define SHIP_FIRE_SPEED         18
#define SHIP_ANGULAR_VELOCITY   6  // Express in pixel per frame, to adapt ...
#define SHIP_LINEAR_VELOCITY    8

#define ENEMY1_FIRE_SPEED       18
#define ENEMY1_ANGULAR_VELOCITY 5  // Express in pixel per frame, to adapt ...
#define ENEMY1_LINEAR_VELOCITY  4


extern SDL_Renderer *getRenderer();

#endif