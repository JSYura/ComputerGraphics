#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  bool hit_flag = false;
  for (int i = 0; i <objects.size(); i++){
      double iter_t;
      Eigen::Vector3d iter_n;
      if ((*objects[i]).intersect(ray, min_t, iter_t, iter_n) && min_t <= iter_t){
        if (hit_flag && iter_t < t){
            t = iter_t;
            n = iter_n;
            hit_id = i;
        }
        if (not hit_flag){
            hit_flag = true;
            t = iter_t;
            n = iter_n;
            hit_id = i;
        }
      }
  }
  return hit_flag;
  ////////////////////////////////////////////////////////////////////////////
}

