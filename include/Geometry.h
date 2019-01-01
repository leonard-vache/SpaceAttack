#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Common.h"

#define SIGN_D(x)  ( ((x) > 0) - ((x) < 0) )

typedef struct SpaceAttack_Point
{
  double x;
  double y;
} SA_Point;

typedef struct SpaceAttack_Rect
{
  double x;
  double y;
  double w;
  double h;
} SA_Rect;

SA_Point  SDL_to_SA_Point(SDL_Point sdl_p);
SA_Point  SDL_Rect_to_SA_Point(SDL_Rect sdl_r);

SDL_Point SA_to_SDL_Point(SA_Point sa_p);

SDL_Rect  SA_to_SDL_Rect(SA_Rect sa_r);

SA_Point SA_Rect_to_SA_Point(SA_Rect r);
SA_Rect  SA_Point_to_SA_Rect(SA_Point p);

SA_Rect   SA_Rect_subtraction(SA_Rect sa_r1, SA_Rect sa_r2);
SA_Rect   SA_Rect_add(SA_Rect sa_r1, SA_Rect sa_r2);

void      Geometry_rotatePoint(SA_Point *p, double theta);
void      Geometry_rotateRect(SA_Point *r, double theta);

void      SA_Point_to_SDL_World(SA_Point *sa_p, SA_Rect sa_r);

#endif 