#include "Pair.h"
#include <sstream>

bool Pair::setFirst(double first)
{
	if (first > 0) { this->first = first; return true; }
	return false;
}

bool Pair::setSecond(double second)
{
	if (second > 0) { this->second = second; return true; }
	return false;
}

Pair::Pair()
	: first(1.0), second(1.0)
{
}

Pair::Pair(double first, double second)
{
	if (!setFirst(first)) this->first = 1.0;
	if (!setSecond(second)) this->second = 1.0;
}

Pair::Pair(const Pair& other)
	: first(other.first), second(other.second)
{
}

Pair& Pair::operator = (const Pair& other)
{
	this->first = other.first;
	this->second = other.second;
	return *this;
}

ostream& operator << (ostream& out, const Pair& p)
{
	out << string(p);
	return out;
}

istream& operator >> (istream& in, Pair& p)
{
	double f, s;
	cout << endl;
	cout << "first (leg > 0) = ? "; in >> f;
	cout << "second (leg > 0) = ? "; in >> s;
	if (f > 0 && s > 0) {
		p.first = f;
		p.second = s;
	}
	else {
		cout << "Invalid input. Setting to defaults (1.0)." << endl;
		p.first = 1.0;
		p.second = 1.0;
	}
	return in;
}

Pair::operator string () const
{
	stringstream ss;
	ss << "(" << first << ", " << second << ")";
	return ss.str();
}

Pair& Pair::operator ++ ()
{
	++first;
	++second;
	return *this;
}

Pair& Pair::operator -- ()
{
	if (first > 1) --first;
	if (second > 1) --second;
	return *this;
}

Pair Pair::operator ++ (int)
{
	Pair t(*this);
	first++;
	second++;
	return t;
}

Pair Pair::operator -- (int)
{
	Pair t(*this);
	if (first > 1) first--;
	if (second > 1) second--;
	return t;
}

double Pair::product() const
{
	return first * second;
}