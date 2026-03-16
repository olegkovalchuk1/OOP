#include "RightAngled.h"
#include <cmath>
#include <sstream>

RightAngled::RightAngled()
    : pair()
{
}

RightAngled::RightAngled(const Pair& pair)
    : pair(pair)
{
}

RightAngled::RightAngled(double f, double s)
    : pair(f, s)
{
}

RightAngled::RightAngled(const RightAngled& other)
    : pair(other.pair)
{
}

RightAngled& RightAngled::operator = (const RightAngled& other)
{
    this->pair = other.pair;
    return *this;
}

ostream& operator << (ostream& out, const RightAngled& r)
{
    out << string(r);
    return out;
}

istream& operator >> (istream& in, RightAngled& r)
{
    cout << "Enter legs (Pair): " << endl;
    in >> r.pair;
    return in;
}

RightAngled::operator string () const
{
    stringstream ss;
    ss << "Triangle with legs " << string(pair)
        << "; Hypotenuse: " << hypotenuse()
        << "; Area: " << area();
    return ss.str();
}

RightAngled& RightAngled::operator ++ ()
{
    ++pair;
    return *this;
}

RightAngled& RightAngled::operator -- ()
{
    --pair;
    return *this;
}

RightAngled RightAngled::operator ++ (int)
{
    RightAngled t(*this);
    pair++;
    return t;
}

RightAngled RightAngled::operator -- (int)
{
    RightAngled t(*this);
    pair--;
    return t;
}

double RightAngled::hypotenuse() const
{
    return sqrt(pair.getFirst() * pair.getFirst() + pair.getSecond() * pair.getSecond());
}

double RightAngled::area() const
{
    return 0.5 * pair.product();
}