#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <cmath>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double r, g, b, h, s, v;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int tmp = i * width + j;
            r = rgb[3 * tmp] / 255.0;
            g = rgb[3 * tmp + 1] / 255.0;
            b = rgb[3 * tmp + 2] / 255.0;
            rgb_to_hsv(r, g, b, h, s, v);
            h += shift;

            if (h < 0){
                h += 360;
            }

            h = fmod(h, 360.0);

            hsv_to_rgb(h, s, v, r, g, b);

            shifted[3 * tmp] = r * 255;
            shifted[3 * tmp + 1] = g * 255;
            shifted[3 * tmp + 2] = b * 255;
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
