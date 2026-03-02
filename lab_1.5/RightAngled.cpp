#include "RightAngled.h"
#include <cmath>
#include <sstream>

using namespace std;

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