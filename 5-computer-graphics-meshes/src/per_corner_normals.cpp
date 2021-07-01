#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  std::vector<std::vector<int>> VF;
  vertex_triangle_adjacency(F, V.rows(), VF);
  for (int i = 0; i < F.rows(); i++){
  	Eigen::RowVector3d a = V.row(F(i, 0));
  	Eigen::RowVector3d b = V.row(F(i, 1));	
  	Eigen::RowVector3d c = V.row(F(i, 2));
    Eigen::RowVector3d n_curr = triangle_area_normal(a,b,c);
    for (int j = 0; j < 3; j++){
      Eigen::RowVector3d n(0, 0, 0);
      for(int k : VF[F(i, j)]){
        Eigen::RowVector3d n_temp = triangle_area_normal(
            V.row(F(k, 0)),
            V.row(F(k, 1)),
            V.row(F(k, 2)));
        if(n_temp.normalized().dot(n_curr.normalized()) > cos(corner_threshold * M_PI / 180)){
          n += n_temp;
        }
      }
      N.row(i * 3 + j) = n.normalized();
    }
  }
}
