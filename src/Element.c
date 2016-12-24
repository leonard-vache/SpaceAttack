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



SA_Point sum_SA_Point(SA_Point sa1, SA_Point sa2)
{
  SA_Point sum;
  sum.x = sa1.x + sa2.x;
  sum.y = sa1.y + sa2.y;

  return sum;
}

SA_Point SDL_to_SA_Point(SDL_Point sdl_p)
{
  SA_Point sa_p;
  sa_p.x = (float) sdl_p.x;
  sa_p.y = (float) sdl_p.y;

  return sa_p;
}

SA_Point SDL_Rect_to_SA_Point(SDL_Rect sdl_r)
{
  SA_Point sa_p;
  sa_p.x = (float) sdl_r.x;
  sa_p.y = (float) sdl_r.y;

  return sa_p;
}

void SA_Point_to_SDL_World(SA_Point *sa_p, SDL_Rect sdl_r)
{

  sa_p->x += (float)sdl_r.x;
  sa_p->y = (float)sdl_r.y + sa_p->y;
}

SDL_Point SA_Point_to_SDL(SA_Point sa_p)
{
  SDL_Point sdl_p;
  sdl_p.x = round(sa_p.x);
  sdl_p.y = round(sa_p.y);

  return sdl_p;
}

Polygon *polygonsToWorld(Pelement el)
{
  Polygon *poly = (Polygon*)malloc(el->bbox.nb_box * sizeof(Polygon));
  int i;
  for (i = 0; i < el->bbox.nb_box; i++)
  {
    poly[i] = el->bbox.box[i];
    //poly[i].width = el->bbox.box[i].width,
    //poly[i].height = el->bbox.box[i].height;
    /*
    poly[i].ul = SA_Point_to_SDL_World(poly[i].ul, el->pos);
    poly[i].ur = SA_Point_to_SDL_World(poly[i].ur, el->pos);
    poly[i].bl = SA_Point_to_SDL_World(poly[i].bl, el->pos);
    poly[i].br = SA_Point_to_SDL_World(poly[i].br, el->pos);
    */
    SA_Point_to_SDL_World(&poly[i].ul, el->pos);
    SA_Point_to_SDL_World(&poly[i].ur, el->pos);
    SA_Point_to_SDL_World(&poly[i].bl, el->pos);
    SA_Point_to_SDL_World(&poly[i].br, el->pos);
    //printf("%s \n",__FUNCTION__);
    
  }
 // printf("\n");
  return poly;
}

// Création + Initialisation d'un élément
Pelement createElement(SpaceAttack_te_texture txt_id, SDL_Rect p, int v, int w, double angle, unsigned short int nb_box, 
  ptrFunction setBBox)
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
  setBBox(el);
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
