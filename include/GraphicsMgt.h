#ifndef GRAPHICS_MGT_h
#define GRAPHICS_MGT_h

#include "Common.h"
#include "Prototypes.h"


#define P_BACKGROUND  "./images/map.bmp"
#define P_SHIP        "./images/ship.bmp"
#define P_SHIP_FIRE   "./images/missilevex.bmp"
#define P_ENEMY1      "./images/enemy1.bmp"
#define P_EXPLOSION   "./images/expl"
#define BOSS_LIFE     "./images/vieboss.bmp"

#define ANGLE_OFFSET        90
#define EXPLOSION_FREQUENCY 10

typedef struct explosion
{
  SDL_Rect pos;
  int previous_tick;
  int collision_id;

  struct explosion *next;
} Explosion;


SDL_Texture *loadImage(char *img_path);
SDL_Texture *loadImageAlpha(char *img_path, int r, int g, int b);
void cleanGraphics(void);
void drawElement(Pelement el);
void drawTexture(SDL_Texture *image, int x, int y, int angle);

#endif