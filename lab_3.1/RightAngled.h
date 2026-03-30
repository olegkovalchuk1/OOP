#pragma once
#include "Pair.h"

class RightAngled : public Pair {
public:
    RightAngled();                        // Конструктор за замовчуванням
    RightAngled(double x, double y);      // Конструктор ініціалізації
    RightAngled(const Pair& p);           // Конструктор ініціалізації через Pair
    RightAngled(const RightAngled& r);    // Конструктор копіювання
    ~RightAngled(void);

    double hypotenuse() const;
    double area() const;

    operator string() const;
    friend ostream& operator << (ostream& out, const RightAngled& r);
    friend istream& operator >> (istream& in, RightAngled& r);
};