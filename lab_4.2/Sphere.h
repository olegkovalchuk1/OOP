#pragma once
#include "IFigure.h"

class Sphere : public IFigure {
private:
    double r;
public:
    Sphere(double r);

    double volume() const override;
    std::string getName() const override;
};