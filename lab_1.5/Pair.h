#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair
{
private:
    double first;
    double second;

public:
    double getFirst() const { return first; }
    double getSecond() const { return second; }

    bool setFirst(double first)
    {
        if (first > 0) { this->first = first; return true; }
        return false;
    }

    bool setSecond(double second)
    {
        if (second > 0) { this->second = second; return true; }
        return false;
    }

    bool Init(double first, double second);
    void Display() const;
    void Read();
    string toString() const;

    double product() const;
};