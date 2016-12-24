#ifndef ELEMENT_H
#define ELEMENT_H

#include "Common.h"
#include "GraphicsMgt.h"

typedef struct element *Pelement;

// Pointeur sur fonction update**ListMotion ou set**BoundingBox. 
// Toutes les fonctions qui retourne void + prenne en argument Pelement
typedef void (*ptrFunction)(Pelement);
 


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


Polygon *polygonsToWorld(Pelement el);

SA_Point SDL_to_SA_Point(SDL_Point sdl_p);

SDL_Point SA_Point_to_SDL(SA_Point sa_p);

Pelement createElement(SpaceAttack_te_texture txt_id, SDL_Rect p, int v, int w, double angle, unsigned short int nb_box, 
  ptrFunction setBBox);

Pelement addElement(Pelement pliste, Pelement el);

Pelement extract(Pelement pliste, Pelement el);

void deleteListOfElement(Pelement pliste);

#endif
