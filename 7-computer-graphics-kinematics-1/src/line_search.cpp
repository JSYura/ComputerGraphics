#include "line_search.h"
#include <iostream>

double line_search(
  const std::function<double(const Eigen::VectorXd &)> & f,
  const std::function<void(Eigen::VectorXd &)> & proj_z,
  const Eigen::VectorXd & z,
  const Eigen::VectorXd & dz,
  const double max_step)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
//  return 0;
  double new_max_step;
  Eigen::VectorXd new_z;

  new_max_step = max_step;
  new_z = z - (new_max_step * dz);
  proj_z(new_z);
  while (f(z) < f(new_z)){
      new_max_step = 0.5 * new_max_step;
      new_z = z - new_max_step * dz;
      proj_z(new_z);
      if (z == new_z) return 0;
  }
  return new_max_step;

  /////////////////////////////////////////////////////////////////////////////
}
