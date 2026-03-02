#pragma once
#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

class RightAngled
{
private:
    Pair pair;

public:
    Pair getPair() const { return pair; }

    bool setPair(Pair pair) {
        return this->pair.Init(pair.getFirst(), pair.getSecond());
    }

    bool Init(Pair pair);
    void Display() const;
    void Read();
    string toString() const;

    double hypotenuse() const;
    double area() const;
};