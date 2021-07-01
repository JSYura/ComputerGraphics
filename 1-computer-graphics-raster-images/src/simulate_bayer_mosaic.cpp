#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int tmp = i * width + j;

            if (i % 2 == 1 && j % 2 == 0) {
                bayer[tmp] = rgb[3 * tmp];
            }
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                bayer[tmp] = rgb[3 * tmp + 1];
            }
            if (i % 2 == 0 && j % 2 == 1) {
                bayer[tmp] = rgb[3 * tmp + 2];
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
