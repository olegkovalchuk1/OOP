#include "Tetrahedron.h"
#include <cmath>

Tetrahedron::Tetrahedron(double a) : a(a) {}

double Tetrahedron::volume() const {
    return (std::pow(a, 3) * std::sqrt(2.0)) / 12.0;
}

std::string Tetrahedron::getName() const {
    return "Тетраедр";
}