#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int tmp = i * width + j;
            for (int k = 0; k < 3; k++){
                rgb[3 * tmp + k] = rgba[4 * tmp + k];
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
