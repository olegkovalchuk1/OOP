#pragma once
#include "Figure.h"

class Pyramid : public Figure {
private:
    double x, y, h;
public:
    Pyramid(double x, double y, double h);
    double volume() const override;
};