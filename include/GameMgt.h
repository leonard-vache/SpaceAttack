#ifndef GAME_MGT_H
#define GAME_MGT_H

#include "Common.h"
#include "KeyboardMgt.h"
#include "Collision.h"


int initGame();
void loadGame();
void stopGame();
void cleanGame();
void delay(unsigned int frameLimit);
void drawGame(void);
void enemy1Pattern(void);
void mainGameLoop(int frameLimit);


// Prend en deuxième argument une fonctin de type ptrFunction
void updateListMotion(Pelement pl, ptrFunction updateList);
void enemy1Pattern();

#endif