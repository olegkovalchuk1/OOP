#include "Figure.h"

Figure::Figure(std::string n) : name(n) {}
Figure::~Figure() {}

std::string Figure::getName() const {
    return name;
}