#include "Motion.h"


void circularPattern(Motion *m)
{
  m->speed.x = 5.f;
  printf("x=%f - y=%f\n",m->pos.x,m->pos.y);
}



void sinusoidalPattern(Motion *m)
{
  static double sinusoidal_angle = 0.f;
  double sinusoidal_speed = 5.f;

  m->speed.y = sinusoidal_speed * cos(sinusoidal_angle*M_PI/180);

  printf("sinusoidal_angle=%f - m->speed.y=%f - m->angle=%f\n",sinusoidal_angle, m->speed.y*sin(sinusoidal_angle*M_PI/180), m->angle);
  sinusoidal_angle = fmod(sinusoidal_angle + sinusoidal_speed, 360.f);
}


void followerPattern(Motion toFollow, Motion *m)
{
  // Vecteur en direction de la cible 
  SA_Rect direction_target = SA_Rect_subtraction(toFollow.pos, m->pos);
  double  angle_target     = atan2(direction_target.y, direction_target.x) * 180.f/M_PI; 

  // Repasse l'angle sur l'intervalle [0;360]
  angle_target = fmod(angle_target + 360.f, 360.f);
  double enemy = fmod(m->angle + 360.f, 360.f);

  double error = angle_target - enemy;
  if (error > 180)
  {
    error = fmod(error, 180.f) -180.f;
  }
  // printf("error(%f) = angle_target(%f) - enn->angle(%f=%f) \n", error, angle_target, enn->angle, enemy);
  m->speed.y = ENEMY1_ANGULAR_VELOCITY * error / 180.f;
  m->speed.x = ENEMY1_LINEAR_VELOCITY;
}


void updateMotion (Motion *m)
{
  /* Update Motion */
  m->angle  = fmod(m->angle + ADAPT_TO_FPS(m->speed.y), 360.f);
  m->pos.y += sin(m->angle*M_PI/180) * ADAPT_TO_FPS(m->speed.x);
  m->pos.x += cos(m->angle*M_PI/180) * ADAPT_TO_FPS(m->speed.x);
}