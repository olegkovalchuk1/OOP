
#include "BitString.h"
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

bool BitString::SetHigh(long value)
{
	
	if (value >= -2147483648LL && value <= 4294967295LL)
	{
		high = value;
		return true;
	}
	else
	{
		high = 0;
		return false;
	}
}

bool BitString::SetLow(long value)
{
	if (value >= -2147483648LL && value <= 4294967295LL)
	{
		low = value;
		return true;
	}
	else
	{
		low = 0;
		return false;
	}
}

bool BitString::Init(long h, long l)
{
	return SetHigh(h) && SetLow(l); 
}                                   

void BitString::Read()
{
	long h, l;
	do
	{
		cout << "Input 64-bit string parts:" << endl;
		cout << " High = "; cin >> h;
		cout << " Low = "; cin >> l;
	} while (!Init(h, l));
}

void BitString::Display() const
{
	cout << endl;
	cout << toString(); 
}                       

const char* BitString::toString() const
{
	static string str; // статична змінна для безпечного зберігання рядка
	stringstream sout; // створили об'єкт літерний потік

	
	sout << bitset<32>(high) << " " << bitset<32>(low) << endl;

	str = sout.str(); 
	return str.c_str(); // перетворюємо до літерного рядка
}

BitString BitString::Not() const
{
	BitString result;
	result.Init(~high, ~low);
	return result;
}

BitString BitString::And(const BitString& other) const
{
	BitString result;
	result.Init(high & other.high, low & other.low);
	return result;
}

BitString BitString::Or(const BitString& other) const
{
	BitString result;
	result.Init(high | other.high, low | other.low);
	return result;
}