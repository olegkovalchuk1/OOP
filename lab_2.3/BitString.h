

#pragma once
#include <iostream>
#include <string>

using namespace std;

class BitString
{
	long high, low;
public:
	long GetHigh() const { return high; }
	long GetLow() const { return low; }
	void SetHigh(long value);
	void SetLow(long value);

	// Конструктори
	BitString();
	BitString(long h, long l);
	BitString(const BitString&);

	// Приведення типу
	operator string() const;

	// Операція присвоєння (обов'язково метод класу)
	BitString& operator =(const BitString&);

	// Унарні операції (методи класу)
	BitString operator ~() const;
	BitString& operator ++();    // Префіксний інкремент (змінює low)
	BitString& operator --();    // Префіксний декремент (змінює low)
	BitString operator ++(int);  // Постфіксний інкремент (змінює high)
	BitString operator --(int);  // Постфіксний декремент (змінює high)

	// Бінарні операції (зовнішні дружні функції)
	friend BitString operator &(const BitString& a, const BitString& b);
	friend BitString operator |(const BitString& a, const BitString& b);
	friend BitString operator ^(const BitString& a, const BitString& b);

	// Операції вводу/виводу (дружні функції)
	friend ostream& operator <<(ostream& out, const BitString& obj);
	friend istream& operator >>(istream& in, BitString& obj);
};