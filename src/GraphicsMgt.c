#include "GraphicsMgt.h"
#include <unistd.h>

SpaceAttack_Texture spTexture;

static Explosion *explosionListe = NULL;

Explosion *getExplosionList() { return explosionListe; }
void updateExplosionList(Explosion *ex) { explosionListe = ex; }

SpaceAttack_Texture getSPTexture() { return spTexture; }


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


void loadGraphics(void)
{
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
}


void drawPolygon(Polygon *poly)
{
  SDL_RenderDrawLine(getRenderer(),poly->ul.x, poly->ul.y, poly->ur.x, poly->ur.y);
  SDL_RenderDrawLine(getRenderer(),poly->ur.x, poly->ur.y, poly->br.x, poly->br.y);
  SDL_RenderDrawLine(getRenderer(),poly->br.x, poly->br.y, poly->bl.x, poly->bl.y);
  SDL_RenderDrawLine(getRenderer(),poly->bl.x, poly->bl.y, poly->ul.x, poly->ul.y);
}


void drawBBox(Pelement el)
{
  int ex = el->pos.x;
  int ey = el->pos.y;
  int i;

  Polygon *poly_el = polygonsToWorld(el);

  //printf("nb bbox = %d\n",el->bbox.nb_box);
  for(i = 0; i < el->bbox.nb_box; i++)
  {
    SDL_RenderDrawLine(getRenderer(),poly_el[i].ul.x, poly_el[i].ul.y, poly_el[i].ur.x, poly_el[i].ur.y);
    SDL_RenderDrawLine(getRenderer(),poly_el[i].ur.x, poly_el[i].ur.y, poly_el[i].br.x, poly_el[i].br.y);
    SDL_RenderDrawLine(getRenderer(),poly_el[i].br.x, poly_el[i].br.y, poly_el[i].bl.x, poly_el[i].bl.y);
    SDL_RenderDrawLine(getRenderer(),poly_el[i].bl.x, poly_el[i].bl.y, poly_el[i].ul.x, poly_el[i].ul.y);
  }
}

void RequestExplosion(SDL_Rect position)
{
  // Creation of an explosion element
  Explosion *ex;
  ex = malloc(sizeof(Explosion));
 
  ex->pos = position;
  ex->previous_tick = 0;
  ex->collision_id = 0;  
  //ex->next = NULL;

  // Add it at the beginning of list
  ex->next = getExplosionList();
  updateExplosionList(ex);
  // Find last elemen from list
  /*while ( pl_explosion->next != NULL )
  {
    pl_explosion = pl_explosion->next;
  }
  pl_explosion->next = &ex;*/
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


void drawExplosion ()
{
  Explosion *pl_ex = getExplosionList();
  if ( NULL == pl_ex )
    return;

  while ( pl_ex != NULL )
  {

    int tick = SDL_GetTicks();
    printf("Explosion tick : %d\n",tick);

    if ( SDL_GetTicks() - pl_ex->previous_tick > EXPLOSION_FREQUENCY )
    {
      printf("Explosion tjrs ok\n");

      SDL_Rect texture_ex = pl_ex->pos;
      SDL_QueryTexture(spTexture.explosions[pl_ex->collision_id], NULL, NULL, &texture_ex.w, &texture_ex.h);
      
      SDL_Point center;
      center.x = texture_ex.w / 2;
      center.y = texture_ex.h / 2;

      if (SDL_RenderCopyEx(getRenderer(),spTexture.explosions[pl_ex->collision_id],NULL,&texture_ex,90,&center,SDL_FLIP_NONE) < 0)
      {
        printf("Error while drawing explosion. SDL Error : %s\n", SDL_GetError());
        return;
      }

      pl_ex->previous_tick = SDL_GetTicks();
      pl_ex->collision_id ++;
    }
    
    if ( NB_EXPLOSION == pl_ex->collision_id  )
    {
      EndExplosion(pl_ex);
    }
    pl_ex = pl_ex->next;


  }

}


void drawGraphics(void)
{
  // Draw background
  drawElement(getMap());
  // Draw missile
  Pelement pl_fire = getFireList();
  while(pl_fire != NULL)
  {
    drawElement(pl_fire);
    drawBBox(pl_fire);
    pl_fire = pl_fire->next;
  }
  // Draw enemy ship
  Pelement pl_en = getEnemy1List();
  while(pl_en != NULL)
  {
    drawElement(pl_en);
    drawBBox(pl_en);
    pl_en = pl_en->next;
  }
  // Draw gamer ship
  drawElement(getShip());
  drawBBox(getShip());
  drawExplosion();
  // Set red render for Bounding box dsplay
  SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
}


void cleanGraphics(void)
{
  // Libère la texture du background
  if (spTexture.background != NULL)
    SDL_DestroyTexture(spTexture.background);

  if (spTexture.ship != NULL)
    SDL_DestroyTexture(spTexture.ship);

  if (spTexture.shipFire != NULL)
    SDL_DestroyTexture(spTexture.shipFire);
}


void drawElement(Pelement el)
{
  SDL_Point center;
  center.x = el->pos.w / 2;
  center.y = el->pos.h / 2;

  SDL_Rect texture_pos = el->pos;
  texture_pos.x -= el->pos.w / 2;
  texture_pos.y -= el->pos.h / 2;

  if (SDL_RenderCopyEx(getRenderer(),el->txt,NULL,&texture_pos,round(el->angle)+90,&center,SDL_FLIP_NONE) < 0)
  {
    printf("Error while drawing element. SDL Error : %s\n", SDL_GetError());
    stopGame();
    return;
  }
  
  SDL_Texture *image = (getSPTexture()).bossLife;
  SDL_Rect dest;
  int size=3;
  dest.x=el->pos.x;
  dest.y=el->pos.y;
  dest.w=size;
  dest.h=size;
  SDL_RenderCopy(getRenderer(), image, NULL, &dest);

}


void drawTexture(SDL_Texture *image, int x, int y, int angle)
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

  //SDL_RenderCopy(getRenderer(), image, NULL, &dest);

  if (SDL_RenderCopyEx(getRenderer(),image,NULL,&dest,round(angle)+90,&center,SDL_FLIP_NONE) < 0)
  {
    printf("Error when rotate on left. SDL Error : %s\n", SDL_GetError());
    stopGame();
    return;
  }
}
