#ifndef PROTOTYPES_H
#define PROTOTYPES_H


// Access function
extern SDL_Renderer *getRenderer();

extern Pelement getMap(); 

extern Pelement getFireList();
extern void updateFireList(Pelement l);

extern Pelement getEnemy1List();
extern void updateEnemy1List(Pelement l);

//extern int adaptToFPS(float value);

//extern int initGame();
//extern void loadGame();
//extern void stopGame();
//extern void mainGameLoop(int frameLimit);
//extern void cleanGame();


// KeyboardMgt
//extern void updateEventManager(void);

// GraphicsMgt
extern SpaceAttack_Texture getSPTexture(void);
extern Pelement getShip(void);
//extern void loadGraphics(void);
//extern void drawGraphics(void);
//extern void cleanGraphics(void);



#endif
