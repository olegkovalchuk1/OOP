#pragma once
#include <iostream>
#include <string>

using namespace std;

class RightAngled
{
public:
    // Вкладений клас Pair
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

private:
    Pair pair; // Використання вкладеного класу як поля

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