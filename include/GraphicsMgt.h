#ifndef GRAPHICS_MGT_h
#define GRAPHICS_MGT_h

#include "Common.h"
#include "Collision.h"

#define P_BACKGROUND  "./images/map.bmp"
#define P_SHIP        "./images/ship.bmp"
#define P_SHIP_FIRE   "./images/missilevex.bmp"
#define P_ENEMY1      "./images/enemy1.bmp"
#define P_EXPLOSION   "./images/expl"
#define BOSS_LIFE     "./images/vieboss.bmp"

#define ANGLE_OFFSET        90

#define NB_EXPLOSION        16 
#define EXPLOSION_FREQUENCY 20



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
  E_TEXT_EXPLOSION,
  E_TEXT_BOSS_LIFE = NB_EXPLOSION + E_TEXT_EXPLOSION, 
  E_TEXT_NB
} SpaceAttack_te_texture;


SDL_Texture *loadImage(char *img_path);
SDL_Texture *loadImageAlpha(char *img_path, int r, int g, int b);
void cleanGraphics(void);
void drawSATexture(SpaceAttack_te_texture txt_id, SA_Rect pos, double angle);
void drawPolygon(SA_Point ul, SA_Point ur, SA_Point br, SA_Point bl);
void Graphics_drawPoint(int x, int y);

void requestExplosion(SA_Rect position);
void getTextureDimension (SpaceAttack_te_texture txt_id, SA_Rect *r);

#endif