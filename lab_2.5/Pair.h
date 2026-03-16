#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pair
{
private:
	double first;
	double second;
public:
	double getFirst() const { return first; }
	double getSecond() const { return second; }
	bool setFirst(double first);
	bool setSecond(double second);
	Pair();
	Pair(double first, double second);
	Pair(const Pair& other);
	Pair& operator = (const Pair& other);
	friend ostream& operator << (ostream& out, const Pair& p);
	friend istream& operator >> (istream& in, Pair& p);
	operator string () const;
	Pair& operator ++ ();
	Pair& operator -- ();
	Pair operator ++ (int);
	Pair operator -- (int);
	double product() const;
};