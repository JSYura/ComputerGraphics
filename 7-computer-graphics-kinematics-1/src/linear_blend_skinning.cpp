#include "linear_blend_skinning.h"

void linear_blend_skinning(
  const Eigen::MatrixXd & V,
  const Skeleton & skeleton,
  const std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T,
  const Eigen::MatrixXd & W,
  Eigen::MatrixXd & U)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
//  U = V;
  U = Eigen::MatrixXd::Zero(V.rows(), 3);
  for(int i = 0; i < V.rows(); i++){
    for(int k = 0; k < skeleton.size(); k++){
        if (skeleton[k].weight_index != -1){
            Eigen::Vector3d v_row_i_trans = V.row(i).transpose();
            int w_idx = W(i,skeleton[k].weight_index);
            U.row(i) = U.row(i) +
                    (w_idx * (T[k] * v_row_i_trans).transpose());
        }
    }
  }
  /////////////////////////////////////////////////////////////////////////////
}
