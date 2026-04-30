
#pragma once
#include "Pair.h"

class Complex : public Pair {
public:
    Complex(double real = 0, double imag = 0);

    void print() const override;
    void input() override;

    // Поліморфні методи
    Pair* add_ptr(const Pair* p) const override;
    Pair* sub_ptr(const Pair* p) const override;
    Pair* mul_ptr(const Pair* p) const override;
    Pair* div_ptr(const Pair* p) const override;
    bool equ_ptr(const Pair* p) const override;

    // Специфічні методи та перевантаження (повернення за значенням)
    Complex add(const Complex& v) const;
    Complex sub(const Complex& v) const;
    Complex mul(const Complex& v) const;
    Complex div(const Complex& v) const;
    bool equ(const Complex& v) const;
    Complex conj() const;
};