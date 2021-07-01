#include "transformed_tips.h"
#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(
  const Skeleton & skeleton, 
  const Eigen::VectorXi & b)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
//  return Eigen::VectorXd::Zero(3*b.size());
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > T;
  Eigen::VectorXd output;
  Eigen::VectorXd loop_v;
  int idx;
  forward_kinematics(skeleton, T);
  output = Eigen::VectorXd::Zero(3*b.size());
  for(int i = 0; i < b.size(); i++){
      loop_v = T[b[i]] * skeleton[b[i]].rest_T * Eigen::Vector4d(skeleton[b[i]].length, 0, 0, 1);
      idx = 3 * i;
      for (int k=0; k < 3; k++){
          output[idx+k] = loop_v[k];
      }
  }
  return output;
  /////////////////////////////////////////////////////////////////////////////
}
