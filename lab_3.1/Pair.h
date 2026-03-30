#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair {
    double first, second;
public:
    Pair();                               // Конструктор за замовчуванням
    Pair(double x, double y);             // Конструктор ініціалізації
    Pair(const Pair& r);                  // Конструктор копіювання
    ~Pair(void);

    double getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(double value) { first = value; }
    void setSecond(double value) { second = value; }

    operator string() const;
    friend ostream& operator << (ostream& out, const Pair& r);
    friend istream& operator >> (istream& in, Pair& r);

    double product() const;
};