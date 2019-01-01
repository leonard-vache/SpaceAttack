#include <unistd.h>
#include <stdio.h>
#include "GraphicsMgt.h"
#include "KeyboardMgt.h"
#include "GameMgt.h"


typedef struct explosion
{
  SA_Rect pos;
  int previous_tick;
  int collision_id;

  struct explosion *next;
} Explosion;

static SP_Texture S_GameTexture[E_TEXT_NB];

static Explosion *explosionListe = NULL;

Explosion *getExplosionList() { return explosionListe; }
void updateExplosionList(Explosion *ex) { explosionListe = ex; }


SDL_Texture *loadImage(char *img_path)
{
  // Charge les images avec SDL Image dans une SDL_Surface 
  SDL_Surface *loadedImage = NULL;
  SDL_Texture *texture = NULL;

  loadedImage = IMG_Load(img_path);
   
  if (loadedImage != NULL)
  {
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getRenderer(), loadedImage);
    // On libère la surface
    SDL_FreeSurface(loadedImage);
    if(texture == NULL)
    {
      printf("%s : Texture \"%s\" non créée ! SDL_Error = %s\n", __FUNCTION__, img_path, SDL_GetError());
      exit(0);
    }
  }
  else
  {
    printf("%s : L'image \"%s\" n'a pas pu être chargée! SDL_Error = %s\n", __FUNCTION__, img_path, SDL_GetError());
    exit(0);
  } 
  return texture; 
}


SDL_Texture *loadImageAlpha(char *img_path, int r, int g, int b)
{
  // Charge les images avec SDL Image dans une SDL_Surface 
  SDL_Surface *loadedImage = NULL;
  SDL_Texture *texture = NULL;

  loadedImage = IMG_Load(img_path);

  if (loadedImage != NULL)
  {
    // Application du filtre de transparence
    SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, r, g, b));
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getRenderer(), loadedImage);
    // On libère la surface
    SDL_FreeSurface(loadedImage);
    if(texture == NULL)
    {
      printf("%s : Texture \"%s\" non créée ! SDL_Error = %s\n", __FUNCTION__, img_path, SDL_GetError());
      exit(0);
    }
  }
  else
  {
    printf("%s : L'image \"%s\" n'a pas pu être chargée! SDL_Error = %s\n", __FUNCTION__, img_path, SDL_GetError());
    exit(0);
  } 
  return texture; 
}


void getTextureDimension (SpaceAttack_te_texture txt_id, SA_Rect *r)
{
  SDL_Rect sdl_r;
  if(SDL_QueryTexture(S_GameTexture[txt_id].texture , NULL, NULL, &(sdl_r.w), &(sdl_r.h)) < 0) 
  {
    printf("%s : Can not get texture dimension ! SDL_Error = %s", __FUNCTION__, SDL_GetError());
    Game_stop();
  }

  r->w = (double)sdl_r.w;
  r->h = (double)sdl_r.h;
}


void Graphics_loadImages( void )
{
  S_GameTexture[E_TEXT_BACKGROUND].texture = loadImage(P_BACKGROUND);
  S_GameTexture[E_TEXT_BACKGROUND].angular_offset = 90;

  S_GameTexture[E_TEXT_SHIP].texture = loadImageAlpha(P_SHIP,255,0,255);
  S_GameTexture[E_TEXT_SHIP].angular_offset = 90;

  S_GameTexture[E_TEXT_SHIP_MAIN_FIRE].texture = loadImageAlpha(P_SHIP_MAIN_FIRE,0,0,0);
  S_GameTexture[E_TEXT_SHIP_MAIN_FIRE].angular_offset = 90;

  S_GameTexture[E_TEXT_ENEMY1].texture = loadImageAlpha(P_ENEMY1,0,0,0);
  S_GameTexture[E_TEXT_ENEMY1].angular_offset = -90;

  S_GameTexture[E_TEXT_ENEMY1_MAIN_FIRE].texture = loadImageAlpha(P_ENEMY1_MAIN_FIRE,0,0,0);
  S_GameTexture[E_TEXT_ENEMY1_MAIN_FIRE].angular_offset = 90;

  S_GameTexture[E_TEXT_P_BOSS_LIFE].texture = loadImageAlpha(P_BOSS_LIFE,0,0,0);
  S_GameTexture[E_TEXT_P_BOSS_LIFE].angular_offset = 90;

  S_GameTexture[E_TEXT_EXPLOSION_SPRITES].texture = loadImage(P_EXPLOSION_SPRITES);
  S_GameTexture[E_TEXT_EXPLOSION_SPRITES].angular_offset = 0;

}


void drawPolygon(SA_Point ul, SA_Point ur, SA_Point br, SA_Point bl)
{
  SDL_RenderDrawLine(getRenderer(),ul.x, ul.y, ur.x, ur.y);
  SDL_RenderDrawLine(getRenderer(),ur.x, ur.y, br.x, br.y);
  SDL_RenderDrawLine(getRenderer(),br.x, br.y, bl.x, bl.y);
  SDL_RenderDrawLine(getRenderer(),bl.x, bl.y, ul.x, ul.y);
}


void requestExplosion(SA_Rect position)
{
  // Creation of an explosion element. It will be destroyed by endExplosion() function.
  Explosion *ex;
  ex = malloc(sizeof(Explosion));
  ex->pos           = position;
  /* Position given is no longer the center but the one in upper left corner  */
  ex->pos.x         = position.x - position.w / 2.f;
  ex->pos.y         = position.y - position.h / 2.f;
  
  ex->previous_tick = 0;
  ex->collision_id  = 0;

  // Add it at the beginning of list
  ex->next = getExplosionList();
  // Update list pointer
  updateExplosionList(ex);
}


void endExplosion(Explosion *ex)
{
  Explosion *pl_ex = getExplosionList();

  if (pl_ex == ex )
  {
    updateExplosionList(pl_ex->next);
    free(ex);
    return;
  }

  while ( pl_ex->next != NULL )
  {
    if ( pl_ex->next == ex )
    {
      pl_ex->next = ex->next; // Raccordement
      free(ex);
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
  /* If no explosion required */
  if ( NULL == pl_ex )
    return;
  
  int tick = Keybord_getTick() /*SDL_GetTicks()*/;
  while ( pl_ex != NULL )
  {
    /* Update Explosion sprite to draw depending on frequency */
    if (tick - pl_ex->previous_tick > EXPLOSION_FREQUENCY )
    {
      pl_ex->previous_tick = tick;
      pl_ex->collision_id ++;
    

      if ( pl_ex->collision_id > EXPLOSION_NB)
      {
        endExplosion(pl_ex);
        pl_ex = pl_ex->next;
        continue;
      }
    }

    /* Where is the sprite drew on image */
    SDL_Rect sprite;
    /*   - Upper left corner position     */
    sprite.x = EXPLOSION_SPRITE_SQUARE * ((pl_ex->collision_id-1)%5);
    sprite.y = EXPLOSION_SPRITE_SQUARE * ((pl_ex->collision_id-1)/5);
    /*   - Sprite square length and width */
    sprite.w = EXPLOSION_SPRITE_SQUARE;
    sprite.h = EXPLOSION_SPRITE_SQUARE;

    /* Where the sprite will be draw on game Window */
    /*   - Coordinates = SA Element */
    SDL_Rect texture_ex = SA_to_SDL_Rect(pl_ex->pos);
    /*   - Scale = Sprite           */
    /*texture_ex.w = EXPLOSION_SPRITE_SQUARE;
    texture_ex.h = EXPLOSION_SPRITE_SQUARE;*/

    /* Rotation Sprite center */
    SDL_Point center;
    center.x = round(texture_ex.w / 2.f);
    center.y = round(texture_ex.h / 2.f);

    /* Drawing */
    if ( 0 > SDL_RenderCopyEx( getRenderer(),
                               S_GameTexture[E_TEXT_EXPLOSION_SPRITES].texture,
                               &sprite,
                               &texture_ex,
                               S_GameTexture[E_TEXT_EXPLOSION_SPRITES].angular_offset,
                               &center,
                               SDL_FLIP_NONE ) 
       )
    {
      printf("Error while drawing explosion. SDL Error : %s\n", SDL_GetError());
      break;
    }
   

    pl_ex = pl_ex->next;
  }
}



void Graphics_clean(void)
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


void Graphics_drawSATexture(SpaceAttack_te_texture txt_id, SA_Rect pos, double angle)
{
  SDL_Rect src_texture = SA_to_SDL_Rect(pos);
  src_texture.x = 0;
  src_texture.y = 0;
  /* Select a portion of source sprite
  src_texture.w = src_texture.w / 2; 
  src_texture.h = src_texture.h / 2; */

  SDL_Rect dest_texture = SA_to_SDL_Rect(pos);
  dest_texture.x -= pos.w / 2;
  dest_texture.y -= pos.h / 2;
  /* Scaling the texture simply by setting the width and height
  dest_texture.w -= pos.w / 4;
  dest_texture.h -= pos.h / 4; */

  SDL_Point center;
  center.x = dest_texture.w / 2; //round(pos.w / 2.f);
  center.y = dest_texture.h/ 2; //round(pos.h / 2.f);

  if (0 > SDL_RenderCopyEx( getRenderer(), 
                            S_GameTexture[txt_id].texture, 
                            &src_texture,   /* Source Rect*/
                            &dest_texture,  /* Destination Rect*/
                            round(angle + S_GameTexture[txt_id].angular_offset), 
                            &center, 
                            SDL_FLIP_NONE )
     )
  {
    printf("Error while drawing element. SDL Error : %s\n", SDL_GetError());
    Game_stop();
    return;
  }
  // Graphics_drawPoint(pos.x, pos.y);
}


void Graphics_drawPoint(int x, int y)
{
  SDL_Rect dest;
  int size = 3;
  dest.x = x - size/2;
  dest.y = y - size/2;
  dest.w = size;
  dest.h = size;
  SDL_RenderCopy( getRenderer(),
                  S_GameTexture[E_TEXT_P_BOSS_LIFE].texture, 
                  NULL, 
                  &dest );
}


static void Graphics_drawTexture(SDL_Texture *image, int x, int y, int angle)
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
    Game_stop();
    return;
  }
}

