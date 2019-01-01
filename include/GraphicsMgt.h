#ifndef GRAPHICS_MGT_h
#define GRAPHICS_MGT_h

#include "Common.h"
#include <SDL2/SDL_image.h>

#include "Geometry.h"
#include "Collision.h"

/* Image path */
#define P_BACKGROUND            "./images/map.bmp"
#define P_SHIP                  "./images/ship.bmp"
#define P_SHIP_MAIN_FIRE        "./images/missilevex.bmp"
#define P_ENEMY1                "./images/enemy1.bmp"
#define P_ENEMY1_MAIN_FIRE      "./images/missile_enemy1.bmp"
#define P_EXPLOSION_SPRITES     "./images/ExplosionSprites.png"
#define P_BOSS_LIFE             "./images/vieboss.bmp"

#define ANGLE_OFFSET            90

/* Explosion display constant */
#define EXPLOSION_NB            16 
#define EXPLOSION_FREQUENCY     5
#define EXPLOSION_SPRITE_SQUARE 96 


typedef struct sp_texture
{
  SDL_Texture *texture;
  int angular_offset;
} SP_Texture;

 
typedef enum SA_te_texture
{
  E_TEXT_BACKGROUND,
  E_TEXT_SHIP,
  E_TEXT_SHIP_MAIN_FIRE,
  E_TEXT_ENEMY1,
  E_TEXT_ENEMY1_MAIN_FIRE,
  E_TEXT_EXPLOSION_SPRITES,
  E_TEXT_P_BOSS_LIFE, 
  E_TEXT_NB
} SpaceAttack_te_texture;


SDL_Texture *loadImage(char *img_path);
SDL_Texture *loadImageAlpha(char *img_path, int r, int g, int b);
void Graphics_clean(void);
void Graphics_drawSATexture(SpaceAttack_te_texture txt_id, SA_Rect pos, double angle);
void drawPolygon(SA_Point ul, SA_Point ur, SA_Point br, SA_Point bl);
void Graphics_drawPoint(int x, int y);
void Graphics_loadImages( void );


void requestExplosion(SA_Rect position);
void drawExplosion(void);
void getTextureDimension(SpaceAttack_te_texture txt_id, SA_Rect *r);

#endif