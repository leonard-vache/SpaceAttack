#ifndef GAME_MGT_H
#define GAME_MGT_H

#include "Common.h"
#include "Element.h"


int Game_initSDL();

void Game_stop();
void Game_setPause(bool p);

void delay(unsigned int frameLimit);
void drawGame(void);
void enemy1Pattern(void);
void Game_loadObjects();
void Game_mainLoop(int frameLimit);
void Game_clean();


// Prend en deuxième argument une fonctin de type ptrFunctionPelement
void updateListMotion(Pelement pl, ptrFunctionPelement updateList);
void enemy1Pattern();

#endif