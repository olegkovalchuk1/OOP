#pragma once
#include <iostream>
#include <string>

using namespace std;

class BitStringBase {
    long high;
    long low;
public:
    BitStringBase();
    BitStringBase(long h, long l);
    BitStringBase(const BitStringBase& other);
    ~BitStringBase();

    long getHigh() const { return high; }
    long getLow() const { return low; }
    void setHigh(long h) { high = h; }
    void setLow(long l) { low = l; }

    operator string() const;
    friend ostream& operator<<(ostream& out, const BitStringBase& obj);
    friend istream& operator>>(istream& in, BitStringBase& obj);
};