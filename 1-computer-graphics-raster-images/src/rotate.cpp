#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < num_channels; k++){
                rotated[num_channels * ((width - j - 1) * height + i) + k] = input[num_channels * (i * width + j) + k];
            };
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
