#include "Element.h"

// Game Objects
static Pelement map = NULL;
static Pelement ship = NULL;
static Pelement fireList = NULL;
static Pelement enemy1List = NULL;



Pelement getMap() { return map; }
void updateMap(Pelement mp) { map = mp; }

Pelement getShip() { return ship; }
void updateShip(Pelement sh) { ship = sh; }

Pelement getFireList() { return ship->weapon.missiles; }
void updateFireList(Pelement fl) { ship->weapon.missiles = fl; }

Pelement getEnemy1List() { return enemy1List; }
void updateEnemy1List(Pelement el) { enemy1List = el; }


// Create + Init a Game Element
Pelement createElement( SpaceAttack_te_texture txt_id, 
                        SA_Rect p, double v, double w, double angle, 
                        int life,
                        unsigned short int nb_box, ptrFunctionBoundingBox setBBox
                      )
{ 
	Pelement el;
	el = (Pelement) malloc(sizeof(*el));
 
  if (el == NULL)
  {
    printf("Error : element created is NULL");
    stopGame();
    return;
  }

  el->texture_id = txt_id;

  el->mov.speed.x = v;
  el->mov.speed.y = w;
  el->mov.angle   = angle;
  el->mov.pos.x   = p.x;
  el->mov.pos.y   = p.y;
  // Fill heigth and width field from texture
  getTextureDimension(txt_id, &(el->mov.pos) );

  el->life = life;

  el->bbox.nb_box = nb_box;
  el->bbox.box = (Polygon*)malloc(nb_box * sizeof(Polygon));
  el->bbox.previous_angle = -90.0;
  // Initialize Bounding Box
  setBBox(&(el->bbox));
  //el->bbox.init_bbox = setBBox;

  memset(el->weapon.desc, 0, E_WEAPON_NB * sizeof(ts_Weapon_descriptor));
  el->weapon.missiles = NULL;

  el->next = NULL;
  return el;
}



Pelement addElement(Pelement pliste, Pelement el){ // Ajout de l'élément au début de la liste
	    
  if (pliste == NULL && el == NULL)
  {
      printf("Error : list and element to add is empty\n");
      stopGame();
      return;
  }
  el->next = pliste;
  return el;
}


Pelement extract(Pelement pliste, Pelement el){ // Extraction d'un élément d'une liste, retourne l'élément extrait
	
  if (pliste == NULL)
  {
    printf("Error can not extract an empty list\n");
    stopGame();
    return;
  }
    
  Pelement pl = pliste, pe;
    
  if(pl == el ){
		pliste = pliste->next;
		return pliste;
	}	

	while(pl->next != NULL)
  {
		if(pl->next == el)
    {
			pl->next = el->next; // Raccordement
			break;
		}
		pl = pl->next;
	}
	
	return pliste;
}


void Element_delete(Pelement el)
{
  if (el->weapon.missiles != NULL)
    Element_deleteList(el->weapon.missiles);
  
  free(el->bbox.box);
  free(el);
}


void Element_deleteList(Pelement list) // Suppression de la liste entière
{ 
	Pelement p = list, toFree = NULL;
	while(p != NULL)
  {
		toFree = p;
		p = p->next;

    Element_delete(toFree);
	}
}


bool isElementsCollision(Pelement el1, Pelement el2)
{
  // Si la distance entre deux élément est supérieur à la somme de leur diagonal, alors il ne peut avoir collision entre eux
  // Optime : on raisonne avec les distances au carré (évite l'utilisation de sqrt)
  int distance = pow(el1->mov.pos.x - el2->mov.pos.x,2) + pow(el1->mov.pos.y - el2->mov.pos.y,2);
  int min_distance_to_compute_check = pow(el1->mov.pos.h,2) + pow(el1->mov.pos.w,2)  // diagonale du premier element
                                    + pow(el2->mov.pos.h,2) + pow(el2->mov.pos.w,2); // diagonale du second element

  if (distance > min_distance_to_compute_check)
    return false;

  BoundingBox bbox_el1 = boundingBoxToWorld(el1->bbox, el1->mov.pos);
  BoundingBox bbox_el2 = boundingBoxToWorld(el2->bbox, el2->mov.pos);
  
  int i,j;
  for (i = 0; i < bbox_el1.nb_box; i++)
  {
    for (j = 0; j < bbox_el2.nb_box; j++)
    {      
      if ( isPolygonsCollision(bbox_el1.box[i], bbox_el2.box[j]) || 
           isPolygonsCollision(bbox_el2.box[j], bbox_el1.box[i]) 
         )
      {
        free(bbox_el1.box);
        free(bbox_el2.box);
        return true;
      }
    }
  }

  free(bbox_el1.box);
  free(bbox_el2.box);
  return false;
}


bool Element_isOutOfMap(Pelement el)
{
  return (el->mov.pos.y > SCREEN_HEIGHT + el->mov.pos.h || 
          el->mov.pos.y < 0                             ||
          el->mov.pos.x > SCREEN_WIDTH + el->mov.pos.w  || 
          el->mov.pos.x < 0 );
}


void Element_activateWeapon( Pelement      el,
                             te_Weapon_id  weap_id )
{
  if (weap_id > ELEMENT_MAX_WEAPON)
  {
    printf("Error Weapon %d unknown\n", weap_id);
    return;
  }

  el->weapon.desc[weap_id].isActive = true;
}



void Element_shoot(Pelement el, te_Weapon_id weap_id)
{
  if (weap_id >= E_WEAPON_NB)
  {
    printf("Erreur Weapon %d unrecognize\n", weap_id);
  }


  if (el->weapon.desc[weap_id].isActive)
  { 
    if(SDL_GetTicks()-el->weapon.desc[weap_id].previousFire >= 1000.f / el->weapon.desc[weap_id].fireRate )
    {
      SA_Rect rspot;// = SA_Point_to_SA_Rect(el->weapon.desc[weap_id].spot);
      memcpy(&rspot, &el->weapon.desc[weap_id].spot, sizeof(SA_Rect));
      Geometry_rotateRect(&rspot, M_PI/180.f * el->mov.angle);
      Pelement newMissile = createElement( el->weapon.desc[weap_id].weaponTexture, 
                                           SA_Rect_add(el->mov.pos, rspot),
                                           el->weapon.desc[weap_id].fireSpeed, 
                                           0,
                                           el->mov.angle,
                                           el->weapon.desc[weap_id].damage,
                                           NB_BOUNDING_BOX_FIRE_SHIP, 
                                           el->weapon.desc[weap_id].setWeaponBBox
                                         );
      // addElement() function returns the pointer to new linked list with added element
      el->weapon.missiles                   = addElement(el->weapon.missiles, newMissile);
      el->weapon.desc[weap_id].previousFire = SDL_GetTicks();
    }
  }
  else
  {
    printf("WARNING : Weapon is not active\n");
  }
}

void Element_draw(Pelement el)
{
  int cpt_miss = 0;
  Pelement list = el;
  while (list != NULL)
  {
    cpt_miss = 0;
    Pelement miss = list->weapon.missiles;
    while (miss != NULL)
    {
      cpt_miss ++;
      drawSATexture (miss->texture_id, miss->mov.pos, miss->mov.angle);
      miss = miss->next;
    }
    drawSATexture (list->texture_id, list->mov.pos, list->mov.angle);
    list = list->next;
    printf("Nb missiles : %d\n", cpt_miss);
  }
}


void Element_updateMotion(Pelement el)
{
  Pelement list = el;
  //updateMotion(&list->mov);

  while (list != NULL)
  {
    updateMotion(&list->mov);
    if ( Element_isOutOfMap(list) )  list->life = 0;

    Pelement miss = list->weapon.missiles;
    while (miss != NULL)
    {
      updateMotion(&miss->mov); 
      if ( Element_isOutOfMap(miss) )  miss->life = 0;
      miss = miss->next;
    }
    list = list->next;
  }
}


void Element_collectGarbage(Pelement list, ptrFunctionPelement updateList)
{
  Pelement pl_prev = list;
  Pelement pl_to_free;

  while(list != NULL)
  {
    printf("Element life = %d\n",list->life);
    if (list->life <= 0 )
    {
      // First element of the list
      if(pl_prev == list)
      {
        pl_prev = list->next;
        // Call adapted function to update
       updateList(pl_prev);
      }
      else
      {
        // Link previous element with next one
        pl_prev->next = list->next;
      }
      pl_to_free = list;
      list = list->next;
      //printf("Element delete\n");
      Element_delete(pl_to_free);
      //free(pl_to_free);
    }
    else
    {
      pl_prev = list;
      list = list->next;
    }
  }
}

