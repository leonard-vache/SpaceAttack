#ifndef GAME_MGT_H
#define GAME_MGT_H

#include "Common.h"
#include "Element.h"
#include "KeyboardMgt.h"
//#include "Collision.h"



// Screen size in pixels
/*
#define SCREEN_WIDTH            600    
#define SCREEN_HEIGHT           700   
                            
               
#define FIRE_RATE               10  // Frame per Fire (1 fire every X frame)
#define SHIP_FIRE_SPEED         18
#define SHIP_ANGULAR_VELOCITY   6  // Express in pixel per frame, to adapt ...
#define SHIP_LINEAR_VELOCITY    8

#define ENEMY1_FIRE_SPEED       18
#define ENEMY1_ANGULAR_VELOCITY 5  // Express in pixel per frame, to adapt ...
#define ENEMY1_LINEAR_VELOCITY  4
*/


int initGame();
void loadGame();
void stopGame();
void cleanGame();
void delay(unsigned int frameLimit);
void drawGame(void);
void enemy1Pattern(void);
void mainGameLoop(int frameLimit);


// Prend en deuxième argument une fonctin de type ptrFunctionPelement
void updateListMotion(Pelement pl, ptrFunctionPelement updateList);
void enemy1Pattern();

#endif