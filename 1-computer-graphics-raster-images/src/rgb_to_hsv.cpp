#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    double cmax = std::max(std::max(r, g), b);
    double cmin = std::min(std::min(r, g), b);
    double diff = cmax - cmin;

    v = cmax;

    if (cmax == 0){
        s = 0;
    } else {
        s = diff / cmax;
    }

    if (diff == 0) {
        h = 0;
    } else if (cmax == r) {
        h = 60.0 * (g - b) / diff;
    } else if (cmax == g) {
        h = 60.0 * (2 + (b - r) / diff);
    } else if (cmax == b) {
        h = 60.0 * (4 + (r - g) / diff);
    }
    if (h < 0) {
        h += 360;
    }
  ////////////////////////////////////////////////////////////////////////////
}
