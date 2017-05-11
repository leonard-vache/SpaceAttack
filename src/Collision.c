#include "Collision.h"
#include "GraphicsMgt.h"



void setMapBoundingBox(BoundingBox *map_box) {}

void setShipFireBoundingBox(BoundingBox *fire_box)
{
  if (fire_box->nb_box != NB_BOUNDING_BOX_FIRE_SHIP)
  {
    printf("Error in setShipFireBoundingBox 1 BoundingBox is expected\n");
    stopGame();
    return;
  }

  SA_Rect fire;
  getTextureDimension(E_TEXT_SHIP_MAIN_FIRE, &fire);

  fire_box->box[0].ul.x = -fire.w / 2.f;
  fire_box->box[0].ul.y = -fire.h / 2.f;
  fire_box->box[0].width = (double)fire.w;
  fire_box->box[0].height = (double)fire.h;

  fire_box->box[0].ur.x = fire_box->box[0].ul.x + fire_box->box[0].width;
  fire_box->box[0].ur.y = fire_box->box[0].ul.y;

  fire_box->box[0].bl.x = fire_box->box[0].ul.x;
  fire_box->box[0].bl.y = fire_box->box[0].ul.y + fire_box->box[0].height;

  fire_box->box[0].br.x = fire_box->box[0].ul.x + fire_box->box[0].width;
  fire_box->box[0].br.y = fire_box->box[0].ul.y + fire_box->box[0].height;
}


void setEnemy1BoundingBox(BoundingBox *en_box)
{
  if (en_box->nb_box != NB_BOUNDING_BOX_ENEMY1)
  {
    printf("Error in setEnemy1BoundingBox 2 BoundingBox are expected\n");
    stopGame();
    return;
  }

  SA_Rect en;
  getTextureDimension(E_TEXT_ENEMY1, &en);

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
  en_box->box[1].ul.x = -en.w / 2.f;
  en_box->box[1].ul.y = -25.f;
  en_box->box[1].width = (double)en.w;
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

void setShipBoundingBox(BoundingBox *shp_box)
{
  if (shp_box->nb_box != NB_BOUNDING_BOX_SHIP)
  {
    printf("Error in setShipBoundingBox 2 BoundingBox are expected\n");
    stopGame();
    return;
  }

  SA_Rect shp;
  getTextureDimension(E_TEXT_SHIP, &shp);

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
  double fin = 6.f;
  shp_box->box[1].ul.x = -shp.w / 2.f + fin ;
  shp_box->box[1].ul.y = -3.f;
  shp_box->box[1].width = (double)shp.w - 2 * fin;
  shp_box->box[1].height = 29.f;

  shp_box->box[1].ur.x = shp_box->box[1].ul.x + shp_box->box[1].width;
  shp_box->box[1].ur.y = shp_box->box[1].ul.y;

  shp_box->box[1].bl.x = shp_box->box[1].ul.x;
  shp_box->box[1].bl.y = shp_box->box[1].ul.y + shp_box->box[1].height;

  shp_box->box[1].br.x = shp_box->box[1].ul.x + shp_box->box[1].width;
  shp_box->box[1].br.y = shp_box->box[1].ul.y + shp_box->box[1].height;
}


BoundingBox boundingBoxToWorld(BoundingBox bbox_ref, SA_Rect pos)
{
  BoundingBox bbox;
  bbox.nb_box = bbox_ref.nb_box;
  bbox.previous_angle = bbox_ref.previous_angle;
  bbox.box = (Polygon*)malloc(bbox.nb_box * sizeof(Polygon));

  int i;
  for (i = 0; i < bbox.nb_box; i++)
  {
    bbox.box[i] = bbox_ref.box[i];
    SA_Point_to_SDL_World(&bbox.box[i].ul, pos);
    SA_Point_to_SDL_World(&bbox.box[i].ur, pos);
    SA_Point_to_SDL_World(&bbox.box[i].bl, pos);
    SA_Point_to_SDL_World(&bbox.box[i].br, pos);
  }
  
  return bbox;
}


void rotatePolygon(Polygon *poly, double delta_angle)
{  
  Geometry_rotatePoint(&(poly->ul), delta_angle);
  Geometry_rotatePoint(&(poly->ur), delta_angle);
  Geometry_rotatePoint(&(poly->bl), delta_angle);
  Geometry_rotatePoint(&(poly->br), delta_angle);
}

void printPolygon(Polygon poly)
{
  SA_Point ul = poly.ul, ur = poly.ur, bl = poly.bl, br = poly.br; 
  printf("ul=(%f,%f) ur=(%f,%f) bl=(%f,%f) br=(%f,%f)\n",ul.x, ul.y, ur.x, ur.y, bl.x, bl.y, br.x, br.y);
}


void updateBoundingBox(BoundingBox *bbox, double el_angle)
{
  // X = x*cos(θ) - y*sin(θ)
  // Y = x*sin(θ) + y*cos(θ)
  int i;
  for (i = 0; i < bbox->nb_box; i++)
    rotatePolygon(&(bbox->box[i]), M_PI/180.0 * (el_angle - bbox->previous_angle));

  bbox->previous_angle = el_angle;  
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

      double cross_product2 = vector_cote_poly.x * vector_to_test.y - vector_cote_poly.y * vector_to_test.x;

      // Si au moins un point se trouve à gauche => en dehors du polygone => pas de collisions 
      if (cross_product2 <= 0)
        break;
      
    } // End  for (i = 0; i < NB_POINTS_POLYGON; i++)

    if (j == NB_POINTS_POLYGON)
      return true;
    
  } // End  for (i = 0; i < NB_POINTS_POLYGON; i++)

  return false;
}


