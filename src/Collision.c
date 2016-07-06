#include "Collision.h"
#include "math.h"


void setMapBoundingBox(Pelement map) {}

void setShipFireBoundingBox(Pelement fire)
{
  BoundingBox *fire_box = &(fire->bbox);

  if (fire_box->nb_box != NB_BOUNDING_BOX_FIRE_SHIP)
  {
    printf("Error in setShipFireBoundingBox 1 BoundingBox is expected\n");
    stopGame();
    return;
  }

  fire_box->box[0].ul.x = -fire->pos.w / 2.f;
  fire_box->box[0].ul.y = -fire->pos.h / 2.f;
  fire_box->box[0].width = (float)fire->pos.w;
  fire_box->box[0].height = (float)fire->pos.h;

  fire_box->box[0].ur.x = fire_box->box[0].ul.x + fire_box->box[0].width;
  fire_box->box[0].ur.y = fire_box->box[0].ul.y;

  fire_box->box[0].bl.x = fire_box->box[0].ul.x;
  fire_box->box[0].bl.y = fire_box->box[0].ul.y + fire_box->box[0].height;

  fire_box->box[0].br.x = fire_box->box[0].ul.x + fire_box->box[0].width;
  fire_box->box[0].br.y = fire_box->box[0].ul.y + fire_box->box[0].height;
}


void setEnemy1BoundingBox(Pelement en)
{
  BoundingBox *en_box = &(en->bbox);
  if (en_box->nb_box != NB_BOUNDING_BOX_ENEMY1)
  {
    printf("Error in setEnemy1BoundingBox 2 BoundingBox are expected\n");
    stopGame();
    return;
  }

  //                            0--->
  //                            |
  // même referentiel que sdl : v
  en_box->box[0].ul.x = -12.f;
  en_box->box[0].ul.y = 8.f;
  en_box->box[0].width = (float)20;
  en_box->box[0].height = (float)20;

  en_box->box[0].ur.x = en_box->box[0].ul.x + en_box->box[0].width;
  en_box->box[0].ur.y = en_box->box[0].ul.y;

  en_box->box[0].bl.x = en_box->box[0].ul.x;
  en_box->box[0].bl.y = en_box->box[0].ul.y + en_box->box[0].height;

  en_box->box[0].br.x = en_box->box[0].ul.x + en_box->box[0].width;
  en_box->box[0].br.y = en_box->box[0].ul.y + en_box->box[0].height;
  /*
  p_bbox1=en_box->box[0];
  printf("p_bbox1.ul=(%d,%d)\n",p_bbox1.ul.x,p_bbox1.ul.y);
  printf("p_bbox1.ur=(%d,%d)\n",p_bbox1.ur.x,p_bbox1.ur.y);
  printf("p_bbox1.bl=(%d,%d)\n",p_bbox1.bl.x,p_bbox1.bl.y);
  printf("p_bbox1.br=(%d,%d)\n",p_bbox1.br.x,p_bbox1.br.y);
  printf("p_bbox1.height=%d p_bbox1.width=%d\n",p_bbox1.height,p_bbox1.width);
  */
  en_box->box[1].ul.x = -en->pos.w / 2.f;
  en_box->box[1].ul.y = -25.f;
  en_box->box[1].width = (float)en->pos.w;
  en_box->box[1].height = 32.f;

  en_box->box[1].ur.x = en_box->box[1].ul.x + en_box->box[1].width;
  en_box->box[1].ur.y = en_box->box[1].ul.y;

  en_box->box[1].bl.x = en_box->box[1].ul.x;
  en_box->box[1].bl.y = en_box->box[1].ul.y + en_box->box[1].height;

  en_box->box[1].br.x = en_box->box[1].ul.x + en_box->box[1].width;
  en_box->box[1].br.y = en_box->box[1].ul.y + en_box->box[1].height;
}

void setShipBoundingBox(Pelement shp)
{
  BoundingBox *shp_box = &(shp->bbox);
  if (shp_box->nb_box != NB_BOUNDING_BOX_SHIP)
  {
    printf("Error in setShipBoundingBox 2 BoundingBox are expected\n");
    stopGame();
    return;
  }
  // First bounding box. Polygone point are set in ship referentiel
  shp_box->box[0].ul.x = -9.f;
  shp_box->box[0].ul.y = -20.f;
  shp_box->box[0].width = 18.f;
  shp_box->box[0].height = 17.f;

  shp_box->box[0].ur.x = shp_box->box[0].ul.x + shp_box->box[0].width;
  shp_box->box[0].ur.y = shp_box->box[0].ul.y;

  shp_box->box[0].bl.x = shp_box->box[0].ul.x;
  shp_box->box[0].bl.y = shp_box->box[0].ul.y + shp_box->box[0].height;

  shp_box->box[0].br.x = shp_box->box[0].ul.x + shp_box->box[0].width;
  shp_box->box[0].br.y = shp_box->box[0].ul.y + shp_box->box[0].height;

  // Second Bounding box
  // Remove fin from Bounding Box
  float fin = 6.f;
  shp_box->box[1].ul.x = -shp->pos.w / 2.f + fin ;
  shp_box->box[1].ul.y = -3.f;
  shp_box->box[1].width = (float)shp->pos.w - 2 * fin;
  shp_box->box[1].height = 29.f;

  shp_box->box[1].ur.x = shp_box->box[1].ul.x + shp_box->box[1].width;
  shp_box->box[1].ur.y = shp_box->box[1].ul.y;

  shp_box->box[1].bl.x = shp_box->box[1].ul.x;
  shp_box->box[1].bl.y = shp_box->box[1].ul.y + shp_box->box[1].height;

  shp_box->box[1].br.x = shp_box->box[1].ul.x + shp_box->box[1].width;
  shp_box->box[1].br.y = shp_box->box[1].ul.y + shp_box->box[1].height;
}


void rotatePoint(SA_Point *p, float theta)
{
  float x = p->x;
  float y = p->y;

  p->x = x * cos(theta) - y * sin(theta);
  p->y = x * sin(theta) + y * cos(theta);
}


void rotatePolygone(Polygone *poly, float delta_angle)
{  
  //printf("Before rotation : "); 
  //printPolygone(*poly);
  rotatePoint(&(poly->ul), delta_angle);
  rotatePoint(&(poly->ur), delta_angle);
  rotatePoint(&(poly->bl), delta_angle);
  rotatePoint(&(poly->br), delta_angle);
  //printf("After rotation : "); 
  //printPolygone(*poly);
  //printf("-----------------------------------------------------------------\n");
}

void printPolygone(Polygone poly)
{
  SA_Point ul = poly.ul, ur = poly.ur, bl = poly.bl, br = poly.br; 
  printf("ul=(%f,%f) ur=(%f,%f) bl=(%f,%f) br=(%f,%f)\n",ul.x, ul.y, ur.x, ur.y, bl.x, bl.y, br.x, br.y);
}


void updateBoundingBox(Pelement el)
{
  // X = x*cos(θ) - y*sin(θ)
  // Y = x*sin(θ) + y*cos(θ)
  int i;
  for (i = 0; i < el->bbox.nb_box; i++)
    rotatePolygone(&(el->bbox.box[i]), M_PI/180.0 * (el->angle - el->bbox.previous_angle));

  el->bbox.previous_angle = el->angle;  
}
