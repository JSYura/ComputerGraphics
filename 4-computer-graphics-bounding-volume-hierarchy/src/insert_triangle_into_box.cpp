#include "insert_triangle_into_box.h"

void insert_triangle_into_box(
  const Eigen::RowVector3d & a,
  const Eigen::RowVector3d & b,
  const Eigen::RowVector3d & c,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
    Eigen::Vector3d triangle_min, triangle_max;
    for (int i = 0; i <= 2; i++) {
        triangle_min[i] = std::min({a[i], b[i], c[i]});
        triangle_max[i] = std::max({a[i], b[i], c[i]});
        B.min_corner[i] = (B.min_corner[i] < triangle_min[i])? B.min_corner[i]:triangle_min[i];
        B.max_corner[i] = (B.max_corner[i] > triangle_max[i])? B.max_corner[i]:triangle_max[i];
    }
  ////////////////////////////////////////////////////////////////////////////
}


