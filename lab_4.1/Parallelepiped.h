#pragma once
#include "Figure.h"

class Parallelepiped : public Figure {
private:
    double x, y, z;
public:
    Parallelepiped(double x, double y, double z);
    double volume() const override;
};