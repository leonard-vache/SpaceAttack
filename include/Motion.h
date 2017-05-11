#ifndef MOTION_H
#define MOTION_H

#include "Geometry.h"

typedef struct 
{
  SA_Point speed;
  SA_Rect  pos;
  double   angle;
} Motion;



void circularPattern(Motion *m);
void sinusoidalPattern(Motion *m);
void followerPattern(Motion toFollow, Motion *m);

void updateMotion (Motion *m);




#endif  /* MOTION */

