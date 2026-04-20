#pragma once
#include "Array.h"

class Money : public Array {
public:
    Money(int s = 0, unsigned char initVal = 0);

    void add(const Array& other) override;

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(const Money& other) const;
    Money operator/(const Money& other) const;

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;

    void print() const override;
};