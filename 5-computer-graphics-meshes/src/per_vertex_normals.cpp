#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  for (int i = 0; i < F.rows(); i++) {
  	Eigen::RowVector3d a = V.row(F(i, 0));
  	Eigen::RowVector3d b = V.row(F(i, 1));
  	Eigen::RowVector3d c = V.row(F(i, 2));
  	Eigen::RowVector3d n = triangle_area_normal(a, b, c);
  	N.row(F(i, 0)) += n;
  	N.row(F(i, 1)) += n;
  	N.row(F(i, 2)) += n;
  }

  for (int j = 0; j < N.rows(); j++){
    N.row(j) = N.row(j).normalized();
  }
}
