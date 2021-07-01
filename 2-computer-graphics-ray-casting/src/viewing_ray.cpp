#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ray.origin = camera.e;

  double u_j = (camera.width/width)*(j+0.5)-(camera.width/2);
  //since topleft
  double v_i = -((camera.height/height)*(i+0.5)-(camera.height/2));
  double new_d = -camera.d;

  ray.direction = camera.u*u_j + camera.v*v_i + new_d*camera.w;

    ////////////////////////////////////////////////////////////////////////////
}

