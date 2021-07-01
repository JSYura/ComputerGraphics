#include "projected_gradient_descent.h"
#include "line_search.h"

void projected_gradient_descent(
  const std::function<double(const Eigen::VectorXd &)> & f,
  const std::function<Eigen::VectorXd(const Eigen::VectorXd &)> & grad_f,
  const std::function<void(Eigen::VectorXd &)> & proj_z,
  const int max_iters,
  Eigen::VectorXd & z)
{
  /////////////////////////////////////////////////////////////////////////////
  // Add your code here
  Eigen::VectorXd grad_z;
  for (int i = 0; i < max_iters; i ++){
      grad_z = grad_f(z);
      if (grad_z.norm() != 0){
          z = z - line_search(f, proj_z, z, grad_z, 53641) * grad_z;
          proj_z(z);
      }else{
          return;
      }
  }
  /////////////////////////////////////////////////////////////////////////////
}
