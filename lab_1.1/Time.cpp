
#include "Time.h"
#include <iostream>

using namespace std;

bool Time::SetFirst(int value)
{
	if (value >= 0)
	{
		first = value;
		return true;
	}
	else
	{
		first = 0;
		return false;
	}
}

bool Time::SetSecond(int value)
{
	if (value >= 0 && value < 60)
	{
		second = value;
		return true;
	}
	else
	{
		second = 0;
		return false;
	}
}

bool Time::Init(int x, int y)
{
	return SetFirst(x) && SetSecond(y); // повторне використання коду
}

void Time::Read()
{
	int x, y;
	do
	{
		cout << "Input time values:" << endl;
		cout << " Hours = "; cin >> x;
		cout << " Minutes = "; cin >> y;
	} while (!Init(x, y));
}

void Time::Display() const
{
	cout << endl;
	cout << "Time: " << first << " h " << second << " m" << endl;
}

int Time::minutes() const
{
	return first * 60 + second;
}