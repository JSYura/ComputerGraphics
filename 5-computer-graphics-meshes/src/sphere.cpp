#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  int num_f_count = num_faces_u * num_faces_v;  
  int num_v_count = (num_faces_u + 1) * (num_faces_v + 1);
  V.resize(num_v_count, 3);
  F.resize(num_f_count, 4); 
  UV.resize(num_v_count, 2);
  UF.resize(num_f_count, 4);
  NV.resize(num_v_count, 3);
  NF.resize(num_f_count, 4);
  double theta = 2.0*M_PI / num_faces_u;
  double p = M_PI / num_faces_v;
  int index = 0;
  for (int i = 0; i < num_faces_u + 1; i++) {
    for (int j = 0; j < num_faces_v + 1; j++) {
      // math stuff, convert to sphere
      double a = sin(j * p) * cos(i*theta);
      double b = sin(j * p) * sin(i*theta);
      double c = cos(j * p);

      V.row(index) = Eigen::Vector3d(a, b, c);
      UV.row(index) = Eigen::Vector2d((float) i / num_faces_u, (float) j / num_faces_v);
      NV.row(index) = Eigen::Vector3d(a, b, c);
      index++;
    }
  }
  for (int i=0; i < num_faces_u; i++) {
    for (int j=0; j < num_faces_v; j++) {
      // math stuff, convert to sphere
      int d = i*num_faces_v + (i + j);
      int e = d + 1;
      int f = (i+1)*(num_faces_v+1) +j;
      int g = f + 1;
      int row_i = i*num_faces_v + j;

      F.row(row_i) = Eigen::RowVector4i(d, f, g, e);
      UF.row(row_i) = Eigen::RowVector4i(d, f, g, e);
      NF.row(row_i) = Eigen::RowVector4i(d, f, g, e);
    }
  }
}
