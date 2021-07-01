#include "fast_mass_springs_precomputation_dense.h"
#include "signed_incidence_matrix_dense.h"
#include <Eigen/Dense>

bool fast_mass_springs_precomputation_dense(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXd & m,
  const Eigen::VectorXi & b,
  const double delta_t,
  Eigen::VectorXd & r,
  Eigen::MatrixXd & M,
  Eigen::MatrixXd & A,
  Eigen::MatrixXd & C,
  Eigen::LLT<Eigen::MatrixXd> & prefactorization)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  Eigen::MatrixXd Q = Eigen::MatrixXd::Identity(V.rows(),V.rows());
  int v_row_no, e_row_no, b_row_no;
  v_row_no = V.rows();
  e_row_no = E.rows();
  r.resize(e_row_no);
  b_row_no = b.size();
  Eigen::MatrixXd r_i;
  for (int i = 0; i < e_row_no; i++) {
      r_i = (V.row(E(i, 0)) - V.row(E(i, 1)));
      r(i) = r_i.norm();
  }
  M = Eigen::MatrixXd::Zero(v_row_no,v_row_no);
  M += m.asDiagonal();

  signed_incidence_matrix_dense(v_row_no, E, A);
  C = Eigen::MatrixXd::Zero(b_row_no,v_row_no);
  for (int i = 0; i < b_row_no; i++) {
      for (int j = 0; j < v_row_no; j++){
          if (b(i) != j){
              C(i, j) = 0;
          }else{
              C(i, b(i)) = 1;
          }
      }
  }
//  formula
  Q = k * A.transpose() * A + 1.0/pow(delta_t,2) * M + 1e10 * C.transpose() * C;
  /////////////////////////////////////////////////////////////////////////////
  prefactorization.compute(Q);
  return prefactorization.info() != Eigen::NumericalIssue;
}
