#ifndef COLLISION_H
#define COLLISION_H

#include "Common.h"
#include "Element.h"

#define NB_BOUNDING_BOX_SHIP      2
#define NB_BOUNDING_BOX_ENEMY1    2
#define NB_BOUNDING_BOX_FIRE_SHIP 1
#define NB_BOUNDING_BOX_MAP       0

#define NB_POINTS_POLYGON         4


void setMapBoundingBox(Pelement map);
void setShipFireBoundingBox(Pelement fire);
void setEnemy1BoundingBox(Pelement en);
void setShipBoundingBox(Pelement shp);

void printPolygon(Polygon poly);
void rotatePoint(SA_Point *p, float theta);
void rotatePolygon(Polygon *poly, float delta_angle);
void updateBoundingBox(Pelement el);

bool isPolygonsCollision(Polygon p1, Polygon p2);
bool isElementsCollision(Pelement el1, Pelement el2);
void checkCollisions();



#endif 