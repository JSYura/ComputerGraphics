#include "ray_intersect_triangle.h"

bool ray_intersect_triangle(
        const Ray & ray,
        const Eigen::RowVector3d & A,
        const Eigen::RowVector3d & B,
        const Eigen::RowVector3d & C,
        const double min_t,
        const double max_t,
        double & t)
{
    ////////////////////////////////////////////////////////////////////////////
    double a = A[0] - B[0];
    double b = A[1] - B[1];
    double c = A[2] - B[2];
    double d = A[0] - C[0];
    double e = A[1] - C[1];
    double f = A[2] - C[2];

    double g = ray.direction[0];
    double h = ray.direction[1];
    double i = ray.direction[2];

    double j = A[0] - ray.origin[0];
    double k = A[1] - ray.origin[1];
    double l = A[2] - ray.origin[2];

    double AC_yz = e * i - h * f;
    double AC_xz = g * f - d * i;
    double AC_xy = d * h - e * g;
    double AB_xy = a * k - j * b;
    double AB_xz = j * c - a * l;
    double AB_yz = b * l - k * c;

    double M = a * (AC_yz) + b * (AC_xz) + c * (AC_xy);

    t = - (f * AB_xy + e * AB_xz + d * AB_yz) / M;
    if (t < min_t || t>max_t) {
        return false;
    }

    double gamma = (i * AB_xy + h * AB_xz + g * AB_yz) / M;
    if(gamma < 0 || gamma > 1){
        return false;
    }

    double beta = (j * AC_yz + k * AC_xz + l * AC_xy) / M;
    if(beta < 0 || beta > 1 - gamma){
        return false;
    }

    return true;
    ////////////////////////////////////////////////////////////////////////////
}
