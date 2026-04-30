
#include "Complex.h"

Complex::Complex(double real, double imag) : Pair(real, imag) {}

void Complex::print() const {
    std::cout << "(" << a << " + " << b << "i)";
}

void Complex::input() {
    std::cout << "Enter real and imaginary parts: ";
    std::cin >> a >> b;
}

// === Реалізація поліморфних методів ===
Pair* Complex::add_ptr(const Pair* p) const {
    const Complex* c = dynamic_cast<const Complex*>(p);
    if (c) return new Complex(a + c->a, b + c->b);
    return nullptr;
}

Pair* Complex::sub_ptr(const Pair* p) const {
    const Complex* c = dynamic_cast<const Complex*>(p);
    if (c) return new Complex(a - c->a, b - c->b);
    return nullptr;
}

Pair* Complex::mul_ptr(const Pair* p) const {
    const Complex* c = dynamic_cast<const Complex*>(p);
    if (c) return new Complex(a * c->a - b * c->b, a * c->b + c->a * b);
    return nullptr;
}

Pair* Complex::div_ptr(const Pair* p) const {
    const Complex* c = dynamic_cast<const Complex*>(p);
    if (c) {
        double denominator = c->a * c->a + c->b * c->b;
        return new Complex((a * c->a + b * c->b) / denominator,
            (c->a * b - a * c->b) / denominator);
    }
    return nullptr;
}

bool Complex::equ_ptr(const Pair* p) const {
    const Complex* c = dynamic_cast<const Complex*>(p);
    if (c) return (a == c->a) && (b == c->b);
    return false;
}

// === Реалізація специфічних методів (за значенням) ===
Complex Complex::add(const Complex& v) const { return Complex(a + v.a, b + v.b); }
Complex Complex::sub(const Complex& v) const { return Complex(a - v.a, b - v.b); }
Complex Complex::mul(const Complex& v) const { return Complex(a * v.a - b * v.b, a * v.b + v.a * b); }
Complex Complex::div(const Complex& v) const {
    double denominator = v.a * v.a + v.b * v.b;
    return Complex((a * v.a + b * v.b) / denominator, (v.a * b - a * v.b) / denominator);
}
bool Complex::equ(const Complex& v) const { return (a == v.a) && (b == v.b); }
Complex Complex::conj() const { return Complex(a, -b); }