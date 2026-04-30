// Pair.h
#pragma once
#include <iostream>

class Pair {
protected:
    // Спільні поля описані у абстрактному класі
    double a;
    double b;

public:
    Pair(double a = 0, double b = 0) : a(a), b(b) {}
    virtual ~Pair() = default;

    // Чисті віртуальні функції вводу/виводу
    virtual void print() const = 0;
    virtual void input() = 0;

    // Віртуальні арифметичні операції (повертають вказівник на новий об'єкт для підтримки поліморфізму)
    virtual Pair* add_ptr(const Pair* p) const = 0;
    virtual Pair* sub_ptr(const Pair* p) const = 0;
    virtual Pair* mul_ptr(const Pair* p) const = 0;
    virtual Pair* div_ptr(const Pair* p) const = 0;
    virtual bool equ_ptr(const Pair* p) const = 0;
};