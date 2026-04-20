#include "Sphere.h"
#include <cmath>

Sphere::Sphere(double r) : r(r) {}

double Sphere::volume() const {
    const double PI = 3.141592653589793;
    return (4.0 * PI * std::pow(r, 3)) / 3.0;
}

std::string Sphere::getName() const {
    return "Куля";
}