#pragma once
#include "Figure.h"
#include <cmath>

class Tetrahedron : public Figure {
private:
    double a;
public:
    Tetrahedron(double a);
    double volume() const override;
};