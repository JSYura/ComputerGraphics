#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // r = 2(n.l)n - l
  Eigen::Vector3d r = ((-1) * (2 * (n.dot(in)) * n - in)).normalized();
  return r;
  ////////////////////////////////////////////////////////////////////////////
}
