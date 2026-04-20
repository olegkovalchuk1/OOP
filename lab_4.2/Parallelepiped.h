#pragma once
#include "IFigure.h"

class Parallelepiped : public IFigure {
private:
    double x, y, z;
public:
    Parallelepiped(double x, double y, double z);

    double volume() const override;
    std::string getName() const override;
};