#include "Geometry.h"

#define OUT_OF_RANGE  10000

SA_Point SDL_to_SA_Point(SDL_Point sdl_p)
{
  SA_Point sa_p;
  sa_p.x = (double) sdl_p.x;
  sa_p.y = (double) sdl_p.y;

  return sa_p;
}

SA_Point SDL_Rect_to_SA_Point(SDL_Rect sdl_r)
{
  SA_Point sa_p;
  sa_p.x = (double) sdl_r.x;
  sa_p.y = (double) sdl_r.y;

  return sa_p;
}

void SA_Point_to_SDL_World(SA_Point *sa_p, SA_Rect sa_r)
{

  sa_p->x += sa_r.x;
  sa_p->y =  sa_r.y + sa_p->y;
}

SDL_Point SA_to_SDL_Point(SA_Point sa_p)
{
  SDL_Point sdl_p;
  sdl_p.x = round(sa_p.x);
  sdl_p.y = round(sa_p.y);

  return sdl_p;
}

SDL_Rect SA_to_SDL_Rect(SA_Rect sa_r)
{
  SDL_Rect r;
  r.x = round(sa_r.x);
  r.y = round(sa_r.y);
  r.w = round(sa_r.w);
  r.h = round(sa_r.h);

  return r;
}


SA_Rect SDL_to_SA_Rect(SDL_Rect sdl_r)
{
  SA_Rect r;
  r.x = (double)sdl_r.x;
  r.y = (double)sdl_r.y;
  r.w = (double)sdl_r.w;
  r.h = (double)sdl_r.h;

  return r;
}

SA_Rect SA_Point_to_SA_Rect(SA_Point p)
{
  SA_Rect r;
  memset(&r, 0, sizeof(SA_Point));
  r.x = p.x;
  r.y = p.y;

  return r;
}


SA_Point SA_Rect_to_SA_Point(SA_Rect r)
{
  SA_Point p;
  p.x = r.x;
  p.y = r.y;

  return p;
}

SA_Point SA_Point_subtraction(SA_Point  sa_p1, SA_Point  sa_p2) 
{
  SA_Point ret;
  ret.x = sa_p1.x - sa_p2.x;
  ret.y = sa_p1.y - sa_p2.y;

  return ret;
}

SA_Rect SA_Rect_subtraction(SA_Rect sa_r1, SA_Rect sa_r2) 
{
  SA_Rect ret;
  ret.x = sa_r1.x - sa_r2.x;
  ret.y = sa_r1.y - sa_r2.y;
  ret.w = sa_r1.w - sa_r2.w;
  ret.h = sa_r1.h - sa_r2.h;

  return ret;
}

SA_Rect SA_Rect_add(SA_Rect sa_r1, SA_Rect sa_r2) 
{
  SA_Rect ret;
  ret.x = sa_r1.x + sa_r2.x;
  ret.y = sa_r1.y + sa_r2.y;
  ret.w = sa_r1.w + sa_r2.w;
  ret.h = sa_r1.h + sa_r2.h;

  return ret;
}


void Geometry_rotatePoint(SA_Point *p, double theta)
{
  double x = p->x;
  double y = p->y;

  p->x = x * cos(theta) - y * sin(theta);
  p->y = x * sin(theta) + y * cos(theta);
}

void Geometry_rotateRect(SA_Point *r, double theta)
{
  double x = r->x;
  double y = r->y;

  r->x = x * cos(theta) - y * sin(theta);
  r->y = x * sin(theta) + y * cos(theta);
}






