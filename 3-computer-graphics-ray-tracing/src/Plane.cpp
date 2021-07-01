#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
//  return false;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d d = ray.direction;
  n = normal;
  Eigen::Vector3d p_0 = point;
  if (n.dot(d) == 0) {
      return false;
  }
  double result_t = (-1)*(n.dot(e-p_0))/(n.dot(d));
  if (result_t >= min_t){
      t = result_t;
      return true;
  }
  return false;

  ////////////////////////////////////////////////////////////////////////////
}

