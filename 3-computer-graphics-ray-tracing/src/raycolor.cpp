#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  rgb = Eigen::Vector3d(0,0,0);

  // use of first hit
  int hit_id;
//  double min_t;
  double t;
  Eigen::Vector3d n;
  if (first_hit(ray, min_t, objects, hit_id, t, n)){
      rgb = blinn_phong_shading(ray, hit_id, t, n, objects, lights);
      if (num_recursive_calls < 4){
          Ray r;
          r.origin = ray.origin + t * ray.direction;
          r.direction = reflect(ray.direction, n);
          Eigen::Vector3d r_rgb;
          if (raycolor(r, 1e-6, objects, lights, num_recursive_calls+1, r_rgb)){
              rgb += (objects.at(hit_id)->material->km.array() * r_rgb.array()).matrix();
          }
      }
      return true;

  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
