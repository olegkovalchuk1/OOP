
#include "BitString.h"
#include <sstream>
#include <bitset>

using namespace std;

void BitString::SetHigh(long value)
{
	high = value;
}

void BitString::SetLow(long value)
{
	low = value;
}

BitString::BitString()
	: high(0), low(0)
{
}

BitString::BitString(long h, long l)
{
	SetHigh(h); SetLow(l);
}

BitString::BitString(const BitString& other)
{
	*this = other;
}

// Перевантаження присвоєння
BitString& BitString::operator =(const BitString& other)
{
	if (this != &other)
	{
		high = other.high;
		low = other.low;
	}
	return *this;
}

// Приведення до рядка
BitString::operator string() const
{
	stringstream sout;
	sout << bitset<32>(high) << " " << bitset<32>(low);
	return sout.str();
}

// Побітове НЕ (унарна - метод класу)
BitString BitString::operator ~() const
{
	return BitString(~high, ~low);
}

// Префіксний інкремент
BitString& BitString::operator ++()
{
	++low;
	return *this;
}

// Префіксний декремент
BitString& BitString::operator --()
{
	--low;
	return *this;
}

// Постфіксний інкремент
BitString BitString::operator ++(int)
{
	BitString tmp = *this;
	++high;
	return tmp;
}

// Постфіксний декремент
BitString BitString::operator --(int)
{
	BitString tmp = *this;
	--high;
	return tmp;
}

// Побітове І (бінарна - дружня функція)
BitString operator &(const BitString& a, const BitString& b)
{
	return BitString(a.high & b.high, a.low & b.low);
}

// Побітове АБО (бінарна - дружня функція)
BitString operator |(const BitString& a, const BitString& b)
{
	return BitString(a.high | b.high, a.low | b.low);
}

// Побітове виключне АБО (бінарна - дружня функція)
BitString operator ^(const BitString& a, const BitString& b)
{
	return BitString(a.high ^ b.high, a.low ^ b.low);
}

// Вивід
ostream& operator <<(ostream& out, const BitString& obj)
{
	out << string(obj);
	return out;
}

// Ввід
istream& operator >>(istream& in, BitString& obj)
{
	long h, l;
	cout << " High = "; in >> h;
	cout << " Low  = "; in >> l;
	obj.SetHigh(h);
	obj.SetLow(l);
	return in;
}