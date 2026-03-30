#include "RightAngled.h"
#include <cmath>
#include <sstream>

// Виклик конструктора за замовчуванням базового класу
RightAngled::RightAngled() : Pair() {}

// Виклик конструктора ініціалізації базового класу
RightAngled::RightAngled(double x, double y) : Pair(x, y) {}

// Ініціалізація через об'єкт Pair
RightAngled::RightAngled(const Pair& p) : Pair(p) {}

// Конструктор копіювання
RightAngled::RightAngled(const RightAngled& r) : Pair(r) {}

RightAngled::~RightAngled(void) {}

double RightAngled::hypotenuse() const {
    // Звернення через гетери, оскільки поля private в Pair
    return sqrt(getFirst() * getFirst() + getSecond() * getSecond());
}

double RightAngled::area() const {
    return 0.5 * product();
}

RightAngled::operator string() const {
    stringstream ss;
    ss << "RightAngled " << Pair::operator string()
        << " | Hypotenuse: " << hypotenuse()
        << " | Area: " << area();
    return ss.str();
}

ostream& operator << (ostream& out, const RightAngled& r) {
    return out << (string)r;
}

istream& operator >> (istream& in, RightAngled& r) {
    double f, s;
    cout << "Leg A: "; in >> f;
    cout << "Leg B: "; in >> s;
    r.setFirst(f);
    r.setSecond(s);
    return in;
}