#include "kinematics_jacobian.h"
#include "transformed_tips.h"
#include <iostream>

void kinematics_jacobian(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  Eigen::MatrixXd & J)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  J = Eigen::MatrixXd::Zero(b.size()*3,skeleton.size()*3);
  Eigen::VectorXd tips, cp_tips;
  Skeleton cp_skeleton = skeleton;

  tips = transformed_tips(skeleton, b);
//  cp_skeleton = skeleton;

  for (int i = 0; i < skeleton.size(); i++){
      for (int k = 0; k < 3; k ++){
          int idx = 3 * i;
          cp_skeleton[i].xzx[k] += 1e-7;
          cp_tips = transformed_tips(cp_skeleton, b);
          J.col(idx + k) = (cp_tips - tips) / 1e-7;
          cp_skeleton[i].xzx[k] -= 1e-7;
      }
  }
  /////////////////////////////////////////////////////////////////////////////
}
