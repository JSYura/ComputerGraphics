#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  n = normal;

  if (n.dot(ray.direction) == 0) {
    return false;
  }

  t = n.dot(point - ray.origin) / (n.dot(ray.direction));
  return (t >= min_t);
  ////////////////////////////////////////////////////////////////////////////
}

