#include "RightAngled.h"
#include <cmath>


int RightAngled::counter = 0;

void RightAngled::Init(Pair pair)
{
	setPair(pair);
}

void RightAngled::Display() const
{
	cout << endl;
	cout << "pair = " << endl;
	pair.Display();
	cout << "Hypotenuse = " << hypotenuse() << endl;
	cout << "Area = " << area() << endl;
}

void RightAngled::Read()
{
	Pair p;
	cout << endl;
	cout << "Pair = ? " << endl;
	p.Read();
	Init(p);
}

RightAngled::RightAngled(const double first, const double second)
	: pair(first, second)
{
	RightAngled::counter++;
}

RightAngled::RightAngled(const RightAngled& r)
{
	pair = r.pair;
	RightAngled::counter++;
}

RightAngled::~RightAngled(void)
{
	RightAngled::counter--;
}

RightAngled& RightAngled::operator = (const RightAngled& r)
{
	pair = r.pair;
	return *this;
}

RightAngled::operator string () const
{
	stringstream ss;
	ss << "pair = " << pair << endl;
	ss << "Hypotenuse = " << hypotenuse() << endl;
	ss << "Area = " << area() << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const RightAngled& r)
{
	out << string(r);
	return out;
}

istream& operator >> (istream& in, RightAngled& r)
{
	cout << endl;
	cout << "pair = ? "; in >> r.pair;
	return in;
}

RightAngled RightAngled::operator ++ (int)
{
	RightAngled r(*this);
	pair++;
	return r;
}

RightAngled RightAngled::operator -- (int)
{
	RightAngled r(*this);
	pair--;
	return r;
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

double RightAngled::hypotenuse() const
{
	return sqrt(pair.getFirst() * pair.getFirst() + pair.getSecond() * pair.getSecond());
}

double RightAngled::area() const
{
	return 0.5 * pair.product();
}

int RightAngled::getCounter()
{
	return RightAngled::counter;
}


int RightAngled::Pair::counter = 0;

void RightAngled::Pair::Init(double first, double second)
{
	setFirst(first);
	setSecond(second);
}

void RightAngled::Pair::Display() const
{
	cout << "first = " << first << endl;
	cout << "second = " << second << endl;
}

void RightAngled::Pair::Read()
{
	double f;
	double s;
	cout << endl;
	cout << "first = ? "; cin >> f;
	cout << "second = ? "; cin >> s;
	Init(f, s);
}

RightAngled::Pair::Pair()
	: first(1.0)
{
	setSecond(1.0);
	RightAngled::Pair::counter++;
}

RightAngled::Pair::Pair(const double first)
	: first(first)
{
	setSecond(1.0);
	RightAngled::Pair::counter++;
}

RightAngled::Pair::Pair(const double first, const double second)
	: first(first)
{
	setSecond(second);
	RightAngled::Pair::counter++;
}

RightAngled::Pair::Pair(const RightAngled::Pair& p)
	: first(p.first), second(p.second)
{
	RightAngled::Pair::counter++;
}

RightAngled::Pair::~Pair(void)
{
	RightAngled::Pair::counter--;
}

RightAngled::Pair& RightAngled::Pair::operator = (const RightAngled::Pair& p)
{
	this->first = p.first;
	this->second = p.second;
	return *this;
}

RightAngled::Pair::operator string () const
{
	stringstream ss;
	ss << "first = " << first << endl;
	ss << "second = " << second << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const RightAngled::Pair& p)
{
	out << string(p);
	return out;
}

istream& operator >> (istream& in, RightAngled::Pair& p)
{
	double f;
	double s;
	cout << endl;
	cout << "first = ? "; in >> f;
	cout << "second = ? "; in >> s;
	p.setFirst(f);
	p.setSecond(s);
	return in;
}

RightAngled::Pair& RightAngled::Pair::operator ++ ()
{
	++first;
	++second;
	return *this;
}

RightAngled::Pair& RightAngled::Pair::operator -- ()
{
	if (first > 1) --first;
	if (second > 1) --second;
	return *this;
}

RightAngled::Pair RightAngled::Pair::operator ++ (int)
{
	RightAngled::Pair t(*this);
	first++;
	second++;
	return t;
}

RightAngled::Pair RightAngled::Pair::operator -- (int)
{
	RightAngled::Pair t(*this);
	if (first > 1) first--;
	if (second > 1) second--;
	return t;
}

double RightAngled::Pair::product() const
{
	return first * second;
}

int RightAngled::Pair::getCounter()
{
	return RightAngled::Pair::counter;
}