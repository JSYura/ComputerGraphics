#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"
#include <Eigen/Dense>

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
//  return false;
  int hit_id;
  return first_hit(ray, min_t, triangles, hit_id, t, n);
  ////////////////////////////////////////////////////////////////////////////
}



