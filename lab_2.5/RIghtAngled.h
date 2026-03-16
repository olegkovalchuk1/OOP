#pragma once
#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;
class RightAngled
{
private:
	Pair pair;
public:
	Pair getPair() const { return pair; }
	void setPair(const Pair& pair) { this->pair = pair; }
	RightAngled();
	RightAngled(const Pair& pair);
	RightAngled(double f, double s);
	RightAngled(const RightAngled& other);
	RightAngled& operator = (const RightAngled& other);
	friend ostream& operator << (ostream& out, const RightAngled& r);
	friend istream& operator >> (istream& in, RightAngled& r);
	operator string () const;
	RightAngled& operator ++ ();
	RightAngled& operator -- ();
	RightAngled operator ++ (int);
	RightAngled operator -- (int);
	double hypotenuse() const;
	double area() const;
};