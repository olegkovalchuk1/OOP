#pragma once
#include "Array.h"

class Hex : public Array {
public:
    Hex(int s = 0, unsigned char initVal = 0);

    void add(const Array& other) override;

    Hex operator+(const Hex& other) const;
    Hex operator-(const Hex& other) const;
    Hex operator*(const Hex& other) const;
    Hex operator/(const Hex& other) const;

    bool operator==(const Hex& other) const;
    bool operator!=(const Hex& other) const;
    bool operator>(const Hex& other) const;
    bool operator<(const Hex& other) const;

    void print() const override;
};