#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Common.h"

typedef struct SpaceAttack_Point
{
  float x;
  float y;
} SA_Point;


SA_Point SDL_to_SA_Point(SDL_Point sdl_p);
SA_Point SDL_Rect_to_SA_Point(SDL_Rect sdl_r);
void SA_Point_to_SDL_World(SA_Point *sa_p, SDL_Rect sdl_r);
SDL_Point SA_Point_to_SDL(SA_Point sa_p);

#endif 