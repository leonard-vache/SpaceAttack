#include "opstruct.h"


SDL_Point SA_Point_to_SDL(SA_Point sa_p)
{
  SDL_Point sdl_p;
  sdl_p.x = round(sa_p.x);
  sdl_p.y = round(sa_p.y);

  return sdl_p;
}

// Création + Initialisation d'un élément
Pelement create(SDL_Texture *t, SDL_Rect p, int v, int w, float angle, unsigned short int nb_box, 
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
  el->txt = t;
  el->speed[0] = v;
  el->speed[1] = w;
  el->angle = angle;


  if(SDL_QueryTexture(t, NULL, NULL, &(el->pos.w), &(el->pos.h)) < 0) 
  {
    printf("Can not get texture dimension ! SDL_Error : %s", SDL_GetError());
    stopGame();
  }
  el->pos.x = p.x;
  el->pos.y = p.y;

  el->bbox.nb_box = nb_box;
  el->bbox.box = (Polygone*)malloc(nb_box * sizeof(Polygone));
  el->bbox.previous_angle = -90.0;
  setBBox(el);
  //el->bbox.init_bbox = setBBox;
  
  el->next = NULL;
  return el;
}



Pelement add(Pelement pliste, Pelement el){ // Ajout de l'élément au début de la liste
	    
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



void delete_all(Pelement pliste) // Suppression de la liste entière
{ 
	Pelement p = pliste, pel = NULL;
	while(p != NULL)
  {
		pel = p;
		p = p->next;
    //unsigned short int i;
    //for(i = 0; i < pel->bbox.nb_box; i++)
    free(pel->bbox.box);
		free(pel);
	}
}
