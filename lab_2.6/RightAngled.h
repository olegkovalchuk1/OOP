#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class RightAngled
{
private:
	static int counter;

public:
	class Pair
	{
	private:
		double first;
		double second;
		static int counter;

	public:
		double getFirst() const { return first; }
		double getSecond() const { return second; }
		void setFirst(double first) { if (first > 0) this->first = first; else this->first = 1.0; }
		void setSecond(double second) { if (second > 0) this->second = second; else this->second = 1.0; }

		void Init(double first, double second);
		void Display() const;
		void Read();

		Pair();
		Pair(const double first);
		Pair(const double first, const double second);
		Pair(const Pair& p);
		~Pair(void);

		Pair& operator = (const Pair& p);
		friend ostream& operator << (ostream& out, const Pair& p);
		friend istream& operator >> (istream& in, Pair& p);
		operator string () const;

		Pair& operator ++ ();
		Pair& operator -- ();
		Pair operator ++ (int);
		Pair operator -- (int);

		double product() const;

		static int getCounter();
	};

	Pair getPair() const { return pair; }
	void setPair(Pair pair) { this->pair = pair; }

	void Init(Pair pair);
	void Display() const;
	void Read();

	RightAngled(const double first = 1.0, const double second = 1.0);
	RightAngled(const RightAngled& r);
	~RightAngled(void);

	RightAngled& operator = (const RightAngled& r);
	friend ostream& operator << (ostream& out, const RightAngled& r);
	friend istream& operator >> (istream& in, RightAngled& r);
	operator string () const;

	RightAngled& operator ++ ();
	RightAngled& operator -- ();
	RightAngled operator ++ (int);
	RightAngled operator -- (int);

	double hypotenuse() const;
	double area() const;

	static int getCounter();

private:
	Pair pair;
};