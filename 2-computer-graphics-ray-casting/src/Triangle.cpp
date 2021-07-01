#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>
bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
//  return false;
    // 3 corners
    Eigen::Vector3d corner_a = std::get<0>(corners);
    Eigen::Vector3d corner_b = std::get<1>(corners);
    Eigen::Vector3d corner_c = std::get<2>(corners);
    // 2 edge ba,ca in formula
    Eigen::Vector3d vector_ba = corner_a - corner_b;
    Eigen::Vector3d vector_ca = corner_a - corner_c;

    //calculate normal vector
    Eigen::Vector3d vector_ac = corner_c - corner_a;
    Eigen::Vector3d vector_ab = corner_b - corner_a;
    // normal vector of triangle plane
    n = vector_ca.cross(vector_ab).normalized();

    // origin and direction
    Eigen::Vector3d eye = ray.origin;
    Eigen::Vector3d dir = ray.direction;
    // vector ea
    Eigen::Vector3d vector_ea = corner_a - ray.origin;

    // check
    if (n.dot(dir) == 0) {
        return false;
    }
    // use formula in slides
    t = (-1)*(n.dot(eye-corner_a))/(n.dot(dir));
    if (t < min_t) {
        return false;
    }

    // formula in textbook
    double a = vector_ba[0];
    double b = vector_ba[1];
    double c = vector_ba[2];
    double d = vector_ca[0];
    double e = vector_ca[1];
    double f = vector_ca[2];
    double g = dir[0];
    double h = dir[1];
    double i = dir[2];
    double j = vector_ea[0];
    double k = vector_ea[1];
    double l = vector_ea[2];
    //We can reduce the number of operations by reusing numbers such as
    //“ei_hf.”
    double ei_hf = e * i - h * f;
    double gf_di = g * f - d * i;
    double dh_eg = d * h - e * g;
    double ak_jb = a * k - j * b;
    double jc_al = j * c - a * l;
    double bl_kc = b * l - k * c;
    // design algorithm according textbook step by step
    double M = a * ei_hf + b * gf_di + c * dh_eg;
    // compute gamma
    double gamma = (i*ak_jb + h*jc_al + g*bl_kc)/M;
    if (gamma<0 || gamma>1) {
        return false;
    }
    // compute beta
    double beta = (j*ei_hf + k*gf_di + l*dh_eg)/M;
    if (beta < 0 || (beta > (1-gamma))) {
        return false;
    }
    return true;
  ////////////////////////////////////////////////////////////////////////////
}


