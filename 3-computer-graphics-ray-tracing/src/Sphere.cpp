#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
//  return false;
    Eigen::Vector3d c = center;
    Eigen::Vector3d e = ray.origin;
    Eigen::Vector3d d = ray.direction;
    // formula
    double A = d.dot(d);
    double B = 2 * d.dot(e-c);
    double C = (e-c).dot(e-c) - pow(radius, 2);
    // calculate delta
    double discriminant = B*B-4*A*C;
    // no root or both less than min_t
    if (discriminant < 0){
        return false;
    }
    //larger root
    double root_1 = (-B + sqrt(discriminant))/(2*A);
    // smaller root
    double root_2 = (-B - sqrt(discriminant))/(2*A);
    // both less than min_t
    if (root_1 < min_t){
        return false;
    }
    if (discriminant == 0){
        t = root_1;
        n = (e + t * d - c)/radius;
        return true;
    }
    if (discriminant > 0){
        if (root_2 >= min_t){
            t = root_2;
        }else{
            t = root_1;
        }
        n = (e + t * d - c)/radius;
        return true;
    }
    return false;
  ////////////////////////////////////////////////////////////////////////////
}

