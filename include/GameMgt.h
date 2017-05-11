#ifndef GAME_MGT_H
#define GAME_MGT_H

#include "Common.h"
#include "Element.h"
#include "KeyboardMgt.h"



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