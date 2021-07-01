#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width; j ++){
            int tmp = i * width + j;
            gray[tmp] = 0.2126 * rgb[3 * tmp] + 0.7152 * rgb[3 * tmp + 1] + 0.0722 * rgb[3 * tmp + 2];
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}


