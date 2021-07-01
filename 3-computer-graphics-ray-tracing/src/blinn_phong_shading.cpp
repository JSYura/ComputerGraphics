#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
//  return Eigen::Vector3d(0,0,0);

  // L = L_a + L_d + L_s
  //   = k_a * I_a + k_d * (I/r^2) * max(0, n*l) + k_s * (I/r^2) * max(0, n*h)^p
  Eigen::Vector3d output(0,0,0);

  Eigen::Vector3d k_a = objects[hit_id] -> material -> ka;
  Eigen::Vector3d k_d = objects[hit_id] -> material -> kd;
  Eigen::Vector3d k_s = objects[hit_id] -> material -> ks;
  Eigen::Vector3d I_a = Eigen::Vector3d (0.1,0.1,0.1);
  double p = objects[hit_id]->material->phong_exponent;

  // l=light.pos-position;
  // shadowray=(point,l);
  Ray sd_ray;
  int sd_hit_id;
  double sd_t;
  Eigen::Vector3d sd_n;
  double max_t;

  for (int i = 0; i < lights.size(); i++){
      sd_ray.origin = ray.origin + t * ray.direction;
      lights.at(i) -> direction(sd_ray.origin, sd_ray.direction, max_t);

      if (first_hit(sd_ray, 1e-6, objects, sd_hit_id, sd_t, sd_n) && max_t > sd_t){
          continue;
      }

      // L_d
      // k_d * (I/r^2) * max(0, n*l)
      output += (k_d.array() * (lights.at(i)->I).array()).matrix() * std::max(0.0, n.dot(sd_ray.direction));

      // L_s
      // k_s * (I/r^2) * max(0, n*h)^p
      Eigen::Vector3d h = (-ray.direction.normalized() + sd_ray.direction.normalized()).normalized();
      output += (k_s.array() * (lights.at(i)->I).array()).matrix() * std::pow(std::max(0.0, n.dot(h)), p);

  }

  // L_a
  output += (k_a.array() * I_a.array()).matrix();
  return output;

  ////////////////////////////////////////////////////////////////////////////
}
