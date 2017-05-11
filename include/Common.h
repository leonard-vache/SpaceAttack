#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>


// Screen size in pixels
#define SCREEN_WIDTH            600    
#define SCREEN_HEIGHT           700   
                            
#define FPS                     30  // Frame per second
#define ADAPT_TO_FPS(x)         (x) / FPS 

#define SHIP_MAX_WEAPON         3
// Velocity are expressed in Pixel per second
#define SHIP_FIRE_RATE          4  // Fire frequency (fire/seconde)
#define SHIP_FIRE_SPEED         550  
#define SHIP_FIRE_DAMAGE        5
#define SHIP_ANGULAR_VELOCITY   180
#define SHIP_LINEAR_VELOCITY    250

#define ENEMY1_FIRE_RATE        60
#define ENEMY1_FIRE_SPEED       550
#define ENEMY1_DAMAGE           2
#define ENEMY1_ANGULAR_VELOCITY 250  // Express in pixel per frame, to adapt ...
#define ENEMY1_LINEAR_VELOCITY  150

#define SHIP_LIFE               50   
#define ENEMY1_LIFE             10


extern SDL_Renderer *getRenderer();

#endif