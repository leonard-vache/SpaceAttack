#ifndef OPSTRUCT_H
#define OPSTRUCT_H

#include <SDL.h>

typedef struct element *Pelement;
// Pointeur sur fonction update**ListMotion ou set**BoundingBox. 
// Toutes les fonctions qui retourne void + prenne en argument Pelement
typedef void (*ptrFunction)(Pelement);
 
typedef struct SpaceAttack_Point
{
  float x;
  float y;

} SA_Point;

typedef struct polygone 
{
  SA_Point ul;   // Upper left
  SA_Point ur;   // Upper right
  SA_Point bl;   // Bottom left
  SA_Point br;   // Bottom right
  float width;
  float height;
} Polygone;


typedef struct boundingbox
{
  unsigned short int nb_box;
  Polygone *box;
  float previous_angle;
  //void (*init_bbox)(Pelement);
} BoundingBox;

typedef struct element 
{
	SDL_Texture *txt;				// type de missile/vaisseau
	float speed[2];         // vecteur Vitesse : speed[0] = v   speed[1] = w
  SDL_Rect pos;
  float angle;
  BoundingBox bbox;
	Pelement next;
} Element;

SDL_Point SA_Point_to_SDL(SA_Point sa_p);

Pelement create(SDL_Texture *t, SDL_Rect p, int v, int w, float angle, unsigned short int nb_box, 
  ptrFunction setBBox);

Pelement add(Pelement pliste, Pelement el);

Pelement extract(Pelement pliste, Pelement el);

void delete_all(Pelement pliste);

#endif
