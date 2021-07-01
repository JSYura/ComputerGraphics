#include "fast_mass_springs_precomputation_sparse.h"
#include "signed_incidence_matrix_sparse.h"
#include <vector>

bool fast_mass_springs_precomputation_sparse(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXd & m,
  const Eigen::VectorXi & b,
  const double delta_t,
  Eigen::VectorXd & r,
  Eigen::SparseMatrix<double>  & M,
  Eigen::SparseMatrix<double>  & A,
  Eigen::SparseMatrix<double>  & C,
  Eigen::SimplicialLLT<Eigen::SparseMatrix<double> > & prefactorization)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
//  std::vector<Eigen::Triplet<double> > ijv;
  const int n = V.rows();
  int e_row_no, b_row_no;
  e_row_no = E.rows();
  b_row_no = b.size();
//  for(int i = 0;i<n;i++) ijv.emplace_back(i,i,1);
  Eigen::SparseMatrix<double> Q(n,n);
//  Q.setFromTriplets(ijv.begin(),ijv.end());
  r.resize(e_row_no);
  Eigen::MatrixXd r_i;
  std::vector<Eigen::Triplet<double> > iter_vector1, iter_vector2;
  for (int i = 0; i < e_row_no; i++) {
      r_i = (V.row(E(i, 0)) - V.row(E(i, 1)));
      r(i) = r_i.norm();
  }

  for (int i = 0; i < n; i++) {
      iter_vector1.emplace_back(i, i, m(i));
  }
  M.resize(n,n);
  M.setFromTriplets(iter_vector1.begin(),iter_vector1.end());

  signed_incidence_matrix_sparse(n, E, A);

  for (int j = 0;j < b_row_no; j++) {
      iter_vector2.emplace_back(j,b[j],1);
  }
  C.resize(b_row_no, n);
  C.setFromTriplets(iter_vector2.begin(),iter_vector2.end());

  Q = k * A.transpose() * A + 1.0 / pow(delta_t,2) * M + 1e10 * C.transpose() * C;
  /////////////////////////////////////////////////////////////////////////////
  prefactorization.compute(Q);
  return prefactorization.info() != Eigen::NumericalIssue;
}
