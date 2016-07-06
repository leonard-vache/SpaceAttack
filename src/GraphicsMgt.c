#include "GraphicsMgt.h"

SpaceAttack_Texture spTexture;

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
  spTexture.ship = loadImageAlpha(P_SHIP,255,0,255);
  spTexture.shipFire = loadImageAlpha(P_SHIP_FIRE,0,0,0);
  spTexture.enemy1 = loadImageAlpha(P_ENEMY1,0,0,0);
  spTexture.bossLife = loadImageAlpha(BOSS_LIFE,0,0,0);
}


void drawPolygone(Polygone *poly)
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

  //printf("nb bbox = %d\n",el->bbox.nb_box);
  for(i = 0; i < el->bbox.nb_box; i++)
  {
    SDL_Point ul = SA_Point_to_SDL(el->bbox.box[i].ul);
    SDL_Point ur = SA_Point_to_SDL(el->bbox.box[i].ur);
    SDL_Point bl = SA_Point_to_SDL(el->bbox.box[i].bl);
    SDL_Point br = SA_Point_to_SDL(el->bbox.box[i].br);

    //printf("pos=(%d,%d) ul=(%d,%d) ur=(%d,%d) bl=(%d,%d) br=(%d,%d)\n",ex,ey, ul.x, ul.y, ur.x, ur.y, bl.x, bl.y, br.x, br.y);
    SDL_RenderDrawLine(getRenderer(),ul.x + ex, ul.y + ey, ur.x + ex, ur.y + ey);
    SDL_RenderDrawLine(getRenderer(),ur.x + ex, ur.y + ey, br.x + ex, br.y + ey);
    SDL_RenderDrawLine(getRenderer(),br.x + ex, br.y + ey, bl.x + ex, bl.y + ey);
    SDL_RenderDrawLine(getRenderer(),bl.x + ex, bl.y + ey, ul.x + ex, ul.y + ey);
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
    printf("Error when rotate on left. SDL Error : %s\n", SDL_GetError());
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
