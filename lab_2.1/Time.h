#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
	int first, second;
public:
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();

	bool SetFirst(int);
	bool SetSecond(int);
	int GetFirst() const;
	int GetSecond() const;

	Time& operator = (const Time&);
	operator string() const;

	friend ostream& operator << (ostream&, const Time&);
	friend istream& operator >> (istream&, Time&);

	Time& operator ++();
	Time& operator --();
	Time operator ++(int);
	Time operator --(int);

	int minutes() const;
};