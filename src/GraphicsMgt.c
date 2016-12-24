#include <unistd.h>
#include "GraphicsMgt.h"


typedef struct explosion
{
  SDL_Rect pos;
  int previous_tick;
  int collision_id;

  struct explosion *next;
} Explosion;


static Explosion *explosionListe = NULL;

Explosion *getExplosionList() { return explosionListe; }
void updateExplosionList(Explosion *ex) { explosionListe = ex; }

static SP_Texture S_GameTexture[E_TEXT_NB];

static void drawCenter(int x, int y);


SDL_Texture *loadImage(char *img_path)
{
  // Charge les images avec SDL Image dans une SDL_Surface 
  SDL_Surface *loadedImage = NULL;
  SDL_Texture *texture = NULL;

  // loadedImage = IMG_Load(img_path); -> need SDL_image...
  loadedImage = SDL_LoadBMP(img_path); 
   
  if (loadedImage != NULL)
  {
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getRenderer(), loadedImage);
    // On libère la surface
    SDL_FreeSurface(loadedImage);
    if(texture == NULL)
    {
      printf("Texture non créée ! SDL_Error : %s\n", SDL_GetError());
      exit(0);
    }
  }
  else
  {
    printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
    exit(0);
  } 
  return texture; 
}


SDL_Texture *loadImageAlpha(char *img_path, int r, int g, int b)
{
  // Charge les images avec SDL Image dans une SDL_Surface 
  SDL_Surface *loadedImage = NULL;
  SDL_Texture *texture = NULL;

  // loadedImage = IMG_Load(img_path); -> need SDL_image.h ...
  loadedImage = SDL_LoadBMP(img_path); 
  if (loadedImage != NULL)
  {
    //Application du filtre de transparence
    SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, r, g, b));
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getRenderer(), loadedImage);
    // On libère la surface
    SDL_FreeSurface(loadedImage);
    if(texture == NULL)
    {
      printf("Texture non créée ! SDL_Error : %s\n", SDL_GetError());
      exit(0);
    }
  }
  else
  {
    printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
    exit(0);
  } 
  return texture; 
}


void getTextureDimension (SpaceAttack_te_texture txt_id, SDL_Rect *r)
{
  if(SDL_QueryTexture(S_GameTexture[txt_id].texture , NULL, NULL, &(r->w), &(r->h)) < 0) 
  {
    printf("Can not get texture dimension ! SDL_Error : %s", SDL_GetError());
    stopGame();
  }
}


void loadGraphics(void)
{
  /*
  spTexture.background = loadImage(P_BACKGROUND);
  spTexture.ship       = loadImageAlpha(P_SHIP,255,0,255);
  spTexture.shipFire   = loadImageAlpha(P_SHIP_FIRE,0,0,0);
  spTexture.enemy1     = loadImageAlpha(P_ENEMY1,0,0,0);
  spTexture.bossLife   = loadImageAlpha(BOSS_LIFE,0,0,0);
  int i;
  for(i = 1; i <= NB_EXPLOSION; i++ )
  {
    char expl_path[256];
    sprintf(expl_path,"%s%i.bmp",P_EXPLOSION,i);
    spTexture.explosions[i-1] = loadImageAlpha(expl_path,0,0,0);
  } 
  */

  S_GameTexture[E_TEXT_BACKGROUND].texture = loadImage(P_BACKGROUND);
  S_GameTexture[E_TEXT_BACKGROUND].angular_offset = 90;

  S_GameTexture[E_TEXT_SHIP].texture = loadImageAlpha(P_SHIP,255,0,255);
  S_GameTexture[E_TEXT_SHIP].angular_offset = 90;

  S_GameTexture[E_TEXT_SHIP_FIRE].texture = loadImageAlpha(P_SHIP_FIRE,0,0,0);
  S_GameTexture[E_TEXT_SHIP_FIRE].angular_offset = 90;

  S_GameTexture[E_TEXT_ENEMY1].texture = loadImageAlpha(P_ENEMY1,0,0,0);
  S_GameTexture[E_TEXT_ENEMY1].angular_offset = -90;

  S_GameTexture[E_TEXT_BOSS_LIFE].texture = loadImageAlpha(BOSS_LIFE,0,0,0);
  S_GameTexture[E_TEXT_BOSS_LIFE].angular_offset = 90;

  int i;
  for(i = 0; i < NB_EXPLOSION; i++ )
  {
    char expl_path[256];
    sprintf(expl_path,"%s%d.bmp",P_EXPLOSION,i+1);

    S_GameTexture[E_TEXT_EXPLOSION+i].texture = loadImageAlpha(expl_path,0,0,0);
    S_GameTexture[E_TEXT_EXPLOSION+i].angular_offset = 90;
  } 
}

/*
void drawPolygon(Polygon poly)
{
  SDL_RenderDrawLine(getRenderer(),poly.ul.x, poly.ul.y, poly.ur.x, poly.ur.y);
  SDL_RenderDrawLine(getRenderer(),poly.ur.x, poly.ur.y, poly.br.x, poly.br.y);
  SDL_RenderDrawLine(getRenderer(),poly.br.x, poly.br.y, poly.bl.x, poly.bl.y);
  SDL_RenderDrawLine(getRenderer(),poly.bl.x, poly.bl.y, poly.ul.x, poly.ul.y);
}
*/


void drawPolygon(SA_Point ul, SA_Point ur, SA_Point br, SA_Point bl)
{
  SDL_RenderDrawLine(getRenderer(),ul.x, ul.y, ur.x, ur.y);
  SDL_RenderDrawLine(getRenderer(),ur.x, ur.y, br.x, br.y);
  SDL_RenderDrawLine(getRenderer(),br.x, br.y, bl.x, bl.y);
  SDL_RenderDrawLine(getRenderer(),bl.x, bl.y, ul.x, ul.y);
}


void RequestExplosion(SDL_Rect position)
{
  // Creation of an explosion element. It will be destroyed by EndExplosion() function.
  Explosion *ex;
  ex = malloc(sizeof(Explosion));
 
  ex->pos = position;
  ex->previous_tick = 0;
  ex->collision_id = E_TEXT_EXPLOSION;  

  // Add it at the beginning of list
  ex->next = getExplosionList();
  // Update list pointer
  updateExplosionList(ex);
}

void EndExplosion(Explosion *ex)
{
  Explosion *pl_ex = getExplosionList();
  if (pl_ex == ex )
  {
    updateExplosionList(pl_ex->next);
    return;
  }

  while ( pl_ex->next != NULL )
  {
    if ( pl_ex->next == ex )
    {
      pl_ex->next == ex->next; // Raccordement
      free(pl_ex);
      break;
    }
    pl_ex = pl_ex->next;
  }
}


void deleteAllExplosions()
{
  Explosion *p = getExplosionList(), *pex = NULL;
  while(p != NULL)
  {
    pex = p;
    p = p->next;
    free(pex);
  }
}


void drawExplosion ()
{
  Explosion *pl_ex = getExplosionList();
  if ( NULL == pl_ex )
    return;

  while ( pl_ex != NULL )
  {

    int tick = SDL_GetTicks();

    if ( SDL_GetTicks() - pl_ex->previous_tick > EXPLOSION_FREQUENCY )
    {
      pl_ex->previous_tick = SDL_GetTicks();
      pl_ex->collision_id ++;
    }

    SDL_Rect texture_ex = pl_ex->pos;
    SDL_QueryTexture(S_GameTexture[pl_ex->collision_id].texture, NULL, NULL, &texture_ex.w, &texture_ex.h);
    
    SDL_Point center;
    center.x = texture_ex.w / 2;
    center.y = texture_ex.h / 2;

    if ( 0 > SDL_RenderCopyEx( getRenderer(),
                               S_GameTexture[pl_ex->collision_id].texture,
                               NULL,
                               &texture_ex,
                               S_GameTexture[pl_ex->collision_id].angular_offset,
                               &center,
                               SDL_FLIP_NONE ) 
       )
    {
      printf("Error while drawing explosion. SDL Error : %s\n", SDL_GetError());
      return;
    }
   
    if ( NB_EXPLOSION == pl_ex->collision_id  )
    {
      EndExplosion(pl_ex);
    }
    pl_ex = pl_ex->next;
  }
}


void cleanGraphics(void)
{
  // Delete remaning Explosion object
  deleteAllExplosions();
  // Textures liberation
  int i;
  for (i = 0; i < E_TEXT_NB; i++)
  {
    if (S_GameTexture[i].texture != NULL)
      SDL_DestroyTexture(S_GameTexture[i].texture);
  }
}


void drawSATexture(SpaceAttack_te_texture txt_id, SDL_Rect pos, double angle)
{
  SDL_Point center;
  center.x = pos.w / 2;
  center.y = pos.h / 2;

  SDL_Rect texture_pos = pos;
  texture_pos.x -= pos.w / 2;
  texture_pos.y -= pos.h / 2;

  if (0 > SDL_RenderCopyEx( getRenderer(), 
                            S_GameTexture[txt_id].texture, 
                            NULL, 
                            &texture_pos, 
                            round(angle + S_GameTexture[txt_id].angular_offset), 
                            &center, 
                            SDL_FLIP_NONE )
     )
  {
    printf("Error while drawing element. SDL Error : %s\n", SDL_GetError());
    stopGame();
    return;
  }
  //drawCenter(pos.x, pos.y);
}


static void drawCenter(int x, int y)
{
  SDL_Rect dest;
  int size = 3;
  dest.x = x - size/2;
  dest.y = y - size/2;
  dest.w = size;
  dest.h = size;
  SDL_RenderCopy( getRenderer(),
                  S_GameTexture[E_TEXT_BOSS_LIFE].texture, 
                  NULL, 
                  &dest );
}


static void drawTexture(SDL_Texture *image, int x, int y, int angle)
{ 
  SDL_Rect dest;
  // Règle le rectangle à dessiner selon la taille de l'image source
  dest.x = x;
  dest.y = y;   
  // Dessine l'image entière sur l'écran aux coordonnées x et y
  SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);

  SDL_Point center;
  center.x = dest.w / 2;
  center.y = dest.h / 2;

  if ( 0 > SDL_RenderCopyEx( getRenderer(),
                             image,
                             NULL,
                             &dest,
                             angle,
                             &center,
                             SDL_FLIP_NONE ) 
     )
  {
    printf("Error when rotate. SDL Error : %s\n", SDL_GetError());
    stopGame();
    return;
  }
}

