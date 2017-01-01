#include "Element.h"

// Game Objects
static Pelement map = NULL;
static Pelement ship = NULL;
static Pelement fireList = NULL;
static Pelement enemy1List = NULL;

//int adaptToFPS(float value) { return 60 / (round(60.0 * FPS / value) / FPS); }

Pelement getMap() { return map; }
void updateMap(Pelement mp) { map = mp; }

Pelement getShip() { return ship; }
void updateShip(Pelement sh) { ship = sh; }

Pelement getFireList() { return fireList; }
void updateFireList(Pelement fl) { fireList = fl; }

Pelement getEnemy1List() { return enemy1List; }
void updateEnemy1List(Pelement el) { enemy1List = el; }


// Création + Initialisation d'un élément
Pelement createElement(SpaceAttack_te_texture txt_id, SDL_Rect p, int v, int w, double angle, unsigned short int nb_box, 
  ptrFunctionBoundingBox setBBox)
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
  //el->txt = t;
  el->speed[0] = v;
  el->speed[1] = w;
  el->angle = angle;

  // Fill heigth and width field from texture
  getTextureDimension(txt_id, &(el->pos) );
  el->pos.x = p.x;
  el->pos.y = p.y;

  el->bbox.nb_box = nb_box;
  el->bbox.box = (Polygon*)malloc(nb_box * sizeof(Polygon));
  el->bbox.previous_angle = -90.0;
  // Initialize Bounding Box
  setBBox(&(el->bbox));
  //el->bbox.init_bbox = setBBox;
  
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


void deleteElement(Pelement el)
{
  free(el->bbox.box);
  free(el);
}

void deleteListOfElement(Pelement pliste) // Suppression de la liste entière
{ 
	Pelement p = pliste, pel = NULL;
	while(p != NULL)
  {
		pel = p;
		p = p->next;

    deleteElement(pel);
	}
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

  BoundingBox bbox_el1 = boundingBoxToWorld(el1->bbox, el1->pos);
  BoundingBox bbox_el2 = boundingBoxToWorld(el2->bbox, el2->pos);
  
  int i,j;
  for (i = 0; i < bbox_el1.nb_box; i++)
  {
    for (j = 0; j < bbox_el2.nb_box; j++)
    {      
      if (isPolygonsCollision(bbox_el1.box[i], bbox_el2.box[j]) || isPolygonsCollision(bbox_el2.box[j], bbox_el1.box[i]) )
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


void moveElementOutOfRange(Pelement el)
{
  el->pos.x = 2.f * SCREEN_WIDTH;
  el->pos.y = 2.f * SCREEN_HEIGHT;
}

