#include "catmull_clark.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <vector>


void catmull_clark(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const int num_iters,
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF)
{
  if (num_iters <= 0){
      return;
  }
  // init 
  SV.resize(0, 3);
  SF.resize(0, 4);
  std::unordered_map<std::string, std::vector<int>> edge_face;
  std::unordered_map<int, std::vector<int>> p_face;
  std::unordered_map<int, std::vector<int>> near_p;
  int x,y,z;
  Eigen::MatrixXd n_face;
  Eigen::RowVector3d face_point, new_point, v;
  std::vector<Eigen::RowVector3d> vertexs;
  Eigen::RowVector4i new_e;
  //create a hash map
  n_face.resize(F.rows(), 3);
  for (int i=0; i < F.rows(); i++){
      Eigen::RowVector3d temp(0, 0, 0);
      for (int j=0; j<F.cols(); j++){
       x = F(i, j);
       y = F(i, (j+1)%F.cols());
       edge_face[std::to_string(x) + " " + std::to_string(y)].push_back(i);
       edge_face[std::to_string(y) + " " + std::to_string(x)].push_back(i);
       p_face[x].push_back(i); 
       z = F(i, ((j-1)+F.cols())%F.cols());
       if (std::find(near_p[x].begin(), near_p[x].end(), y) == near_p[x].end()){
         near_p[x].push_back(y);
       }
       if (std::find(near_p[x].begin(), near_p[x].end(), z) == near_p[x].end()){
         near_p[x].push_back(z);
       }
       temp += V.row(F(i, j));
      }
      n_face.row(i) = temp / (double) F.cols();
  }
  for (int i=0; i<F.rows(); i++){
      for (int j=0; j<F.cols(); j++){
       x = F(i, j);
       y = F(i, (j+1)%F.cols());
       z = F(i, ((j-1)+F.cols())%F.cols());

       Eigen::RowVector3d xy(0, 0, 0);
       Eigen::RowVector3d xz(0, 0, 0);
       for (int face: edge_face[std::to_string(x) + " " + std::to_string(y)]){
         xy += n_face.row(face);
       }
       for (int face: edge_face[std::to_string(x) + " " + std::to_string(z)]){
         xz += n_face.row(face);
       }
       xy = (xy + V.row(x) + V.row(y)) / 4.0;
       xz = (xz + V.row(x) + V.row(z)) / 4.0;
       face_point = n_face.row(i);
       Eigen::RowVector3d F(0, 0, 0);
       Eigen::RowVector3d R(0, 0, 0);
       Eigen::RowVector3d P = V.row(x);
       double n = 0;
       for (int face: p_face[x]){
          F += n_face.row(face);
          n += 1;
        }
       for (int n: near_p[x]){
          R += (V.row(x) + V.row(n)) / 2.0;
        }
       R /= n;
       F /= n;
       new_point = (F + 2 * R + (n - 3) * P) / n;
       new_e = {-100, -100, -100, -100};
       vertexs = {xy, face_point, xz, new_point};
      for (int k = 0; k < 4; k++){
        v = vertexs.at(k);
        for (int m = 0; m<SV.rows(); m++){
          if (v.isApprox(SV.row(m))){
            new_e(k) = m;
          }   
        }
        if (new_e(k) == -100){
          SV.conservativeResize(SV.rows() + 1, Eigen::NoChange);
          SV.row(SV.rows()-1) = v;
          new_e(k) = SV.rows()-1;        
        }     
      }
      SF.conservativeResize(SF.rows() + 1, Eigen::NoChange);
      SF.row(SF.rows() - 1) = new_e;       
      }
  }
  catmull_clark(Eigen::MatrixXd(SV), Eigen::MatrixXi(SF), num_iters - 1, SV, SF);
}