#include "RightAngled.h"
#include <cmath>
#include <sstream>

using namespace std;

// --- Реалізація методів вкладеного класу RightAngled::Pair ---

bool RightAngled::Pair::Init(double first, double second)
{
    if (setFirst(first) && setSecond(second)) {
        return true;
    }
    return false;
}

void RightAngled::Pair::Display() const
{
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
}

void RightAngled::Pair::Read()
{
    double f, s;
    cout << endl;
    do {
        cout << "first (leg > 0) = ? "; cin >> f;
        cout << "second (leg > 0) = ? "; cin >> s;
    } while (!Init(f, s));
}

string RightAngled::Pair::toString() const
{
    stringstream sout;
    sout << "(" << first << ", " << second << ")";
    return sout.str();
}

double RightAngled::Pair::product() const
{
    return first * second;
}

// --- Реалізація методів класу RightAngled ---

bool RightAngled::Init(Pair pair)
{
    return setPair(pair);
}

void RightAngled::Display() const
{
    cout << endl;
    cout << "Legs (Pair) = " << endl;
    pair.Display();
    cout << "Hypotenuse = " << hypotenuse() << endl;
    cout << "Area = " << area() << endl;
}

void RightAngled::Read()
{
    Pair p;
    cout << endl;
    cout << "Enter legs (Pair) = ? " << endl;
    p.Read();
    Init(p);
}

string RightAngled::toString() const
{
    stringstream sout;
    sout << "Triangle with legs " << pair.toString()
        << "; Hypotenuse: " << hypotenuse()
        << "; Area: " << area();
    return sout.str();
}

double RightAngled::hypotenuse() const
{
    return sqrt(pair.getFirst() * pair.getFirst() + pair.getSecond() * pair.getSecond());
}

double RightAngled::area() const
{
    return 0.5 * pair.product();
}