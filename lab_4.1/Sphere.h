#pragma once
#include "Figure.h"
#include <cmath>

class Sphere : public Figure {
private:
    double r;
public:
    Sphere(double r);
    double volume() const override;
};