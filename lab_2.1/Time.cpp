#include "Time.h"
#include <sstream>

Time::Time() // конструктор за умовчанням
{
	SetFirst(0);
	SetSecond(0);
}

// конструктор ініціалізації та за умовчанням
Time::Time(int f , int s )
{
	if (!SetFirst(f)) first = 0;
	if (!SetSecond(s)) second = 0;
}

Time::Time(const Time& t) // конструктор копіювання
{
	first = t.first;
	second = t.second;
}

Time::~Time()
{
}

bool Time::SetFirst(int f)
{
	if (f >= 0)
	{
		first = f;
		return true;
	}
	first = 0;
	return false;
}

bool Time::SetSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		second = s;
		return true;
	}
	second = 0;
	return false;
}

int Time::GetFirst() const
{
	return first;
}

int Time::GetSecond() const
{
	return second;
}

Time& Time::operator = (const Time& t)
{
	first = t.first;
	second = t.second;
	return *this;
}

Time::operator string () const
{
	stringstream ss;
	ss << " Hours = " << first << endl;
	ss << " Minutes = " << second << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Time& t)
{
	out << string(t); // повторне використання коду
	return out;
}

istream& operator >> (istream& in, Time& t)
{
	int f, s;
	cout << " Hours = "; in >> f;
	cout << " Minutes = "; in >> s;
	cout << endl;
	t.SetFirst(f);
	t.SetSecond(s);
	return in;
}

Time& Time::operator ++() // префіксна - модифікує first
{
	first++;
	return *this;
}

Time& Time::operator --() // префіксна - модифікує first
{
	first--;
	return *this;
}

Time Time::operator ++(int) // постфіксна - модифікує second
{
	Time t(*this);
	second++;
	return t;
}

Time Time::operator --(int) // постфіксна - модифікує second
{
	Time t(*this);
	second--;
	return t;
}

int Time::minutes() const
{
	return first * 60 + second;
}