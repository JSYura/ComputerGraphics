#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double a, b, new_a;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int tmp = 4 * (i * width + j);
            a = A[tmp + 3] / 255.0;
            b = B[tmp + 3] / 255.0;
            new_a = a + (1 - a) * b;
            for (int k = 0; k < 3; k++){
                C[tmp + k] = (a * A[tmp + k] + b * (1 - a) * B[tmp + k]) / new_a;
            }
            C[tmp + 3] = new_a * 255;
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
