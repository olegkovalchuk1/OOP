
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6001)
#include <iostream>
#include <cstring>
#include "BitString.h"

using namespace std;

int main()
{
	
	BitString b1;
	b1.Read();
	b1.Display();

	
	char s[100];
	strcpy(s, b1.toString());
	cout << "Copied string: " << s << endl;

	
	BitString b2;
	cout << "Init b2 with specific values..." << endl;
	b2.Init(255, 65535); // довільні значення для демонстрації
	b2.Display();

	
	cout << "--- Bitwise Operations ---" << endl;
	BitString resNot = b1.Not();
	cout << "NOT b1: ";
	resNot.Display();

	BitString resAnd = b1.And(b2);
	cout << "b1 AND b2: ";
	resAnd.Display();

	BitString resOr = b1.Or(b2);
	cout << "b1 OR b2: ";
	resOr.Display();

	
	cout << "--- Array of objects ---" << endl;
	BitString arr[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Object " << i + 1 << ":" << endl;
		arr[i].Read();
	}
	cout << "Displaying array:" << endl;
	for (int i = 0; i < 2; i++)
	{
		arr[i].Display();
	}

	return 0;
}