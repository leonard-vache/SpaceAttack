#ifndef ELEMENT_H
#define ELEMENT_H

#include "Common.h"
#include "Geometry.h"
#include "GraphicsMgt.h"
#include "Collision.h"


typedef struct element *Pelement;

// Pointeur sur fonction update**ListMotion ou set**BoundingBox. 
// Toutes les fonctions qui retourne void + prenne en argument Pelement
typedef void (*ptrFunctionPelement)(Pelement);


typedef struct element 
{
  SpaceAttack_te_texture texture_id;  // Texture element representation
	float speed[2];                     // vecteur Vitesse : speed[0] = v (lineaire)   speed[1] = w (angulaire)
  SDL_Rect pos;
  double angle;
  BoundingBox bbox;
	Pelement next;
} Element;



extern Pelement getMap();
extern void updateMap(Pelement mp);

extern Pelement getShip();
extern void updateShip(Pelement sh);

extern Pelement getFireList();
extern void updateFireList(Pelement fl);

extern Pelement getEnemy1List();
extern void updateEnemy1List(Pelement el);


Pelement createElement(SpaceAttack_te_texture txt_id, SDL_Rect p, int v, int w, double angle, unsigned short int nb_box, 
  ptrFunctionBoundingBox setBBox);
Pelement addElement(Pelement pliste, Pelement el);
Pelement extract(Pelement pliste, Pelement el);

void deleteListOfElement(Pelement pliste);
bool isElementsCollision(Pelement el1, Pelement el2);
void moveElementOutOfRange(Pelement el);

#endif
