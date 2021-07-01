#include "signed_incidence_matrix_sparse.h"
#include <vector>

void signed_incidence_matrix_sparse(
  const int n,
  const Eigen::MatrixXi & E,
  Eigen::SparseMatrix<double>  & A)
{
  //////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  std::vector<Eigen::Triplet<double> > ijv;
//  ijv.emplace_back(0,0,1234.5678);
  int e_row_no;
  e_row_no = E.rows();
  for (int i = 0; i < e_row_no; i++) {
      ijv.emplace_back(i, E(i, 0), 1);
      ijv.emplace_back(i, E(i, 1), -1);
  }
  A.resize(e_row_no,n);
  A.setFromTriplets(ijv.begin(),ijv.end());
  //////////////////////////////////////////////////////////////////////////////
}
