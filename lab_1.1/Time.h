
#pragma once

class Time
{
	int first, second;
public:
	int GetFirst() const { return first; }
	int GetSecond() const { return second; }
	bool SetFirst(int value);
	bool SetSecond(int value);
	bool Init(int, int);
	void Read();
	void Display() const;
	int minutes() const;
};