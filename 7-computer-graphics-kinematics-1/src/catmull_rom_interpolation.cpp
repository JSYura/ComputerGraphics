#include "catmull_rom_interpolation.h"
#include <Eigen/Dense>

Eigen::Vector3d catmull_rom_interpolation(
  const std::vector<std::pair<double, Eigen::Vector3d> > & keyframes,
  double t)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
//  return Eigen::Vector3d(0,0,0);
    Eigen::Vector3d output(0,0,0);
    int size, s, e;
    size = keyframes.size();
    if (keyframes.empty()){
        return output;
    }
    t = fmod(t, keyframes[size-1].first);
    // start, end index
    s = -1;
    e = -1;
    for (int i = 0; i < size; i++){
        if (keyframes[i].first != t){
            if (keyframes[i].first < t && t < keyframes[i+1].first){
                s = i;
                if (i != size - 1){
                    e = s + 1;
                }else{
                    e = 0;
                }
            }
        }else{
            return keyframes[i].second;
        }
    }

    // first 0,1,2,3
    double f0, f1, f2, f3;
    // second 0,1,2,3
    // third 0,1
    Eigen::Vector3d s0, s1, s2, s3, t0, t1;
    if (!keyframes.empty()){
        f1 = keyframes[s].first;
        f2 = keyframes[e].first;

        s1 = keyframes[s].second;
        s2 = keyframes[e].second;

        int idx0;
        int idx3;
        if (s == 0){
            idx0 = size-1;
            idx3 = e+1;
        }else if (e == size-1){
            idx0 = s-1;
            idx3 = 0;
        }else{
            idx0 = s-1;
            idx3 = e+1;
        }
        f0 = keyframes[idx0].first;
        s0 = keyframes[idx0].second;

        f3 = keyframes[idx3].first;
        s3 = keyframes[idx3].second;
    }else{
        return output;
    }

    double diff12;
    diff12 = f2-f1;

    f0 = (f0-f1) / diff12;
    f3 = (f3-f1) / diff12;

    t = (t-f1) / diff12;
    f1 = 0;
    f2 = 1;

    t0 = (s2 - s0) / (f2 - f0);
    t1 = (s3 - s1) / (f3 - f1);

    // formula
    output = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * s1 +
            (pow(t, 3) - 2 * pow(t, 2) + t) * t0 +
            (-2 * pow(t, 3) + 3 * pow(t, 2)) * s2 +
            (pow(t, 3) - pow(t, 2))  * t1;
    return output;

  /////////////////////////////////////////////////////////////////////////////
}
