#ifndef COLLISION_H
#define COLLISION_H

#include "Common.h"
#include "Geometry.h"

#define NB_BOUNDING_BOX_SHIP      2
#define NB_BOUNDING_BOX_ENEMY1    2
#define NB_BOUNDING_BOX_FIRE_SHIP 1
#define NB_BOUNDING_BOX_MAP       0

#define NB_POINTS_POLYGON         4


typedef struct Polygon 
{
  SA_Point ul;   // Upper left
  SA_Point ur;   // Upper right
  SA_Point bl;   // Bottom left
  SA_Point br;   // Bottom right
  float width;
  float height;
} Polygon;


typedef struct boundingbox
{
  unsigned short int nb_box;
  Polygon *box;
  float previous_angle;
  //void (*init_bbox)(Pelement);
} BoundingBox;

// Pointeur sur fonction set**BoundingBox. 
// Toutes les fonctions qui retourne void + prenne en argument BoundingBox *
typedef void (*ptrFunctionBoundingBox)(BoundingBox *);


void setMapBoundingBox(BoundingBox *map_box);
void setShipFireBoundingBox(BoundingBox *fire_box);
void setEnemy1BoundingBox(BoundingBox *en_box);
void setShipBoundingBox(BoundingBox *shp_box);

//Polygon *polygonsToWorld(Pelement el);
BoundingBox boundingBoxToWorld(BoundingBox bbox_ref, SDL_Rect pos);
void printPolygon(Polygon poly);
void rotatePoint(SA_Point *p, float theta);
void rotatePolygon(Polygon *poly, float delta_angle);
void updateBoundingBox(BoundingBox *bbox, double el_angle);

bool isPolygonsCollision(Polygon p1, Polygon p2);



#endif 