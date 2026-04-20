#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(double x, double y, double z)
    : x(x), y(y), z(z) {
}

double Parallelepiped::volume() const {
    return x * y * z;
}

std::string Parallelepiped::getName() const {
    return "Паралелепіпед";
}