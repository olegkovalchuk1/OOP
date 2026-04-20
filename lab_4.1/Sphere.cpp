#include "Sphere.h"

Sphere::Sphere(double r) : Figure("Куля"), r(r) {}

double Sphere::volume() const {
    const double PI = 3.141592653589793;
    return (4.0 * PI * std::pow(r, 3)) / 3.0;
}