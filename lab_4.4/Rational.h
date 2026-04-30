
#pragma once
#include "Pair.h"

class Rational : public Pair {
private:
    void Reduce(); // Приватна функція скорочення дробу

public:
    Rational(int numerator = 0, int denominator = 1);

    void print() const override;
    void input() override;

    // Поліморфні методи
    Pair* add_ptr(const Pair* p) const override;
    Pair* sub_ptr(const Pair* p) const override;
    Pair* mul_ptr(const Pair* p) const override;
    Pair* div_ptr(const Pair* p) const override;
    bool equ_ptr(const Pair* p) const override;

    // Специфічні методи
    double value() const;
    Rational add(const Rational& v) const;
    Rational sub(const Rational& v) const;
    Rational mul(const Rational& v) const;
    Rational div(const Rational& v) const;

    bool equal(const Rational& v) const;
    bool great(const Rational& v) const;
    bool less(const Rational& v) const;
};