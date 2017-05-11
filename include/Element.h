#ifndef ELEMENT_H
#define ELEMENT_H

#include "Common.h"
#include "Geometry.h"
#include "Motion.h"
#include "GraphicsMgt.h"
#include "Collision.h"

#define ELEMENT_MAX_WEAPON 5


typedef struct element *Pelement;


// Pointeur sur fonction update**ListMotion ou set**BoundingBox. 
// Toutes les fonctions qui retourne void + prenne en argument Pelement
typedef void (*ptrFunctionPelement)(Pelement);

typedef enum 
{
  E_WEAPON_MAIN,
  E_WEAPON_SECONDARY_LEFT,
  E_WEAPON_SECONDARY_RIGHT,
  E_WEAPON_NB
} te_Weapon_id;

typedef struct
{
  SpaceAttack_te_texture weaponTexture;
  ptrFunctionBoundingBox setWeaponBBox;
  bool                   isActive;
  unsigned int           fireRate;
  unsigned int           damage;
  unsigned int           previousFire;
  double                 fireSpeed;
  /* Absolute position onto Element */
  SA_Rect                spot;

} ts_Weapon_descriptor;

typedef struct
{
  ts_Weapon_descriptor desc[E_WEAPON_NB];
  /* Missils Lists*/
  Pelement             missiles;
} ts_Weapon;

typedef struct element 
{
  SpaceAttack_te_texture texture_id;  // Element representation
  Motion  mov;
  int life;
  BoundingBox bbox;
  ts_Weapon   weapon;
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


Pelement createElement(SpaceAttack_te_texture txt_id, 
                       SA_Rect p, double v, double w, double angle, 
                       int life,
                       unsigned short int nb_box, ptrFunctionBoundingBox setBBox);
Pelement addElement(Pelement pliste, Pelement el);
Pelement extract(Pelement pliste, Pelement el);

void Element_deleteList(Pelement pliste);
bool isElementsCollision(Pelement el1, Pelement el2);
void Element_collectGarbage(Pelement list, ptrFunctionPelement updateList);

#endif
