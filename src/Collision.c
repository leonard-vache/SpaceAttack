#include "Collision.h"
#include <math.h>


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
  en_box->box[0].width = 20.f;
  en_box->box[0].height = 20.f;

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

  rotatePolygon(&(en_box->box[0]), M_PI);
  rotatePolygon(&(en_box->box[1]), M_PI);
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
  // First bounding box. Polygon point are set in ship referentiel
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


void rotatePolygon(Polygon *poly, float delta_angle)
{  
  rotatePoint(&(poly->ul), delta_angle);
  rotatePoint(&(poly->ur), delta_angle);
  rotatePoint(&(poly->bl), delta_angle);
  rotatePoint(&(poly->br), delta_angle);
}

void printPolygon(Polygon poly)
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
    rotatePolygon(&(el->bbox.box[i]), M_PI/180.0 * (el->angle - el->bbox.previous_angle));

  el->bbox.previous_angle = el->angle;  
}


bool isPolygonsCollision(Polygon p1, Polygon p2)
{
  // Y vers le bas => Repère indirect => on tourne dans l'autre sens
  SA_Point p1_t[NB_POINTS_POLYGON] = { p1.ul, p1.ur, p1.br, p1.bl};
  SA_Point p2_t[NB_POINTS_POLYGON+1] = { p2.ul, p2.ur, p2.br, p2.bl, p2.ul};

  int i, j;
  SA_Point vector_cote_poly, vector_to_test;
  // Boucle sur les 4 points à tester
  for (i = 0; i < NB_POINTS_POLYGON; i++)
  {
    // Boucles sur les points du polygone (+ 1 pour lier le premier et le dernier coté du polygone)
    for (j = 0; j < NB_POINTS_POLYGON; j++)
    {
      // Vecteur reliant 2 points consécutifs du polygone
      vector_cote_poly.x = p2_t[j+1].x - p2_t[j].x;
      vector_cote_poly.y = p2_t[j+1].y - p2_t[j].y;
      
      // Vecteur vers le point à tester
      vector_to_test.x = p1_t[i].x - p2_t[j].x;
      vector_to_test.y = p1_t[i].y - p2_t[j].y;

      float cross_product2 = vector_cote_poly.x * vector_to_test.y - vector_cote_poly.y * vector_to_test.x;

      // Si au moins un point se trouve à gauche => en dehors du polygone => pas de collisions 
      if (cross_product2 <= 0)
        break;
      
    } // End  for (i = 0; i < NB_POINTS_POLYGON; i++)

    if (j == NB_POINTS_POLYGON)
      return true;
    
  } // End  for (i = 0; i < NB_POINTS_POLYGON; i++)

  return false;
}


bool isElementsCollision(Pelement el1, Pelement el2)
{
  // Si la distance entre deux élément est supérieur à la somme de leur diagonal, alors il ne peut avoir collision entre eux
  // Optime : on raisonne avec les distances au carré (évite l'utilisation de sqrt)
  int distance = pow(el1->pos.x - el2->pos.x,2) + pow(el1->pos.y - el2->pos.y,2);
  int min_distance_to_compute_check = pow(el1->pos.h,2) + pow(el1->pos.w,2)  // diagonale du premier element
                                    + pow(el2->pos.h,2) + pow(el2->pos.w,2); // diagonale du second element

  if (distance > min_distance_to_compute_check)
    return false;

  Polygon *poly_el1 = polygonsToWorld(el1);
  Polygon *poly_el2 = polygonsToWorld(el2);  
  
  int i,j;
  for (i = 0; i < el1->bbox.nb_box; i++)
  {
    for (j = 0; j < el2->bbox.nb_box; j++)
    {      
      if (isPolygonsCollision(poly_el1[i], poly_el2[j]) || isPolygonsCollision(poly_el2[j], poly_el1[i]) )
      {
        free(poly_el1);
        free(poly_el2);
        return true;
      }
    }
  }

  free(poly_el1);
  free(poly_el2);
  return false;
}


void moveElementOutOfRange(Pelement el)
{
  el->pos.x = 2.f * SCREEN_WIDTH;
  el->pos.y = 2.f * SCREEN_HEIGHT;
}


void checkCollisions()
{ 
    Pelement pl_to_free;

    Pelement pl_fire = getFireList();
    int compt=0;
    int nb_mis=0;
    while(pl_fire != NULL)
    {
      nb_mis++;
      updateBoundingBox(pl_fire);
      pl_fire = pl_fire->next;
    }

    updateBoundingBox(getShip());

    Pelement pl_enn = getEnemy1List();
    while(pl_enn != NULL)
    {
      compt++;
      updateBoundingBox(pl_enn);
      //Check collision between ship and enemy
      if( isElementsCollision(pl_enn, getShip()) )
      {
        RequestExplosion(pl_enn->pos);
        moveElementOutOfRange(pl_enn);
        break;
      }
      // Check Collison entre ennemy and missile
      pl_fire = getFireList();
      while(pl_fire != NULL)
      {
        if(isElementsCollision(pl_fire, pl_enn))
        {
          RequestExplosion(pl_enn->pos);
          moveElementOutOfRange(pl_enn);
          moveElementOutOfRange(pl_fire);
          break;
        }
        else 
          pl_fire = pl_fire->next;
      }
      pl_enn = pl_enn->next;
    }
}
