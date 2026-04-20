#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(double a) : Figure("Тетраедр"), a(a) {}

double Tetrahedron::volume() const {
    return (std::pow(a, 3) * std::sqrt(2.0)) / 12.0;
}