#include "Pyramid.h"

Pyramid::Pyramid(double x, double y, double h)
    : Figure("Піраміда"), x(x), y(y), h(h) {
}

double Pyramid::volume() const {
    return (x * y * h) / 3.0;
}