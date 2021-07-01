#include "copy_skeleton_at.h"
Skeleton copy_skeleton_at(
  const Skeleton & skeleton, 
  const Eigen::VectorXd & A)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  Skeleton copy = skeleton;
  for (int i = 0; i < skeleton.size(); i++) {
      int idx = i * 3;
      for (int k = 0; k < 3; k++){
          copy[i].xzx[k] = A(idx + k);
      }
    }
  return copy;
  /////////////////////////////////////////////////////////////////////////////
}
