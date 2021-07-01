#include "ray_intersect_box.h"
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
    Eigen::Vector3d corner_min, corner_max, direction, tmin, tmax;

    for (int i = 0; i <= 2; i++) {
        corner_min[i] = box.min_corner[i];
        corner_max[i] = box.max_corner[i];
        direction[i] = 1 / ray.direction[i];
    }

    for (int i = 0; i <= 2; i++) {
        if(direction[i] >= 0){
            tmin[i] = direction[i] * (corner_min[i] - ray.origin[i]);
            tmax[i] = direction[i] * (corner_max[i] - ray.origin[i]);
        }
        else{
            tmin[i] = direction[i] * (corner_max[i] - ray.origin[i]);
            tmax[i] = direction[i] * (corner_min[i] - ray.origin[i]);
        }
    }

    double final_tmax = std::min({tmax[0], tmax[1], tmax[2]});
    double final_tmin = std::max({tmin[0], tmin[1], tmin[2]});
    if (final_tmax < final_tmin) {
        return false;
    }
    return !((max_t < final_tmin) || (min_t > final_tmax));
  ////////////////////////////////////////////////////////////////////////////
}
