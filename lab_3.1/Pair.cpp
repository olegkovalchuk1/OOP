#include "Pair.h"
#include <sstream>

Pair::Pair() {
    setFirst(0);
    setSecond(0);
}

Pair::Pair(double x, double y) {
    setFirst(x);
    setSecond(y);
}

Pair::Pair(const Pair& r) {
    setFirst(r.getFirst());
    setSecond(r.getSecond());
}

Pair::~Pair(void) {}

Pair::operator string() const {
    stringstream ss;
    ss << "(" << getFirst() << ", " << getSecond() << ")";
    return ss.str();
}

ostream& operator << (ostream& out, const Pair& r) {
    return out << (string)r;
}

istream& operator >> (istream& in, Pair& r) {
    double f, s;
    cout << "first = "; in >> f;
    cout << "second = "; in >> s;
    r.setFirst(f);
    r.setSecond(s);
    return in;
}

double Pair::product() const {
    return first * second;
}