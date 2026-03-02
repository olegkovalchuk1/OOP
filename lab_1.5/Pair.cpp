#include "Pair.h"
#include <sstream>

using namespace std;

bool Pair::Init(double first, double second)
{
    if (setFirst(first) && setSecond(second)) {
        return true;
    }
    return false;
}

void Pair::Display() const
{
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
}

void Pair::Read()
{
    double f, s;
    cout << endl;
    do {
        cout << "first (leg > 0) = ? "; cin >> f;
        cout << "second (leg > 0) = ? "; cin >> s;
    } while (!Init(f, s));
}

string Pair::toString() const
{
    stringstream sout;
    sout << "(" << first << ", " << second << ")";
    return sout.str();
}

double Pair::product() const
{
    return first * second;
}