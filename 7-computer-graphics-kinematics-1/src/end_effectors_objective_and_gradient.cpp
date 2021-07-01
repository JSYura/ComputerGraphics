#include "end_effectors_objective_and_gradient.h"
#include "transformed_tips.h"
#include "kinematics_jacobian.h"
#include "copy_skeleton_at.h"
#include <iostream>

void end_effectors_objective_and_gradient(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  const Eigen::VectorXd & xb0,
  std::function<double(const Eigen::VectorXd &)> & f,
  std::function<Eigen::VectorXd(const Eigen::VectorXd &)> & grad_f,
  std::function<void(Eigen::VectorXd &)> & proj_z)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  f = [&](const Eigen::VectorXd & A)->double
  {
    Skeleton skeleton_copy;
    Eigen::VectorXd tips;
    skeleton_copy = copy_skeleton_at(skeleton, A);
    tips = transformed_tips(skeleton_copy, b);
    return (tips - xb0).dot(tips - xb0);
  };
  grad_f = [&](const Eigen::VectorXd & A)->Eigen::VectorXd
  {
    Skeleton skeleton_copy;
    Eigen::VectorXd tips;
    Eigen::MatrixXd J;
    skeleton_copy = copy_skeleton_at(skeleton, A);
    tips = transformed_tips(skeleton_copy, b);
    kinematics_jacobian(skeleton_copy, b, J);
    return J.transpose() * ((tips - xb0) * 2);
  };
  proj_z = [&](Eigen::VectorXd & A)
  {
//    assert(skeleton.size()*3 == A.size());
      for(int i = 0; i < skeleton.size(); i++){
          int idx = 3 * i;
          for (int k = 0; k < 3; k++){
              A[idx + k] = fmax(skeleton[i].xzx_min[k], fmin(skeleton[i].xzx_max[k], A[idx + k]));
          }
      }
  };
  /////////////////////////////////////////////////////////////////////////////
}
