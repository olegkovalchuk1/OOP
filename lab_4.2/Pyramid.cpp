#include "Pyramid.h"

Pyramid::Pyramid(double x, double y, double h)
    : x(x), y(y), h(h) {
}

double Pyramid::volume() const {
    return (x * y * h) / 3.0;
}

std::string Pyramid::getName() const {
    return "Піраміда";
}