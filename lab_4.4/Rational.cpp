
#include "Rational.h"
#include <cmath>

void Rational::Reduce() {
    int num = static_cast<int>(a);
    int den = static_cast<int>(b);
    if (den == 0) den = 1; // Захист від ділення на нуль

    int u = std::abs(num);
    int v = std::abs(den);
    while (v != 0) {
        int temp = u % v;
        u = v;
        v = temp;
    }
    int gcd = u;

    num /= gcd;
    den /= gcd;

    if (den < 0) { // Знаменник завжди має бути додатнім
        num = -num;
        den = -den;
    }

    a = num;
    b = den;
}

Rational::Rational(int numerator, int denominator) : Pair(numerator, denominator) {
    Reduce();
}

void Rational::print() const {
    std::cout << a << "/" << b;
}

void Rational::input() {
    std::cout << "Enter numerator and denominator: ";
    std::cin >> a >> b;
    Reduce();
}

double Rational::value() const {
    return (double)a / b;
}

// === Реалізація поліморфних методів ===
Pair* Rational::add_ptr(const Pair* p) const {
    const Rational* r = dynamic_cast<const Rational*>(p);
    if (r) return new Rational(a * r->b + b * r->a, b * r->b);
    return nullptr;
}

Pair* Rational::sub_ptr(const Pair* p) const {
    const Rational* r = dynamic_cast<const Rational*>(p);
    if (r) return new Rational(a * r->b - b * r->a, b * r->b);
    return nullptr;
}

Pair* Rational::mul_ptr(const Pair* p) const {
    const Rational* r = dynamic_cast<const Rational*>(p);
    if (r) return new Rational(a * r->a, b * r->b);
    return nullptr;
}

Pair* Rational::div_ptr(const Pair* p) const {
    const Rational* r = dynamic_cast<const Rational*>(p);
    if (r) return new Rational(a * r->b, b * r->a);
    return nullptr;
}

bool Rational::equ_ptr(const Pair* p) const {
    const Rational* r = dynamic_cast<const Rational*>(p);
    if (r) return (a == r->a) && (b == r->b);
    return false;
}

// === Реалізація специфічних методів (за значенням) ===
Rational Rational::add(const Rational& v) const {
    return Rational(a * v.b + b * v.a, b * v.b);
}

Rational Rational::sub(const Rational& v) const {
    return Rational(a * v.b - b * v.a, b * v.b);
}

Rational Rational::mul(const Rational& v) const {
    return Rational(a * v.a, b * v.b);
}

Rational Rational::div(const Rational& v) const {
    return Rational(a * v.b, b * v.a);
}

bool Rational::equal(const Rational& v) const { return (a == v.a) && (b == v.b); }
bool Rational::great(const Rational& v) const { return this->value() > v.value(); }
bool Rational::less(const Rational& v) const { return this->value() < v.value(); }