#include "fast_mass_springs_step_sparse.h"
#include <igl/matlab_format.h>

void fast_mass_springs_step_sparse(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXi & b,
  const double delta_t,
  const Eigen::MatrixXd & fext,
  const Eigen::VectorXd & r,
  const Eigen::SparseMatrix<double>  & M,
  const Eigen::SparseMatrix<double>  & A,
  const Eigen::SparseMatrix<double>  & C,
  const Eigen::SimplicialLLT<Eigen::SparseMatrix<double> > & prefactorization,
  const Eigen::MatrixXd & Uprev,
  const Eigen::MatrixXd & Ucur,
  Eigen::MatrixXd & Unext)
{
  //////////////////////////////////////////////////////////////////////////////
  // Replace with your code
//  for(int iter = 0;iter < 50;iter++)
//  {
//    const Eigen::MatrixXd l = Ucur;
//    Unext = prefactorization.solve(l);
//  }

  Eigen::MatrixXd iter_matrix, y, l;
  Unext = Ucur;
  y = ((1.0 / pow(delta_t, 2.0)) * M * (2 * Ucur - Uprev) + fext) + ((1.0e10 * C.transpose() * C) * V);
  for(int iter = 0;iter < 50;iter++){
      iter_matrix = Eigen::MatrixXd::Zero(E.rows(), 3);
      for (int i = 0; i < E.rows(); i++){
          iter_matrix.row(i) = r(i) * (Unext.row(E(i, 0)) - Unext.row(E(i, 1))).normalized();
      }
      l = k * A.transpose() * iter_matrix + y;
      Unext = prefactorization.solve(l);
  }
  //////////////////////////////////////////////////////////////////////////////
}
