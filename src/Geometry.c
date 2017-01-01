#include "Geometry.h"


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


