#ifndef COLLISION_H
#define COLLISION_H

#include "Common.h"
#include "Prototypes.h"

#define NB_BOUNDING_BOX_SHIP 2
#define NB_BOUNDING_BOX_ENEMY1 2
#define NB_BOUNDING_BOX_FIRE_SHIP 1
#define NB_BOUNDING_BOX_MAP 0

void setMapBoundingBox(Pelement map);
void setShipFireBoundingBox(Pelement fire);
void setEnemy1BoundingBox(Pelement en);
void setShipBoundingBox(Pelement shp);

void printPolygone(Polygone poly);
void rotatePoint(SA_Point *p, float theta);
void rotatePolygone(Polygone *poly, float delta_angle);
void updateBoundingBox(Pelement el);


#endif 