#pragma once
#include "IFigure.h"

class Pyramid : public IFigure {
private:
    double x, y, h;
public:
    Pyramid(double x, double y, double h);

    double volume() const override;
    std::string getName() const override;
};