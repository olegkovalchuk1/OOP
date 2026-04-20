#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(double x, double y, double z)
    : Figure("Паралелепіпед"), x(x), y(y), z(z) {
}

double Parallelepiped::volume() const {
    return x * y * z;
}