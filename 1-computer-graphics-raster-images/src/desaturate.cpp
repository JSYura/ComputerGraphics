#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double r, g, b, h, s, v;
    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width; j ++){
            int tmp = i * width + j;
            r = rgb[3 * tmp] / 255.0;
            g = rgb[3 * tmp + 1] / 255.0;
            b = rgb[3 * tmp + 2] / 255.0;
            rgb_to_hsv(r, g, b, h, s, v);
            if (0 <= factor && factor <= 1) {
                s *= (1 - factor);
            }
            hsv_to_rgb(h, s, v, r, g, b);
            desaturated[3 * tmp] = r * 255.0;
            desaturated[3 * tmp + 1] = g * 255.0;
            desaturated[3 * tmp + 2] = b * 255.0;
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
