#pragma once
#include "IFigure.h"

class Tetrahedron : public IFigure {
private:
    double a;
public:
    Tetrahedron(double a);

    double volume() const override;
    std::string getName() const override;
};